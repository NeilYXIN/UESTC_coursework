<script>
    window.onload = function ()
    {
        var str = document.getElementById ('addid');//后面的input id
        str.onkeyup = function ()
        {
            if (this.value.length > 139)
            {
                alert ('单条微博不能超过139个字！');
                str.value = str.value.substring (0, 139);//这里是最大字数 中文、英文均计为一个字个数
            }
        }
    }
</script>


<?php
	include("conn.php");

	if (!empty($_GET['myname'])){
 		$get=$_GET['myname'];
 	}

	if(!empty($_POST['sub'])){
		$title=$_POST['title'];
		$con=$_POST['con'];
		$sql="insert into `entries` ( `id`, `title`, `dates`, `contents`,`userid`) values (null, '$title', now(), '$con','$get')";
		mysql_query($sql);
		echo "<script>alert('发表成功')</script>";

		?>
	<meta http-equiv="refresh" content="0;url=index.php?myname=<?php echo $get?>">  <!------用javascript跳转---->
<?php


 }

?>

<form action="add.php?myname=<?php echo $get ?>" method="post">
<!--标题<input type="text" name="title"><br>-->
<a href='index.php?myname=<?php echo $get?>' >微博大厅</a>
<h5>有什么新鲜事想告诉大家?</h5><textarea rows="5" cols="50" name="con" id = 'addid'></textarea><br>
<input type="submit" name="sub" value="发布">
</form>
