<?php
  class Export
  {
    private $arr;

    public function __construct($arr)
    {
      $this->arr = $arr;
      echo "<script>console.log('Export module was loaded successful')</script>";
    }

    public function Execute($data)
    {
      $fileName = "";
      $content = "";
      if(!isset($data['group']) || !isset($this->arr[$data['group']]))
      {
        throw new Exception("Wrong module parameters!");
      }
      if(!isset($data['id']))
      {
        $fileName = "group";

        foreach($this->arr[$data['group']] as $student)
        {
          $content .= $student->Name . " " . $student->Surname . "\n";
        }
      }
      else
      {
        $fileName = "student";
        $student = $this->arr[$data['group']][$data['id']];
        $content = "ID:" .  $data['id'] . "\nGroup: " . $data['group'] . "\nName: " . $student->Name . "\nSurname: " . $student->Surname . "\nRating: " . $student->Rating . "\nRole: $student->Role";
      }


      $exportFile = fopen(ROOT_DIR . "/" . $fileName . ".export.txt", "w");
      if(!$exportFile)
      {
        throw new Exception("Permission denied for exporting");
      }
      fwrite($exportFile, $content);
      fclose($exportFile);
    }

    public function View($groupname, $id)
    {
      if(is_array($id)) $id = 0;
      $res = array();
      $res['group'] = "<br><a class='btn btn-success' href='/group/module?module=export&group=$groupname'>Экспорт группы</a><br>";
      $res['student'] = "<br><a class='btn btn-success' href='/student/module?module=export&group=$groupname&id=$id'>Экспорт студента</a><br>";
      return $res;
    }


  }
?>
