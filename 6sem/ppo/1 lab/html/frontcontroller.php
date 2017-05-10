<?php

class FrontController
{
  private $controller;
  private $action;

  private static $instance = null;
  private function __construct() {}

  public static function GetInstance()
  {
    if (self::$instance == null)
    {
      self::$instance = new self();
    }

    return self::$instance;
  }

  public function ConnectController($controller)
  {
    $modelFile = ROOT_DIR . '/models/model.' . strtolower($controller) . '.php';
    if(file_exists($modelFile))
    {
      require_once $modelFile;
    }
    $controllerFile = ROOT_DIR . '/controllers/controller.' . strtolower($controller) . '.php';
    if(file_exists($controllerFile))
    {
      require_once $controllerFile;
      $controllerName = 'Controller' . ucfirst($controller);
      $this->controller = new $controllerName;
    }
    else
    {
      throw new Exception("404! Controller <b>$controllerFile</b> not found!");
    }
  }

  public function Call($action, $args = array())
  {
    $this->action = "Action" . ucfirst($action);
    if(method_exists($this->controller, $this->action))
    {
      $this->controller->{$this->action}($args);
    }
    else
    {
      throw new Exception("404! Method <b>$this->action</b> not found!");
    }
  }

}

?>
