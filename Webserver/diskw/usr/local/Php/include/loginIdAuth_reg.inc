<?
$id_for_auth = $id;
$passwd_for_auth = $passwd;

if(!(isset($id_for_auth) || isset($passwd_for_auth)))
{
?>
  <script language=javascript>
    alert ("��û�кϷ��ĵ�¼��Ϣ�������µ�¼������ز�����");
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
      $message = "��Ϸ���ʺŲ����ڣ�������������Ƿ����";
      break;
    case "invalid_passwd":
      $message = "Ϸ���ʺ������벻����������������Ƿ����";
      break;
    default:
      $message = "Ϸ���ʺ���������֤ʧ�ܣ�������������Ƿ����";
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
