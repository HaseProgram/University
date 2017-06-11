<?php

require_once "view.php";

class Controller
{

  protected $view;
  protected $model;
  protected $modules;

  public function __construct()
  {
    $this->view = new View();
  }

  protected function LoadModules($data)
  {
    $dir = "modules";
    $this->modules = new Registry();
  	if(is_dir($dir))
  	{
  		if($desk = opendir($dir))
  		{
  			while(($file = readdir($desk)) != false)
  			{
  				if(!is_dir($file))
  				{
            require_once $dir. "/" . $file;
            $modulename = str_replace(".php","",ucfirst($file));
            $obj = new $modulename($data);
            $this->modules->Add(strtolower($modulename),$obj);
  				}
  			}
  		}
  	}
  }

public function getUrl()
{
  $url = $_SERVER['HTTP_REFERER'];
  return $url;
}

  public function Location($path)
  {
    header('Location: http://localhost' . $path);
  }

  public function ActionModule($args)
  {
    if(!isset($args['module']) || !$this->modules->Check($args['module']))
    {
      throw new Exception("Undefined module request!");
    }
    $this->modules->Get($args['module'])->Execute($args);
    echo "<script>history.go(-1)</script>";
  }

}

 ?>
