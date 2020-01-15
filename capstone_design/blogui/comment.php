<script>
    window.onload = function ()
    {
        var str = document.getElementById ('commentid');//后面的input id
        str.onkeyup = function ()
        {
            if (this.value.length > 100)
            {
                alert ('单条微博不能超过100个字！');
                str.value = str.value.substring (0, 100);//这里是最大字数 中文数*2
            }
        }
    }
</script>


<?php
	include("conn.php");
  if (isset($_GET['comment'])){
    $get=$_GET['comment'];
		$getuser=$_GET['myname'];

?>
<a href='index.php?myname=<?php echo $getuser?>' >微博大厅</a><br></br>
<?php

		$sql="select * from `comments` where `entryid`='$get'";
		$query=mysql_query($sql);   //取出所有数据
		while($rs=mysql_fetch_array($query))    //取出一条数据
		{
		?>

		<hr>
		<p>用户:<?php echo $rs['userid'] ?>  </p> <!--删除需要传递id-->
		<li><?php echo $rs['contents'] ?></li>
		<p><?php echo $rs['dates'] ?></p>
		<hr>
		<?php
		}
	}

if(isset($_POST['sub'])){
	$cont=$_POST['cont'];
  global $get;
	$sql1="insert into `comments` ( `userid`, `dates`, `contents`,`commentsid`,`entryid`) values ('$getuser', now(), '$cont',null,'$get')";
	mysql_query($sql1);
	echo "<script>alert('评论成功')</script>";    //用javascript跳转
?>
<meta http-equiv="refresh" content="0;url=comment.php?comment=<?php echo $get?>&myname=<?php echo $getuser?>">
<?php
}

?>

<hr>
<form action="comment.php?comment=<?php echo $get?>&myname=<?php echo $getuser?>" method="post">
内容<textarea rows="5" cols="50" name="cont" id = 'commentid'></textarea><br>
<input type="submit" name="sub" value="发表">
</form>
</hr>
