<?php
  class Settings
  {

    private $setting;

    public function __construct($data)
    {
      if(!isset($_COOKIE["settings"]))
      {
        $this->settings = "fff";
      }
      else
      {
        $this->settings = $_COOKIE["settings"];
      }
      echo "<script>console.log('Settings module was loaded successful')</script>";
    }

    public function Execute($data)
    {
      if(!isset($data['set']))
      {
        throw new Exception("Wrong module parameters!");
      }
      setcookie("settings", $data['set'], time()+3600, '/', 'localhost');
      //var_dump($_COOKIE);
    }

    public function View($tmp1, $tmp2)
    {
      $res = array();
      $res['main'] = "<style>body{background: #$this->settings;}</style><input type='text' id='set-inp' value='$this->settings'><br><a id='set-bg' class='btn btn-success'>Задать новый фон</a><br><script>$('#set-bg').click(function(){window.location.href='/index/module?module=settings&set='+$('#set-inp').val()})</script>";
      return $res;
    }


  }
?>
