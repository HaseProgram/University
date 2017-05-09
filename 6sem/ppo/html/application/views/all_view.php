<?php
  foreach ($data as $groupname => $group)
  {
?>
  <div class="block">
    <div class="block-name"><?=$groupname?></div>
      <div class="block-content">
        <ul>
    <?php
      foreach($group as $student)
      {
    ?>
          <li><?=$student->Name?> <?=$student->Surname?></li>
    <?php
      }
    ?>
      </ul>
    </div>
  </div>
<?php
  }
 ?>
