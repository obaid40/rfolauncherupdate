<?
$id_for_auth = $id;
$passwd_for_auth = $passwd;

if(!(isset($id_for_auth) || isset($passwd_for_auth)))
{
?>
  <script language=javascript>
    alert ("您没有合法的登录信息，请重新登录后做相关操作！");
    window.location.href="https://member.funtown.com.cn/agzmember/account";
  </script>
<?
  exit();
}


$auth = "fail";
$url = "http://172.16.21.64:11280/loginIdAuth.php?id=$id_for_auth&passwd=$passwd_for_auth";

$fd = fopen($url,"r");
if ($fd){    $auth = fread($fd,4096);   }
fclose($fd);

if (!eregi("success",$auth)){
  switch ($auth) {
    case "invalid_login_id":
      $message = "此戏谷帐号不存在，请检查你的输入是否错误！";
      break;
    case "invalid_passwd":
      $message = "戏谷帐号与密码不符，请检查你的输入是否错误！";
      break;
    default:
      $message = "戏谷帐号与密码认证失败，请检查你的输入是否错误！";
      break;
  }
  ?>
  <script language=javascript>
    alert ("<?print $message ?>");
    history.back();
  </script>
  <?
  exit();
}
?>
