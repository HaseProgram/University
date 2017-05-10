<?php

class Registry
{
  private $registry;

  public function __construct() {}

  public function Add($name, $type = true)
  {
    $this->registry[$name] = $type;
  }

  public function Check($name)
  {
    if(isset($this->registry[$name]))
    {
      return $this->registry[$name];
    }
    return false;
  }

  public function Get($name)
  {
    $res = $this->Check($name);
    if(!$res)
    {
      throw new Exception("Trying to access to non-registered object!");
    }
    return $res;
  }
}

 ?>
