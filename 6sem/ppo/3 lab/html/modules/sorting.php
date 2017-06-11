<?php
  class Sorting
  {
    private $arr;

    public function __construct($arr)
    {
      $this->arr = $arr;
      echo "<script>console.log('Sorting module was loaded successful')</script>";
    }

    public function Execute($data)
    {
      //var_dump($this->arr); die();
      if(!isset($data['group']) || !isset($this->arr[$data['group']]))
      {
        throw new Exception("Wrong module parameters!");
      }

      for($i = 0; $i < count($this->arr[$data['group']]); $i++)
      {
        for($j = $i; $j < count($this->arr[$data['group']]); $j++)
        {
          if(strcasecmp($this->arr[$data['group']][$i]->Surname,$this->arr[$data['group']][$j]->Surname) > 0)
          {
            $dub = $this->arr[$data['group']][$i];
            $this->arr[$data['group']][$i] = $this->arr[$data['group']][$j];
            $this->arr[$data['group']][$j] = $dub;
          }
        }
      }

      echo "<center><h2>";
      foreach($this->arr[$data['group']] as $student)
      {
        echo $student->Name . " " . $student->Surname . "<br>";
      }
      echo "</h2><a href=\"/group/show\">Back to site</a></center>";
      die();
    }

    public function View($groupname, $id)
    {
      if(is_array($id)) $id = 0;
      $res = array();
      $res['group'] = "<br><a class='btn btn-success' href='/student/module?module=sorting&group=$groupname'>Сортировка по алфавиту</a><br>";
      return $res;
    }


  }
?>
