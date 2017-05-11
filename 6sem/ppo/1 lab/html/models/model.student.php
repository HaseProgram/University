<?php

require_once "core/model.php";
require_once "core/registry.php";
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
    if(!array_key_exists($group, $this->groupsArr))
    {
      throw new Exception("Group not found!");
    }
    if(!array_key_exists($id, $this->groupsArr[$group]))
    {
      throw new Exception("Student not found!");
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
    $commands->Add('add', new CommandAdd($group,array($index => current($data))), new CommandDelete($group, array("delete" => $index)));
    $commands->Add('delete', new CommandDelete($group, $data));

    $this->groupsArr[key($data)] = $commands->Get($args['action'])->Execute();

    $_SESSION['GROUPS_ARR'] = $this->groupsArr;
  }

}

?>
