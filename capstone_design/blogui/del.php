<?php
	include("conn.php");

	if (!empty($_GET['del'])){
		$get=$_GET['del'];
		$myname=$_GET['myname'];
		$sql="delete from `entries` where `id`='$get'";
		mysql_query($sql);
			echo "<script>alert('删除成功')</script>";
	}
?>
<meta http-equiv="refresh" content="0;url=personal.php?myname=<?php echo $myname?>&name=<?php echo $myname?>">
