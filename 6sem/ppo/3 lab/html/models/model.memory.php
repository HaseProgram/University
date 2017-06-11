<?php

require_once "core/model.php";

class ModelMemory extends Model
{

  public function __construct()
  {
    parent::__construct();
  }

  public function Undo()
  {
    $this->groupsArr = $this->memory->Undo($this->groupsArr);
    $_SESSION['GROUPS_ARR'] = $this->groupsArr;
  }

  public function Redo()
  {
    $this->groupsArr = $this->memory->Redo($this->groupsArr);
    $_SESSION['GROUPS_ARR'] = $this->groupsArr;
  }



}

?>
