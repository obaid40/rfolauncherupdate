<?
	//load: -register = ����ʱ����; -deposit = ���ʱ����
	function server_list($gametype="",$load="")
	{
		$dbname ="memberpool";
		if(!$conn = include("connect.php"))
		{
			odbc_close_all();
			print  "<script>alert('���Ͽ��������(MP)��');</script>";
			exit();
		}
		
		//�Ѿ���������Ϸ��ע�Ṧ����Ҫ��ȡ��
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
						return "�Բ������Ѿ������� <font color='red'>���ַ�����</font>�����涨�����ܽ��д˲�����";
					elseif($load == "deposit")
						return "�Բ������� <font color='red'>���ַ�����</font>����ң����涨�����ܽ��д˲�����";
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
			
			//��ʼ��״̬
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
					$add_str = "����������";
					$start_cnt ++;
				}
				elseif($sid == "d80" && $start_cnt > 0)
				{
					$disable_str = "disabled";
					$f_color = "#555555";
					$add_str = "������������";
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
				$add_str = "��ά���У�";
			}

			$tab_items[$cnt] = "<input type='radio' name='server' value='$sid' ".$chk_str." ".$disable_str."><font color='$f_color'>��".$sname.$add_str;
			$cnt++;
		}
		//�����������
		if($load == "deposit" && $start_cnt == 0)
			return "�Բ�������û������ <font color='red'>�κ�һ�������</font>���������������Ϸ��ʹ�ô˹��ܣ�";	
		if($start_cnt == $cnt && $load == "register")
			return "�Բ������Ѿ������� <font color='red'>���з�����</font> ��";
		odbc_close_all();
		return $tab_items;
	}
    
	//��Ӧ����������ķ�������Ϣ
	function server_detail($sid)
	{
		if($sid == "")
		{
			print  "<script>alert('�Ƿ������������ܲ���ʧ�ܣ��޷�������Ϣ��');history.back();</script>";
			exit();
		}

		$dbname ="memberpool";
		if(!$conn = include("connect.php"))
		{
			odbc_close_all();
			print  "<script>alert('���Ͽ��������(MP)��');</script>";
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