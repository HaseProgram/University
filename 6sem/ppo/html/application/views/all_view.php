  <h2>Списки групп</h2>
<?php
  foreach ($data as $groupname => $group)
  {
?>
  <div class="block">
    <div class="name"><a href="/group/show?group=<?=$groupname?>"><?=$groupname?></a></div>
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
 <?php
  if($add)
  {
  ?>
 <div class="block">
   <div class="name"><a href="#">Добавить группу</a></div>
   <div class="block-content">
     <form id="add-group">
       <div class="form-group">
         <input id="gname" type="text" class="form-control" placeholder="Название группы">
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
  <?php
    }
    else
    {
   ?>
   <div class="block">
     <div class="name"><a href="#">Настроить группу</a></div>
     <div class="block-content">
       <form id="edit-group">
         <div class="form-group">
           <label for="gname">Имя группы</label>
           <input id="gname" type="text" class="form-control" value="<?=$groupname?>">
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
       <form id="add-stud">
         <button class="btn btn-danger" type="submit">Удалить группу</button>
       </form>
     </div>
    </div>
    <script>
      $( document ).ready(function() {
          $("#edit-group").submit(function() {
            var gname = $('#gname').val();
            var formData = {};
            formData[gname] = {};
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
      });
    </script>
   <?php
    }
   ?>
