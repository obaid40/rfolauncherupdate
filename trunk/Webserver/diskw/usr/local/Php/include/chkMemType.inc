<?
  $id_for_auth = $id;
  $auth = "fail";

  $url = "http://172.16.21.64:11280/chkMemType.php?id=$id_for_auth";
  $fd = fopen($url,"r");
  if ($fd){    $return_auth = fread($fd,4096);   }
  fclose($fd);

  $auth = explode(":",$return_auth);
  if (!eregi("success",$return_auth)){
    ?>
    <script>
      alert("会员型态不明，不得使用此功能！\n若有其它任何问题请与宏碁戏谷客服人员联络！");
      history.go(-1);
    </script>
    <?
    exit();
  }else if(strtoupper($auth[1]) == "F"){
    ?>
    <script>
      alert("您为体验会员，不得使用此功能，请先转为正式会员，谢谢！");
      document.location = "https://member.funtown.com.cn/agzmember/info/memTypeChange.html";
    </script>
    <?
    exit();
  }
?>