<?php
require_once "core/controller.php";

class ControllerIndex extends Controller
{
  public function __construct()
  {
    $this->LoadModules(null);
    parent::__construct();
  }

}

?>
