<?php

class Request
{
  private $host;
  private $controller = "index";
  private $action = "main";
  private $args = array();

  public function __construct()
  {
    $this->host = $_SERVER['REQUEST_URI'];;
    $this->Parse();
  }

  private function Parse()
  {
    $routes = explode('/', $this->host);

    if (!empty($routes[1]))
    {
      $this->controller = strtolower($routes[1]);
    }

    if (!empty($routes[2]) && $routes[2] != '')
    {
      $routes = explode('?', $routes[2]);
      $this->action = strtolower($routes[0]);
      if (!empty($routes[1]) && $routes[1] != '')
      {
        $this->args = explode('&', $routes[1]);
      }

    }

  }

  public function Controller()
  {
    return $this->controller;
  }

  public function Action()
  {
    return $this->action;
  }

  public function Args()
  {
    return $this->args;
  }

}

 ?>
