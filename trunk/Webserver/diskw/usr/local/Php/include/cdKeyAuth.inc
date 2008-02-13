<?
//Check if this keyno is valid
$id_for_auth = $id;
$keyno_for_auth = strtoupper($keyno);

$auth = "fail";
$url = "http://172.16.21.64:11280/keynoAuth.php?keyno_for_auth=$keyno_for_auth";
$fd = fopen($url,"r");
if ($fd){    $auth_return = fread($fd,4096);   }
fclose($fd);

//exit("in cdKey.php, auth_return= $auth_return");

$auth_return = explode(":",$auth_return);
$auth = $auth_return[0];
if ($auth == "success") {
  //success:$cryptedKey:$gametype:$func:$point:$memo:$eventid:$days:$description:$bonus_point:$bonus_desc:$item_list
  $cryptedKey = $auth_return[1];
  $gametype = $auth_return[2];
  $func = $auth_return[3];
  $point = $auth_return[4];
  $memo = $auth_return[5];
  $eventid = $auth_return[6];
  $day = $auth_return[7];
  $description = $auth_return[8];
  $bonus_point = $auth_return[9];
  $bonus_desc = $auth_return[10];
  $item_list = $auth_return[11];
}
else {
  switch ($auth_return[0]) {
    case "invalid_keyno":
      $message = "���Ϸ������(��Ϸ����Ϸʹ��֮���)\\n�������Ƿ�������󣬻���ͷ���Ա���磡";
      break;
    case "invalid_status":
      $status = $auth_return[1];      
      if (strtoupper($status) == "USED_COMMON_KEY") {
        $message = "���Ѿ�ʹ�ù��������\\n�������Ƿ�������󣬻���ͷ���Ա���磡";
      }
      else if (strtoupper($status) == "USED_KEY") {
        $message = "������Ѿ���ʹ�ù���\\n�������Ƿ�������󣬻���ͷ���Ա���磡";
      }
      else if (strtoupper($status) == "USED_ONCE_EVENTID") {
        $message = "������Ʒ���ÿһλ���ֻ�ܴ�ֵһ�Σ�����Ĳ�Ʒ��װ˵����";
      }
      else {
        $message = "������Ѿ���ʹ�ù���\\n�������Ƿ�������󣬻���ͷ���Ա���磡";
      }
      break;
    case "invalid_gametype":
      $message = "���Ϸ������(��Ϸ��������)\\n�������Ƿ�������󣬻���ͷ���Ա���磡";
      break;
    case "invalid_expiredate":
      $expiredate = $auth_return[1];
      $message = "��ʹ�õ�����Ѿ�������Ч���ޡ�".$expiredate."��\\n�������Ƿ�������󣬻���ͷ���Ա���磡";
      break;
    default:
      $message = "�����֤ʧ��\\n�������Ƿ�������󣬻���ͷ���Ա���磡";
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