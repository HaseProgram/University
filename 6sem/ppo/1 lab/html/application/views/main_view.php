<?php
$ajax = (isset($_SERVER['HTTP_X_REQUESTED_WITH']) && !empty($_SERVER['HTTP_X_REQUESTED_WITH']) && strtolower($_SERVER['HTTP_X_REQUESTED_WITH']) == 'xmlhttprequest');
if(!$ajax)
{
?>
<!DOCTYPE html>
<html>
  <head>
    <title><?=$title?></title>
    <link rel="stylesheet" href="/static/bootstrap/css/bootstrap.css">
    <link rel="stylesheet" href="/static/css/base.css">
    <script src="http://code.jquery.com/jquery-latest.min.js" type="text/javascript"></script>
    <script src="/static/bootstrap/js/json.js" type="text/javascript"></script>
  </head>
  <body>
    <div class="content">
      <?php include 'application/views/' . $content ?>
    </div>
    <script src="/static/bootstrap/js/bootstrap.min.js"></script>
  </body>
</html>
<?php
}
else
{
  include 'application/views/' . $content;
}
?>
