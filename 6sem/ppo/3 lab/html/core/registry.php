<?php

class Registry
{
  private $registry;

  public function __construct() {
    $this->registry = array();
  }

  public function Add($name, $type = true, $contra = false)
  {
    $this->registry[$name] = array($type, $contra);
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
    return $res[0];
  }

  public function GetContra($name)
  {
    $res = $this->Check($name);
    if(!$res)
    {
      throw new Exception("Trying to access to non-registered object!");
    }
    return $res[1];
  }

  public function GetAll()
  {
    return $this->registry;
  }
}

 ?>
