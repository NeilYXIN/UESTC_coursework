
<?php
  include("conn.php");

	if(isset($_POST["Submit"]) && $_POST["Submit"] == "登陆")
	{
		$user = $_POST["userid"];
		$psw = $_POST["password"];
		if($user == "" || $psw == "")
		{
      echo "<script>alert($user)";
      echo "<script>alert($psw)";
			echo "<script>alert('请输入用户名或密码！'); history.go(-1);</script>";
		}
		else
		{
			$sql = "select userid,password from user where userid = '$_POST[userid]' and password = '$_POST[password]'";
			$result = mysql_query($sql);
			$num = mysql_num_rows($result);
			if($num)
			{
				$row = mysql_fetch_array($result);	//将数据以索引方式储存在数组中
				echo $row[0];
        //这里加入跳转页面
?>
      <meta http-equiv="refresh" content="0;url=index.php?myname=<?php echo $user?>">

      <?php
    #    echo "<script>alert('登陆成功');location.href='index.php?index=$user'</script>";
			}
			else
			{
				echo "<script>alert('用户名或密码不正确！');history.go(-1);</script>";
			}
		}
	}
	else
	{
		echo "<script>alert('提交未成功！'); history.go(-1);</script>";
	}

?>
