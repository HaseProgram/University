<?php

require_once "registry.php";

class Memory
{
  public function __construct()
  {
    if(!isset($_SESSION['UNDO']))
    {
      $_SESSION['UNDO'] = $_SESSION['REDO'] = array();
    }
  }

  public function NewAction($action, $commands)
  {
    array_push($_SESSION['UNDO'], array($action => $commands));
    $_SESSION['REDO'] = array();
  }

  public function Undo($arr)
  {
    $action = array_pop($_SESSION['UNDO']);
    if($action == NULL)
    {
      throw new Exception("Trying undo empty action");
    }

    $controller = current($action)->GetContra(key($action));
    $controller->SetArray($arr);


    array_push($_SESSION['REDO'], $action);
    return $controller->Execute();
  }

  public function Redo($arr)
  {
    $action = array_pop($_SESSION['REDO']);
    if($action == NULL)
    {
      throw new Exception("Trying redo empty action");
    }

    $controller = current($action)->Get(key($action));
    $controller->SetArray($arr);

    array_push($_SESSION['UNDO'], $action);
    return $controller->Execute();
  }
}

 ?>
