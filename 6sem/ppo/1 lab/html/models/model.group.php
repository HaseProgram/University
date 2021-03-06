<?php

require_once "core/model.php";
require_once "inc/edit.php";

class ModelGroup extends Model
{

  public function __construct()
  {
    parent::__construct();
  }

  public function StudNumber($groupID)
  {
    if(is_array($this->groupsArr[$groupID]))
    {
      return count($this->groupsArr[$groupID]);
    }
    return 0;
  }

  public function Rating($groupID)
  {
    $rating = array();
    $rating["min"] = 101;
    $rating["max"] = -1;
    $rating["avg"] = 0;
    $count = count($this->groupsArr[$groupID]);
    if($count == 0)
    {
      return array("min" => 0, "max" => 0, "avg" => 0);
    }
    if(is_array($this->groupsArr[$groupID]))
    {
      foreach($this->groupsArr[$groupID] as $student)
      {
        if($student->Rating > $rating["max"]) $rating["max"] = $student->Rating;
        if($student->Rating < $rating["min"]) $rating["min"] = $student->Rating;
        $rating["avg"] += $student->Rating;
      }
      $rating["avg"] /= $count;
    }
    return $rating;
  }

  public function GetGroups($args = null)
  {
    $_SESSION['GROUPS_ARR'] = $this->groupsArr;
    if(is_array($args) && isset($args['group']))
    {
      if(!@array_key_exists($args['group'], $this->groupsArr))
      {
        return array();
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
    $commands->Add('add', new CommandAdd(null, null, $data), new CommandDelete(null, null, array("DELETE" => key($data))));
    $commands->Add('edit', new CommandEdit(null, null, $data), new CommandEdit(null, null, @array_flip((array)$data)));
    $commands->Add('delete', new CommandDelete(null, null, $data), new CommandAdd(null, null, $this->GetGroups(array("group" => current($data)))));

    $this->groupsArr = $commands->Get($args['action'])->SetArray($this->groupsArr);
    $this->groupsArr = $commands->Get($args['action'])->Execute();
    $this->memory->NewAction($args['action'], $commands);
    $_SESSION['GROUPS_ARR'] = $this->groupsArr;
  }

}

?>
