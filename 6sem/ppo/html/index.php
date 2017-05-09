<?php
  session_start();
  define("ROOT_DIR", __DIR__);

  require_once "request.php";
  require_once "frontcontroller.php";

  $request = new Request();
  $controller = $request->Controller();
  $action = $request->Action();

  try
  {
    $frontController = FrontController::GetInstance();
    $frontController->ConnectController($controller);
    $frontController->Call($action, $request->args());
  }
  catch (Exception $e)
  {
    $frontController = FrontController::GetInstance();
    $frontController->ConnectController("404");
    $frontController->Call("main");
  }

 ?>
