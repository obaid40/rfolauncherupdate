<head>
<style type="text/css">
<!--
body {
	background-color: #1F1F1F;
}
body,td,th {
	color: #CCCCCC;
}
.Style1 {color: #CCCCCC}
.Style2 {color: #CCCCCC}
.Style4 {color: #CCCCCC; font-weight: bold; }
.Style6 {
	color: #CCCCCC;
	font-size: 24px;
	font-weight: bold;
}
-->
</style>
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
</head>
<DIV ID="menu" STYLE="position:absolute;visibility:hidden"></div>
<?php
/*======================================================================*\
|| #################################################################### ||
|| # Registration for RF online private server                          || 
|| # ---------------------------------------------------------------- # ||
|| # Copyright ©2006 ShibA. All Rights Reserved.                      ||
|| #################################################################### ||
\*======================================================================*/

include 'rf_config.php';

$tabelka = '<form action=register.php method=post><body topmargin="0" leftmargin="0" bottommargin="0" rightmargin="0" scroll="no" bgcolor="#1f1f1f" text="#a0a0a0">
	<table width="305" border="0" background="ins_fond.jpg">
        <tr>
          <td width="277"><span class="Style4">Login : </span></td>
        </tr>
        <tr>
          <td height="35" valign="top"><input type=text name=login value="'.$_POST['login'].'"></td>
        </tr>
        <tr>
          <td><span class="Style4">Password : </span></td>
        </tr>
        <tr>
          <td height="35" valign="top"><input type=password name=pass></td>
        </tr>
        <tr>
          <td><span class="Style4">Password ( repeat ) : </span></td>
        </tr>
        <tr>
          <td height="35" valign="top"><input type=password name=cpass></td>
        </tr>
        <tr>
          <td><span class="Style4">Email : </span></td>
        </tr>
        <tr>
          <td height="35" valign="top"><input type=text name=mail value="'.$_POST['mail'].'"></td>
        </tr>
        <tr>
          <td height="41" valign="top">
            <div align="left">
              <INPUT type="image" value="Valider" src="valider.jpg">
			  <a href="http://127.0.0.1/rfweb/list.htm"><img src="retour.jpg" border="0"></a>
            </div></td>
        </tr>
      </table>
</form>
<form name="retour" action="http://127.0.0.1/rfweb/list.htm">
	
</form>';

if($reg_open AND isset($_POST['login']))
{


$conn=mssql_connect($host,$sql_user,$sql_pwd) or die("<center><b>Critical Error</b><br>Impossible to connect to the database<br><br><a href=register.php><img src=retour.jpg border=0></a></center>");

@mssql_select_db($base, $conn) or die("<center><b>Critical Error</b><br>Database don't exists OR I can't Access to it !<br><br><a href=register.php><img src=retour.jpg border=0></a></center>");


$login = $_POST['login'];
$pw = $_POST['pass'];
$cpw = $_POST['cpass'];
$email = $_POST['mail'];

$login = trim($login);
$pw = trim($pw);
$cpw = trim($cpw);

if(ereg("[^0-9a-zA-Z_-]", $login, $str))
	{
	echo '<body background="ins_fond.jpg"><center>Login not in good format.';
	echo '<br><br><a href="register.php"><img src="retour.jpg" border="0"></a></center></body>';
	}
elseif(ereg("[^0-9a-zA-Z_-]", $pw, $str))
	{
	echo '<body background="ins_fond.jpg"><center>Password not in good format.';
	echo '<br><br><a href="register.php"><img src="retour.jpg" border="0"></a></center></body>';
	}
elseif (empty($login) || empty($email) || empty($pw) || empty($cpw)) 
	{
	echo '<body background="ins_fond.jpg"><center>Fill in the empty fields. <br><br><a href="register.php"><img src="retour.jpg" border="0"></a></center></body>';
	}
elseif (strpos('\'',$email)) 
	{
	echo '<body background="ins_fond.jpg"><center>This '.$email.' is not a good mail adress.<br><br><a href="register.php"><img src="retour.jpg" border="0"></a></center></body>';
	}
else
	{
	$login_test = strtolower($login);
	$resultx = mssql_query("SELECT (UserId) FROM x2o_user WHERE (UserId) = ('$login_test')") or die;

	if (mssql_num_rows($resultx)) 
		{
		echo '<body background="ins_fond.jpg"><center>The account '.$login.' already exists.<br><br><a href="register.php"><img src="retour.jpg" border="0"></center></body>';
		}
	elseif (strlen($login) < 4) 
		{
		echo '<body background="ins_fond.jpg"><center>Login must have more than 4 characters.<br><br><a href="register.php"><img src="retour.jpg" border="0"></center></body>';
		}
	elseif (strlen($pw) < 4) 
		{
		echo '<body background="ins_fond.jpg"><center>Password must have more than 4 characters.<br><br><a href="register.php"><img src="retour.jpg" border="0"></center></body>';
		}
	elseif (strlen($pw) > 10) 
		{
		echo '<body background="ins_fond.jpg"><center>Password must have less than 10 characters.<br><br><a href="register.php"><img src="retour.jpg" border="0"></center></body>';
		} 
	elseif (strlen($login) > 10) 
		{
		echo '<body background="ins_fond.jpg"><center>Login must have less than 10 characters.<br><br><a href="register.php"><img src="retour.jpg" border="0"></center></body>';
		} 
	elseif ($pw != $cpw) 
		{
		echo '<body background="ins_fond.jpg"><center>Passwords mismatch.<br><br><a href="register.php"><img src="retour.jpg" border="0"></center></body>';
		}
	else 
		{
		mssql_query("INSERT INTO exgame.dbo.x2o_user (UserId,Password,UserName,email) VALUES ((CONVERT (binary(12),'$login')),(CONVERT (binary(12),'$pw')),'$login','$email')");
		mssql_query("INSERT INTO rfweb.dbo.userlogin (userid,password) VALUES ('$login','$pw')");
		mssql_query("INSERT INTO exgame.dbo.account_sound_team (id) VALUES ('".$login."')")or die('<center>error, account exists<br><br><a href=register.php><img src=retour.jpg border=0></center>');

                echo '<body background="ins_fond.jpg"><center>Account has been created.<br><br><a href=http://127.0.0.1/rfweb/list.htm><img src=retour.jpg border=0></center></body>';
		}
	}
}
elseif($reg_open)
{
echo $tabelka;
}
else 
{
echo '<center>Registration closed. Try later.<br><br><a href="http://127.0.0.1/rfweb/list.htm"><img src="retour.jpg" border="0"></center>';
}
?>