<?
//Build DB connection
$dbname = "memberpool";
$conn_mpool = include("connect.php");
if (!$conn_mpool) {
  odbc_close_all();
  $messages[1] = "���ݿ����Ӵ���(MP)�I";
  include("messagebox.php");
  exit();
}

$svr_list = array();
$server2ip = array();
$server2gametype = array();

$sel_svr = "select * from gameserver";
$rs_sel_svr = odbc_exec($conn_mpool, $sel_svr);
while (odbc_fetch_row($rs_sel_svr)) {
   $svr_id = trim(odbc_result($rs_sel_svr,"svr_id"));
   $status = trim(odbc_result($rs_sel_svr,"status"));
   $svr_name = trim(odbc_result($rs_sel_svr,"svr_name"));
   $gametype = trim(odbc_result($rs_sel_svr,"gametype"));
   $ip = trim(odbc_result($rs_sel_svr,"ip"));
   
   $svr_list[$svr_id] = $svr_name;
   $svr_status[$svr_id] = $status;
   $server2ip[$svr_id] = $ip;
   $server2gametype[$svr_id] = $gametype;
}

$gametype_name = array("POOL"=>"ͨ��","DRAGON"=>"����","SGC"=>"������","CASUAL"=>"Ϸ�����ֹ�");
$gametype_folder = array("DRAGON"=>"dragonraja","SGC"=>"sgc","CASUAL"=>"casual");

$casual_game_list = array ("DDZ"=>"������");

$point_per_month = array("DRAGON"=>"300","SGC"=>"300","CASUAL"=>"300");
$pointtype_show["DRAGON"] = array("M"=>"�·���","P"=>"ʱ����");
$pointtype_show["SGC"] = array("M"=>"�·���","P"=>"ʱ����");
$pointtype_show["CASUAL"] = array("M"=>"�·���","T"=>"ʱ����");
?>