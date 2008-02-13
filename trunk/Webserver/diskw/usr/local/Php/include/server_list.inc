<?
	//load: -register = 启动时调用; -deposit = 蓄费时调用
	function server_list($gametype="",$load="")
	{
		$dbname ="memberpool";
		if(!$conn = include("connect.php"))
		{
			odbc_close_all();
			print  "<script>alert('资料库连结错误(MP)！');</script>";
			exit();
		}
		
		//已经启动的游戏（注册功能需要提取）
		if($load == "register" || $load == "deposit")
		{
			global $id;
			$sql = "select gametype from passport where id='$id'";
			$rs = odbc_exec($conn,$sql);
			$cnt = 0;
			while(odbc_fetch_row($rs))
			{
				$game_arr[$cnt] = odbc_result($rs,"gametype");
				$cnt ++;
			}

			if($gametype == "DRAGON")
			{
				if(@in_array("d80",$game_arr))
				{
					if($load == "register")
						return "对不起！您已经启动了 <font color='red'>新手服务器</font>，按规定您不能进行此操作！";
					elseif($load == "deposit")
						return "对不起！您是 <font color='red'>新手服务器</font>的玩家，按规定您不能进行此操作！";
				}
			}

		}
        
		if($gametype != "")
			$str .= " and gametype='$gametype'";

		$sql = "select svr_id,svr_name,status from gameserver where 1=1".$str." order by svr_id";
		$rs = odbc_exec($conn,$sql);

		$tab_items = array();
		$cnt = 0;
		$start_cnt = 0;
		while(odbc_fetch_row($rs))
		{
			$sid = odbc_result($rs,"svr_id");
			$sname = odbc_result($rs,"svr_name");
			$status = odbc_result($rs,"status");
			
			//初始化状态
			$disable_str = "";
			$f_color = "#000000";
			$add_str = "";
			$chk_str = "";

			if($cnt == 0)
				$chk_str = "checked";

			if($load == "register")
			{
				if(@in_array($sid,$game_arr))
				{
					$disable_str = "disabled";
					$f_color = "#555555";
					$add_str = "（已启动）";
					$start_cnt ++;
				}
				elseif($sid == "d80" && $start_cnt > 0)
				{
					$disable_str = "disabled";
					$f_color = "#555555";
					$add_str = "（限制启动）";
				}
			}
			else if($load == "deposit")
			{
				if(!@in_array($sid,$game_arr))
				{
					continue;
				}
				else
				{
					$disable_str = "";
					$f_color = "#000000";
					$add_str = "";
					$start_cnt ++;
				}
			}

			if(!$status)
			{
				$disable_str = "disabled";
				$f_color = "blue";
				$add_str = "（维护中）";
			}

			$tab_items[$cnt] = "<input type='radio' name='server' value='$sid' ".$chk_str." ".$disable_str."><font color='$f_color'>　".$sname.$add_str;
			$cnt++;
		}
		//如果都启动了
		if($load == "deposit" && $start_cnt == 0)
			return "对不起！您还没有启动 <font color='red'>任何一组服务器</font>，请您启动相关游戏再使用此功能！";	
		if($start_cnt == $cnt && $load == "register")
			return "对不起！您已经启动了 <font color='red'>所有服务器</font> ！";
		odbc_close_all();
		return $tab_items;
	}
    
	//对应服务器代码的服务器信息
	function server_detail($sid)
	{
		if($sid == "")
		{
			print  "<script>alert('非法操作产生功能操作失败，无服务器信息！');history.back();</script>";
			exit();
		}

		$dbname ="memberpool";
		if(!$conn = include("connect.php"))
		{
			odbc_close_all();
			print  "<script>alert('资料库连结错误(MP)！');</script>";
			exit();
		}

		$sql = "select svr_name,ip,status from gameserver where svr_id='$sid'";
		$rs = odbc_exec($conn,$sql);
		
		$sname = odbc_result($rs,"svr_name");
		$ip = odbc_result($rs,"ip");
		$status = odbc_result($rs,"status");

		global $id;
		$sql = "select gametype from passport where id='$id' and gametype='$sid'";
		$rs = odbc_exec($conn,$sql);
		if(odbc_fetch_row($rs))
			$isstart = 1;
		else
			$isstart = 0;
			
		$svr_arr = array("servername"=>$sname,
			         "ip"=>$ip,
				 "status" => $status,
			    "isstart" => $isstart
				 );
		odbc_close_all();
		return $svr_arr;
	}
?>