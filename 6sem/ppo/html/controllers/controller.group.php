<?php
require_once "core/controller.php";

class ControllerGroup extends Controller
{
  public function __construct()
  {
    parent::__construct();
    $this->model = new ModelGroup();
  }

  public function ActionShow()
  {
    $replace = array(
      'title' => "All groups!",
      'data' => $this->model->GetGroups()
    );
    $this->view->Render("all_view.php", 'main_view.php', $replace);
  }

  public function ActionEdit($args)
  {
    var_dump($args);
  }

}

?>
