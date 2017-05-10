<?php
require_once "core/controller.php";

class ControllerStudent extends Controller
{
  public function __construct()
  {
    parent::__construct();
    $this->model = new ModelStudent();
  }

  public function ActionShow($args)
  {
    if(!isset($args['id']))
    {
      throw new Exception("Missing student ID");
    }
    $replace = array(
      'title' => "Student card!",
      'data' => $this->model->GetStudent($args['id'])
    );
    $this->view->Render("stud_view.php", 'main_view.php', $replace);
  }

  public function ActionEdit($args)
  {
    if(!isset($args['id']))
    {
      throw new Exception("Missing student ID");
    }
    $this->model->Edit($args['id']);
    $this->Location("group/show");
  }

}

?>
