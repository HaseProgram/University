<?php

class Memory
{
  public function __construct()
  {
    if(!isset($_SESSION['UNDO']))
    {
      $_SESSION['UNDO'] = $_SESSION['REDO'] = array();
    }
  }

  public function NewAction($action, $controller)
  {
    array_push($_SESSION['UNDO'], array($action => $controller));
    $_SESSION['REDO'] = array();
  }

  public function Undo($arr)
  {
    $action = array_pop($_SESSION['UNDO']);
    if($action == NULL)
    {
      throw new Exception("Trying undo empty action");
    }

    array_push($_SESSION['REDO'], $action);

    $controller = current($action)->Get(key($action));
    $controller->SetArray($arr);
    return $controller->Execute();
  }

  public function Redo($arr)
  {
    $action = array_pop($_SESSION['REDO']);
    if($action == NULL)
    {
      throw new Exception("Trying undo empty action");
    }

    array_push($_SESSION['UNDO'], $action);

    $controller = current($action)->GetContra(key($action));
    $controller->SetArray($arr);
    return $controller->Execute();
  }
}

 ?>
