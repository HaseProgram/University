<?php
require_once "registry.php";
require_once "memory.php";

class Model
{
  protected $data;
  protected $groupsArr;
  private $registry;
  protected $memory;

  protected $history;

  public function __construct()
  {
    $this->memory = new Memory();
    $this->data = json_decode(file_get_contents(ROOT_DIR . '/groups.json'));
    $this->registry = new Registry();
    if(!isset($_SESSION['GROUPS_ARR']))
    {
      $groupsArr = array();
      foreach($this->data as $student)
      {
        if(!$this->registry->Check($student->Group))
        {
          $this->registry->add($student->Group);
          $groupsArr["$student->Group"] = array();
        }
        array_push($groupsArr["$student->Group"], $student);
      }
      $_SESSION['GROUPS_ARR'] = $groupsArr;
    }

    $this->groupsArr = $_SESSION['GROUPS_ARR'];
    if(!isset($_SESSION['UNDO']))
    {
      $_SESSION['UNDO'] = $_SESSION['REDO'] = array();
    }
  }
}

?>
