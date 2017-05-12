<?php

function change_key($key,$new_key,&$arr)
{
    if(!array_key_exists($new_key,$arr) || $key == $new_key)
    {
        $arr[$new_key]=$arr[$key];
        unset($arr[$key]);
        return true;
    }
    return false;
}

interface CommandInterface
{
  public function Execute();
  public function SetArray($arr);
}

class CommandAdd implements CommandInterface
{
  private $arr;
  private $nav;
  private $items;
  private $replace;

  public function __construct($arr, $nav, $items, $replace = false)
  {
    $this->arr = $arr;
    $this->nav = $nav;
    $this->items = $items;
    $this->replace = $replace;
  }

  public function SetArray($arr)
  {
    $this->arr = $arr;
  }

  public function Execute()
  {
    if($this->arr == null || !is_array($this->arr))
    {
      throw new Exception("Trying to operate without setting source array!");
    }
    if($this->nav != null)
    {
      $copy = $this->arr;
      $this->arr = $this->arr[$this->nav];
    }

    foreach ($this->items as $key => $data)
    {
      if(!$this->replace && array_key_exists($key, $this->arr))
      {
        throw new Exception("Item already exists!");
      }
      //var_dump($this->arr); var_dump($key); die();
      $this->arr = (array)$this->arr;
      $this->arr[$key] = $data;
    }

    if($this->nav != null)
    {
      $copy[$this->nav] = $this->arr;
    }
    else
    {
      $copy = $this->arr;
    }

    return $copy;
  }
}

class CommandEdit implements CommandInterface
{
  private $arr;
  private $nav;
  private $items;

  public function __construct($arr, $nav, $items)
  {
    $this->arr = $arr;
    $this->nav = $nav;
    $this->items = $items;
  }

  public function SetArray($arr)
  {
    $this->arr = $arr;
  }

  public function Execute()
  {
    if($this->arr == null || !is_array($this->arr))
    {
      throw new Exception("Trying to operate without setting source array!");
    }
    if($this->nav != null)
    {
      $copy = $this->arr;
      $this->arr = $this->arr[$this->nav];
    }

    foreach ($this->items as $key => $new_key)
    {
      if(!array_key_exists($key, $this->arr))
      {
        throw new Exception("Can't edit $key: source item not found!");
      }
      foreach($this->arr[$key] as $id => $student)
      {
        $student->Group = $new_key;
      }
      if(!change_key($key, $new_key, $this->arr))
      {
        throw new Exception("Can't edit $key to $new_key. $new_key already exists!");
      }
    }

    if($this->nav != null)
    {
      $copy[$this->nav] = $this->arr;
    }
    else
    {
      $copy = $this->arr;
    }

    return $copy;
  }
}

class CommandDelete implements CommandInterface
{
  private $arr;
  private $nav;
  private $keys;

  public function __construct($arr, $nav, $keys)
  {
    $this->arr = $arr;
    $this->nav = $nav;
    $this->keys = $keys;
  }

  public function SetArray($arr)
  {
    $this->arr = $arr;
  }

  public function Execute()
  {
    if($this->arr == null || !is_array($this->arr))
    {
      throw new Exception("Trying to operate without setting source array!");
    }
    if($this->nav != null)
    {
      $copy = $this->arr;
      $this->arr = $this->arr[$this->nav];
    }


    foreach ($this->keys as $key => $delete)
    {
      if(!array_key_exists($delete, $this->arr))
      {
        throw new Exception("Can't delete $delete: source item not found!");
      }

      unset($this->arr[$delete]);
    }

    if($this->nav != null)
    {
      $copy[$this->nav] = $this->arr;
    }
    else
    {
      $copy = $this->arr;
    }

    return $copy;
  }
}



?>
