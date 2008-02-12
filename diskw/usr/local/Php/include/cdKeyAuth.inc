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
      $message = "不合法的序号(非戏谷游戏使用之序号)\\n请检查你是否输入错误，或与客服人员联络！";
      break;
    case "invalid_status":
      $status = $auth_return[1];      
      if (strtoupper($status) == "USED_COMMON_KEY") {
        $message = "你已经使用过此序号了\\n请检查你是否输入错误，或与客服人员联络！";
      }
      else if (strtoupper($status) == "USED_KEY") {
        $message = "此序号已经被使用过了\\n请检查你是否输入错误，或与客服人员联络！";
      }
      else if (strtoupper($status) == "USED_ONCE_EVENTID") {
        $message = "本批产品序号每一位玩家只能储值一次，请参阅产品包装说明！";
      }
      else {
        $message = "此序号已经被使用过了\\n请检查你是否输入错误，或与客服人员联络！";
      }
      break;
    case "invalid_gametype":
      $message = "不合法的序号(游戏类型有误)\\n请检查你是否输入错误，或与客服人员联络！";
      break;
    case "invalid_expiredate":
      $expiredate = $auth_return[1];
      $message = "所使用的序号已经超过有效期限‘".$expiredate."’\\n请检查你是否输入错误，或与客服人员联络！";
      break;
    default:
      $message = "序号认证失败\\n请检查你是否输入错误，或与客服人员联络！";
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