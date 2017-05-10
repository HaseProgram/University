<?php

function change_key($key,$new_key,$arr)
{
    if(!array_key_exists($new_key,$arr))
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
}

class CommandAdd implements CommandInterface
{
  private $arr;
  private $items;

  public function __construct($arr, $items)
  {
    $this->arr = $arr;
    $this->items = $items;
  }

  public function Execute()
  {
    foreach ($this->items as $key => $data)
    {
      if(array_key_exists($key, $this->arr))
      {
        throw new Exception("Item already exists!");
      }
      $this->arr[$key] = $data;
    }

    return $this->arr;
  }
}

class CommandEdit implements CommandInterface
{
  private $arr;
  private $items;

  public function __construct($arr, $items)
  {
    $this->arr = $arr;
    $this->items = $items;
  }

  public function Execute()
  {
    foreach ($this->items as $key => $data)
    {
      if(!array_key_exists($key, $this->arr))
      {
        throw new Exception("Can't edit $key: source item not found!");
      }
      $this->arr[$key] = $data;
    }

    return $this->arr;
  }
}

class CommandDelete implements CommandInterface
{
  private $arr;
  private $keys;

  public function __construct($arr, $keys)
  {
    $this->arr = $arr;
    $this->keys = $keys;
  }

  public function Execute()
  {
    foreach ($this->keys as $key)
    {
      if(!array_key_exists($key, $this->arr))
      {
        throw new Exception("Can't delete $key: source item not found!");
      }
      unset($this->arr[$key]);
    }

    return $this->arr;
  }
}



?>