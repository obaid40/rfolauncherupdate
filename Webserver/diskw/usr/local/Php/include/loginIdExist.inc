<?
$dbname = "memberpool";
$conn_tmp = include("connect.php");
if (!$conn_tmp) {
  odbc_close_all();
  print "<script>alert('���Ͽ��������(M)��');</script>";
  exit();
}

$sql = "select id from gametab where id = '$id'";
$rs = odbc_exec($conn_tmp,$sql);
if(odbc_fetch_row($rs))
	return true;
else
	return false;
odbc_close($conn_tmp);
?>