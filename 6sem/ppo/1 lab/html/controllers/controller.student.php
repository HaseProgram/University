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
    if(!isset($args['id']) || !isset($args['group']))
    {
      throw new Exception("Missing student ID");
    }
    $src = "user"; // for image
    // in production we will use special ID field (not local for group)
    // like: $src = $student->GlobalID
    $replace = array(
      'title' => "Student card!",
      'data' => $this->model->GetStudent($args['group'], $args['id']),
      'src' => $src,
      'id' => $args['id']

    );
    $this->view->Render("stud_view.php", 'main_view.php', $replace);
  }

  public function ActionEdit($args)
  {
    $this->model->Edit($args);
    $this->Location("group/show");
  }

}

?>
