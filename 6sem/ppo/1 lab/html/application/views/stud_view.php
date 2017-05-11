<h2>
  <a href="/group/show/">
    <span class="glyphicon glyphicon-circle-arrow-left" aria-hidden="true"></span>
    Назад
  </a>
</h2>

<div class="block">
  <div class="name">
    <?=$data->Surname?> <?=$data->Name?> <?=$data->SecondName?>
  </div>
  <div class="block-content">
    <div class="avatar">
      <img src="/static/users/<?=$src?>.jpg">
    </div>
    Рейтинг: <?=$data->Rating?> <br>
    Статус: <?=$data->Role?>
  </div>
  <form id="delete" style="margin: 20px;">
    <button class="btn btn-danger" type="submit">Удалить студента</button>
  </form>
</div>
<script>
  $( document ).ready(function() {
      $("#delete").submit(function() {
        var formData = {};
        formData["<?=$data->Group?>"] = "<?=$id?>";
        $.ajax({
          url:'/student/edit?action=delete',
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
