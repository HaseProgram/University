<h2>
  <a href="/group/show/">
    <span class="glyphicon glyphicon-circle-arrow-left" aria-hidden="true"></span>
    Назад
  </a>
</h2>
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
    <div class="block-footer">
      <span class="min">Min: <?=$rat[$groupname]["min"]?></span>
      <span class="avg">Average: <?=round($rat[$groupname]["avg"])?></span>
      <span class="max">Max: <?=$rat[$groupname]["max"]?></span>
    </div>
  </div>
  <div class="block">
    <div class="name"><a href="#">Настроить группу</a></div>
    <div class="block-content">
      <form id="edit-group">
        <div class="form-group">
          <label for="gname">Имя группы</label>
          <input id="gname" type="text" class="form-control" value="<?=$groupname?>" required>
          <small id="emailHelp" class="form-text text-muted">Имя должно быть уникальным!</small>
        </div>
        <button class="btn btn-primary" type="submit">Изменить</button>
      </form>
      <form id="add-stud">
        <div class="form-group">
          <label for="gstudname">Добавить студента</label>
          <input id="gstudname" type="text" class="form-control" placeholder="Иван">
          <input id="gstudsurname" type="text" class="form-control" placeholder="Иванов">
          <input id="gstudsecname" type="text" class="form-control" placeholder="Иванович">
          <input id="gstudrate" type="text" class="form-control" placeholder="Рейтинг: 0">
          <input id="gstudrole" type="text" class="form-control" placeholder="student">
        </div>
        <button class="btn btn-primary" type="submit">Добавить</button>
      </form>
      <form id="delete-group">
        <button class="btn btn-danger" type="submit">Удалить группу</button>
      </form>
    </div>
   </div>
   <script>
     $( document ).ready(function() {
         $("#edit-group").submit(function() {
           var gname = $('#gname').val();
           var formData = {};
           formData["<?=$groupname?>"] = gname;
           $.ajax({
             url:'/group/edit?action=edit',
             type:'POST',
             data:'EDIT_DATA=' + $.toJSON(formData),
             success: function(res) {
                 $(".content").html(res);
             }
           });
           return false;
         });

         $("#add-stud").submit(function() {
           var stname = $('#gstudname').val();
           var stsurname = $('#gstudsurname').val();
           var stsecname = $('#gstudsecname').val();
           var strate = $('#gstudrate').val();
           var strole = $('#gstudrole').val();
           var formData = {};
           formData["<?=$groupname?>"] = {};
           formData["<?=$groupname?>"]["Name"] = stname;
           formData["<?=$groupname?>"]["Surname"] = stsurname;
           formData["<?=$groupname?>"]["SecondName"] = stsecname;
           formData["<?=$groupname?>"]["Rating"] = strate;
           formData["<?=$groupname?>"]["Role"] = strole;
           formData["<?=$groupname?>"]["Group"] = "<?=$groupname?>";
           $.ajax({
             url:'/student/edit?action=add',
             type:'POST',
             data:'EDIT_DATA=' + $.toJSON(formData),
             success: function(res) {
                 $(".content").html(res);
             }
           });
           return false;
         });

         $("#delete-group").submit(function() {
           var formData = {};
           formData["DELETE"] = "<?=$groupname?>";
           $.ajax({
             url:'/group/edit?action=delete',
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
<?php
  }
 ?>
