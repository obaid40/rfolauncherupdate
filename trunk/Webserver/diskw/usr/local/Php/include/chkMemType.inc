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
      alert("��Ա��̬����������ʹ�ô˹��ܣ�\n���������κ���������곞Ϸ�ȿͷ���Ա���磡");
      history.go(-1);
    </script>
    <?
    exit();
  }else if(strtoupper($auth[1]) == "F"){
    ?>
    <script>
      alert("��Ϊ�����Ա������ʹ�ô˹��ܣ�����תΪ��ʽ��Ա��лл��");
      document.location = "https://member.funtown.com.cn/agzmember/info/memTypeChange.html";
    </script>
    <?
    exit();
  }
?>