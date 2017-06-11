  <h2>Списки групп</h2>
  <center>
  <?php
  if(!empty($_SESSION['UNDO'])) echo '<a href="/memory/undo/"><span class="glyphicon glyphicon-step-backward"></span> Отменить</a>&nbsp;';
  if(!empty($_SESSION['REDO'])) echo '<a href="/memory/redo/">Применить <span class="glyphicon glyphicon-step-forward"></span></a>&nbsp;';
  ?>
</center>
<?php
  foreach ($data as $groupname => $group)
  {
?>
  <div class="block">
    <div class="name">
      <a href="/group/show?group=<?=$groupname?>"><?=$groupname?></a>,
      <small><?=$nums[$groupname]?> студента(ов)</small>
    </div>
    <div class="block-content">
      <ul>
    <?php
      foreach($group as $id => $student)
      {
    ?>
        <li><a href="/student/show?group=<?=$groupname?>&id=<?=$id?>"><?=$student->Name?> <?=$student->Surname?></a></li>
    <?php
      }
    ?>
      </ul>
    </div>
  </div>
<?php
  }
 ?>

 <div class="block">
   <div class="name"><a href="#">Добавить группу</a></div>
   <div class="block-content">
     <form id="add-group">
       <div class="form-group">
         <input id="gname" type="text" class="form-control" placeholder="Название группы" required>
         <small id="emailHelp" class="form-text text-muted">Имя должно быть уникальным!</small>
       </div>
       <button class="btn btn-primary" type="submit">Добавить</button>
     </form>
   </div>
  </div>
  <script>
    $( document ).ready(function() {
        $("#add-group").submit(function() {
          var gname = $('#gname').val();
          var formData = {};
          formData[gname] = {};
          $.ajax({
            url:'/group/edit?action=add',
            type:'POST',
            data:'EDIT_DATA=' + $.toJSON(formData),
            success: function(res) {
                $(".content").html(res);
            }
          });
          return false;
        });
    });
  </script>
