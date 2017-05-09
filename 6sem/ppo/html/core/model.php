<?php

class Model
{
  protected $data;

  public function __construct()
  {
    $this->data = json_decode(file_get_contents(ROOT_DIR . '/groups.json'));
  }
}

?>
