<?php

require_once "core/model.php";
require_once "core/registry.php";
require_once "inc/edit.php";

class ModelGroup extends Model
{

  private $groups;
  private $groupsArr;

  public function __construct()
  {
    parent::__construct();
    $this->groups = new Registry();
    $this->init();
  }

  private function init()
  {
    if(!isset($_SESSION['GROUPS_ARR']))
    {
      $groupsArr = array();
      foreach($this->data as $student)
      {
        if(!$this->groups->Check($student->Group))
        {
          $this->groups->add($student->Group);
          $groupsArr["$student->Group"] = array();
        }
        array_push($groupsArr["$student->Group"], $student);
      }
      $_SESSION['GROUPS_ARR'] = $groupsArr;
    }
    $this->groupsArr = $_SESSION['GROUPS_ARR'];
  }

  public function GetGroups($args = null)
  {
    $_SESSION['GROUPS_ARR'] = $this->groupsArr;
    if(is_array($args) && isset($args['group']))
    {
      if(!array_key_exists($args['group'], $this->groupsArr))
      {
        throw new Exception("Group not found!");
      }
      return array($args['group'] => $this->groupsArr[$args['group']]);
    }
    return $this->groupsArr;
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

    $commands = new Registry();
    $commands->Add('add', new CommandAdd($this->groupsArr, $data));
    $commands->Add('edit', new CommandEdit($this->groupsArr, $data));
    $commands->Add('delete', new CommandDelete($this->groupsArr, $data));

    $this->groupsArr = $commands->Get($args['action'])->Execute();
    $_SESSION['GROUPS_ARR'] = $this->groupsArr;
  }

}

?>
