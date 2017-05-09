<?php

require_once "core/model.php";
require_once "core/registry.php";

class ModelGroup extends Model
{

  private $groups;

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
  }

  public function GetGroups()
  {
    return $_SESSION['GROUPS_ARR'];
  }
}

?>
