<?php

require_once "core/model.php";
require_once "inc/edit.php";

class ModelStudent extends Model
{

  public function __construct()
  {
    parent::__construct();
  }

  public function GetStudent($group, $id)
  {
    $_SESSION['GROUPS_ARR'] = $this->groupsArr;
    if(!@array_key_exists($group, $this->groupsArr))
    {
      return array();
    }
    if(!@array_key_exists($id, $this->groupsArr[$group]))
    {
      return array();
    }
    return $this->groupsArr[$group][$id];
  }

  public function Edit($args = null)
  {
    if(!is_array($args) || !isset($args['action']))
    {
      throw new Exception("Wrong parameters!");
    }

    $data = array();
    if(isset($_POST['EDIT_DATA']))
    {
      $data = json_decode($_POST['EDIT_DATA']);
    }

    $group = $this->groupsArr[key($data)];
    end($group);
    $index = count($group) + 1;

    $commands = new Registry();
    $commands->Add('add', new CommandAdd(null, key($data), array($index => current($data)), true), new CommandDelete(null, key($data), array("delete" => $index)));
    $commands->Add('delete', new CommandDelete(null, key($data), $data), new CommandAdd(null, key($data), array(current($data) => $this->GetStudent(key($data), current($data))), true));

    $this->groupsArr = $commands->Get($args['action'])->SetArray($this->groupsArr);
    $this->groupsArr = $commands->Get($args['action'])->Execute();
    $this->memory->NewAction($args['action'], $commands);
    $_SESSION['GROUPS_ARR'] = $this->groupsArr;
  }

}

?>
