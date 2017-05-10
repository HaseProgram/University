<?php
require_once "core/controller.php";

class ControllerError extends Controller
{
  public function __constriuct()
  {
    parent::__construct();
  }

  public function ActionMain($error)
  {
    $replace = array('title' => "Error!", 'error' => $error);
    $this->view->Render("error_view.php", 'main_view.php', $replace);
  }

}

?>
