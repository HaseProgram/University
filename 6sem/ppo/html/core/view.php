<?php

class View
{

  public function __construct() {}

  public function Render($content, $template, $data = null)
  {
    if(is_array($data))
    {
      extract($data);
    }
    include 'application/views/' . $template;
  }

}

?>
