<?php
require_once "core/controller.php";

class ControllerGroup extends Controller
{
  public function __construct()
  {
    parent::__construct();
    $this->model = new ModelGroup();
  }

  public function ActionShow($args)
  {
    $groups = $this->model->GetGroups($args);
    $studNum = array();
    $rating = array();
    foreach($groups as $group => $students)
    {
      $studNum[$group] = $this->model->StudNumber($group);
      $rating[$group] = $this->model->Rating($group);
    }
    $replace = array(
      'title' => "All groups!",
      'data' => $groups,
      'nums' => $studNum,
      'rat' => $rating
    );
    if(!isset($args['group']))
    {
      $this->view->Render("all_view.php", 'main_view.php', $replace);
    }
    else
    {
      $this->view->Render("one_view.php", 'main_view.php', $replace);
    }
  }

  public function ActionEdit($args)
  {
    $this->model->Edit($args);
    $this->Location("group/show");
  }

}

?>
