<?php
require_once "core/controller.php";

class ControllerMemory extends Controller
{
  public function __construct()
  {
    $this->model = new ModelMemory();
    $data = $this->model->GetData();
    $this->LoadModules($data);
    parent::__construct();
  }

  public function ActionUndo()
  {
    $this->model->Undo();
    $this->Location("/group/show");
  }

  public function ActionRedo()
  {
    $this->model->Redo();
    $this->Location("/group/show");
  }

}

?>
