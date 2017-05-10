<?php
require_once "core/controller.php";
require_once "core/registry.php";

class ControllerGroup extends Controller
{
  public function __construct()
  {
    parent::__construct();
    $this->model = new ModelGroup();
  }

  public function ActionShow($args)
  {
    $replace = array(
      'title' => "All groups!",
      'data' => $this->model->GetGroups($args),
      'add' => !isset($args['group'])
    );
    $this->view->Render("all_view.php", 'main_view.php', $replace);
  }

  public function ActionEdit($args)
  {
    $replace = array(
      'title' => "All groups!",
      'data' => $this->model->Edit($args)
    );
    $this->Location("group/show");
  }

}

?>
