<?php

require_once "view.php";

class Controller
{

  protected $view;
  protected $model;

  public function __construct()
  {
    $this->view = new View();
  }

}

 ?>
