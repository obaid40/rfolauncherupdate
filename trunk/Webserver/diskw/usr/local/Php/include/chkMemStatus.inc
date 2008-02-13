<?
  $id_for_auth = $id;
  $auth = "fail";

  $url = "http://172.16.21.64:11280/chkMemStatus.php?id=$id_for_auth";
  $fd = fopen($url,"r");
  if ($fd){    $auth = fread($fd,4096);   }
  fclose($fd);

  if (!eregi("success",$auth)){
    ?>
    <script>
      alert("此帐号停权中，不得使用此功能！\n若有其它任何问题请与宏碁戏谷客服人员联络！");
      history.go(-1);
    </script>
    <?
    exit();
  }
?>