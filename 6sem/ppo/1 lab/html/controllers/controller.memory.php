<?php
require_once "core/controller.php";

class ControllerMemory extends Controller
{
  public function __construct()
  {
    parent::__construct();
    $this->model = new ModelMemory();
  }

  public function ActionUndo()
  {
    $this->model->Undo();
    $this->Location("group/show");
  }

  public function ActionRedo()
  {
    $this->model->Redo();
    $this->Location("group/show");
  }

}

?>
