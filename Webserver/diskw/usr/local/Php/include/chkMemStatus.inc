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
      alert("���ʺ�ͣȨ�У�����ʹ�ô˹��ܣ�\n���������κ���������곞Ϸ�ȿͷ���Ա���磡");
      history.go(-1);
    </script>
    <?
    exit();
  }
?>