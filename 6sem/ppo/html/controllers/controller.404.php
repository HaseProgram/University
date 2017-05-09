<?php
require_once "core/controller.php";

class Controller404 extends Controller
{
  public function __constriuct()
  {
    parent::__construct();
  }

  public function ActionMain()
  {
    $title = array('title' => "Error 404!");
    $this->view->Render("404_view.php", 'main_view.php', $title);
  }

}

?>
