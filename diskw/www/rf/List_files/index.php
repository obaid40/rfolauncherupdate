<html><head>
<style type="text/css">
<!--
body {
	background-color: #000000;
}
-->
</style>
<meta http-equiv="REFRESH" content="20">
<script language="javascript">
<!--
function menu()
{
	if(document.getElementById)
	{
		document.getElementById("menu").style.visibility = 'visible';
		document.getElementById("menu").style.top = event.clientY + document.body.scrollTop;
		document.getElementById("menu").style.left = event.clientX + document.body.scrollLeft;
	}
	else if(document.all)
	{
		document.all["menu"].style.visibility = 'visible';
		document.all["menu"].style.top = event.clientY + document.body.scrollTop;
		document.all["menu"].style.left = event.clientX + document.body.scrollLeft;
	}
return(false);
}

function finish()
{
	if(document.getElementById)
	{
		document.getElementById("menu").style.visibility = 'hidden';
	}
	else if(document.all)
	{
		document.all["menu"].style.visibility = 'hidden';
	}
}
document.oncontextmenu=menu;
document.onmouseup=finish;
-->
</script>
<meta http-equiv="Content-Type" content="text/html; charset=iso-8859-1"></head>
<body topmargin="0" leftmargin="0" bottommargin="0" rightmargin="0" scroll="no" text="#a0a0a0" style="background-color: #A0A0A0">
<div id="menu" style="position: absolute; visibility: hidden;"></div>
<table border="0" cellpadding="0" cellspacing="0" height="285" width="305">
  <tbody><tr>
    <td align="left" background="index_data/index_fond.jpg" valign="top"><table border="0" cellpadding="0" cellspacing="0" height="285" width="305">
        <tbody><tr>
          <td align="left" valign="top"><table border="0" cellpadding="0" cellspacing="0" width="305">
            <tbody><tr>
              <td><table border="0" cellpadding="0" cellspacing="0" width="305">
                <tbody><tr>
				  <td align="left" valign="middle"><div align="left">

                                  <a href="http://127.0.0.1/" target="_blank"><img src="index_data/site_web.jpg" onmouseover="this.src='site_web_hover.jpg'" onmouseout="this.src='site_web.jpg'" border="0"></a>&nbsp;
                                  
                                  <a href="http://http://www.gamehaze.com/forum/f352/" target="_blank"><img src="index_data/forum.jpg" onmouseover="this.src='forum_hover.jpg'" onmouseout="this.src='forum.jpg'" border="0"></a>&nbsp;

                                  <a href="http://127.0.0.1/register.php"><img src="index_data/register.jpg" onmouseover="this.src='register_hover.jpg'" onmouseout="this.src='register.jpg'" border="0"></a>&nbsp;

                                  <a href="http://127.0.0.1/rfweb/downloads_patcher.htm"><img src="index_data/patches.jpg" onmouseover="this.src='patches_hover.jpg'" onmouseout="this.src='patches.jpg'" border="0"></a>

                                  </div></td>
                  </tr>
              </tbody></table>
                </td>
            </tr>
            <!-- Online Status -->
            <tr><td>
<?
$TotalConnecte = Lire_La_Ligne_n("D:\RFxG4Server\SystemSave\ServerDisplay.ini" , "15"); 
$LTotalConnecte = substr($TotalConnecte,8,15);
		//Server Status Check Kurayami Corp.
		$serverip = "127.0.0.1";

		echo "<body bgcolor=#000000><b><font size=-1 color=#7b7b7b>";
		echo "Login: " . statuscheck($serverip, "10001");
		echo "&nbsp&nbsp&nbsp Server: " . statuscheck($serverip, "27780");
                echo "</size>";   
                echo "</size>";

?>
            </td></tr>
            <tr>
              <td><table border="0" cellpadding="0" cellspacing="0" width="305">
                <tbody><tr>
                  <td align="left" valign="top" width="200"><div align="left">
                      </style></head><style type="text/css">
<!--
td ,a{
	color: #FFFFFF;
	font-size: 9pt;
	line-height: 18pt;
	text-decoration: none;
	}
a:hover{
	color: #ffffff;
}	
-->
</style></head><body leftmargin="0" topmargin="0" bgcolor="#FFFFFF" marginheight="0" marginwidth="0" style="background-color: #A0A0A0">
<table border="0" cellpadding="3" cellspacing="0" width="315">
  <tbody><tr><td valign="top" width="309">
<br>[02/07/08] Rev2 update released.</a>
<br>[02/06/08] Rev1 update released.</a>
<br>[02/01/08] Guide released for Repack.</a>
<br>[01/31/08] Initial Release of the Kaswynn Repack!</a>
<br>

<br>
      </td>
  </tr>
</tbody></table><br>
                          </p>
                    </div></td>
                  </tr>
              </tbody></table></td>
            </tr>
          </tbody></table>            </td>
        </tr>
    </tbody></table>
    </td>
  </tr>
</tbody></table>
</body></html>

<?
function statuscheck($serverip, $port) {
	$sockres = @fsockopen($serverip, $port, $errno, $errstr, 1);
	if (!$sockres) {
		return "<font color=red>OFFLINE</font>";
	} else {
		@fclose($sockres);
		return "<font color=lightgreen>ONLINE</font>";
	}
}

function Lire_La_Ligne_n($fichier, $ligne) 
{ 
    if (file_exists("$fichier")) 
    { 
        if($id = fopen("$fichier", "r+")) 
            { 
            while(!feof($id)) 
            { 
                $result[]= fgets($id,1000000); 
            } 
            fclose($id); 
            $tab=$result; 
            $result=$tab[$ligne-1]; 
            return $result; 
        } 
        else 
        { 
            return pb_ouv; 
        } 
    } 
    else 
    { 
        return no_file; 
    } 
} 
?>