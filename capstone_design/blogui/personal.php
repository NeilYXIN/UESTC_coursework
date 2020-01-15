<!--混编-->
<?php
  include("conn.php");


  if (!empty($_GET['name'])){
    $name=$_GET['name'];
    $get=$_GET['myname'];
  }
?>
<html>
    <head>
        <title>个人主页</title>
        <meta http-equiv="X-UA-Compatible" content="IE=edge">
	    <meta name="viewport" content="width=device-width, initial-scale=1">
	    <link href="css/bootstrap.min.css" rel="stylesheet" media="screen">
	    <style type="text/css">
		    body {
			    padding-top: 60px;
			    padding-bottom: 40px;
		    }

		    .sidebar-nav {
			    padding: 9px 0;
		    }

		    textarea {
			    width: 100%;
			    display: block;
		    }

		    .sidebar-module {
                padding: 15px;
                margin: 0 -15px 15px;
            }

            .user-page-title {

            }
            .user-page-meta {
                color: #999;
            }

		    @media (max-width: 980px) {
			    div#main-container {
				    padding: 0px;
			    }
		    }

		    @media (max-width: 980px) {
			    /* Enable use of floated navbar text */
			    .navbar-text.pull-right {
				    float: none;
				    padding-left: 5px;
				    padding-right: 5px;
			    }
		    }
	    </style>
    </head>
    <body>

        <nav class="navbar navbar-inverse navbar-fixed-top">
		    <div class="container-fluid">
			    <div class="navbar-header">
				    <button type="button" class="navbar-toggle collapsed" data-toggle="collapse" data-target="#navbar" aria-expanded="false"
				    aria-controls="navbar">
					    <span class="sr-only">Toggle navigation</span>
					    <span class="icon-bar"></span>
					    <span class="icon-bar"></span>
					    <span class="icon-bar"></span>
				    </button>
				    <a class="navbar-brand" href="index.php?name=<?php echo $get?>&myname=<?php echo $get?>">微博大厅</a>
			    </div>
			    <div id="navbar" class="navbar-collapse collapse">

				    <div class="dropdown pull-right">
					    <p class="navbar-text pull-right" id="user-info">
						    <!--Logged in as <a href="#" class="navbar-link">Username</a>-->
						    <a href="personal.php?name=<?php echo $get?>&myname=<?php echo $get?>"><?php echo $get ?></a>
					    </p>
				    </div>
			    </div>
		    </div>
	    </nav>


	    <div class="container">
            <div class="col-sm-8">
                <!--
                <a href='index.php?myname=<?php echo $get?>&name=<?php echo $name?>' >微博大厅</a><br></br>
                <a href='personal.php?myname=<?php echo $get?>&name=<?php echo $name?>' >用户名：<?php echo $name ?></a><br></br>
                -->
                <!-------------如果没有关注则显示关注按钮------------------->
                <?php
	                if ( $get != $name){	//对当前用户id与自己id比较做判断
		                $sql_is_followed="select * from `follownfans` where `userid`='$get' and `followorfans`='$name' and `tag`=0";
		                $is_followed=mysql_query($sql_is_followed)or die ('失败');

		                if(mysql_num_rows($is_followed))
		                {//不为空
                ?>
                <form action="personal.php?myname=<?php echo $get?>&name=<?php echo $name?>" method="post">
                <input class="btn btn-primary" type="submit" name="cancalfollow" value="取消关注">
                </form>
                <?php
		                }
		                else
		                {//为空
                ?>
                <form action="personal.php?myname=<?php echo $get?>&name=<?php echo $name?>" method="post">
                <input class="btn btn-primary" type="submit" name="addfollow" value="添加关注">
                </form>
                <?php
		                }
		                if(!empty($_POST['cancalfollow'])){
		                $sql_delete_follow1=
		                "delete from `follownfans` where `userid`='$get' and `followorfans`='$name' and `tag`=0";
		                $sql_delete_follow2=
		                "delete from `follownfans` where `userid`='$name' and `followorfans`='$get' and `tag`=1";
		                mysql_query($sql_delete_follow1);
		                mysql_query($sql_delete_follow2);
		                echo "<script>alert('取消关注成功')</script>";
                    ?>
                    <meta http-equiv="refresh" content="0;url=personal.php?myname=<?php echo $get?>&name=<?php echo $name?>">
                    <?php
		                }
		                else if(!empty($_POST['addfollow'])){
		                $sql_add_follow1=
		                "insert into `follownfans` ( `userid`, `followorfans`, `tag`) values ('$get','$name','0')";
		                $sql_add_follow2=
		                "insert into `follownfans` ( `userid`, `followorfans`, `tag`) values ('$name','$get','1')";
		                mysql_query($sql_add_follow1);
		                mysql_query($sql_add_follow2);
		                echo "<script>alert('添加关注成功')</script>";
                    ?>
                    <meta http-equiv="refresh" content="0;url=personal.php?myname=<?php echo $get?>&name=<?php echo $name?>">
                    <?php
		                }
	                }

                ?>
  <hr>
                <?php if ($get==$name): ?>
                <a href='add.php?myname=<?php echo $get ?>' >写微博</a>
                <?php endif; ?>


                <?php

	                $sql="select * from `entries` where userid = '$name' order by id desc limit 20 "; //倒序， 只显示前20条
	                $query=mysql_query($sql)or die ('失败');   //取出所有数据

	                while($rs=mysql_fetch_array($query))    //取出一条数据
	                {
                ?>

                <hr>

                <!--<h3 class="user-page-title">
                    <?php echo $rs['title'] ?>
                </h3>-->

                <p class="user-page-meta">
                  <?php echo '微博用户' ?>
                  <a href='personal.php?name=<?php echo $rs['userid']?>&myname=<?php echo $get?>' >
                    <?php echo '#' . $rs['userid'] . '#' ?></a>


                </p>
                <h4><?php echo $rs['contents'] ?></h4>
                <p>  <?php echo $rs['dates'] ?></p>
                <!--
                <p class="user-page-meta">
                    <?php echo $rs['dates'] ?>
                    <?php echo $rs['userid'] ?>
                </p>
                <p><?php echo $rs['contents'] ?></p>
                -->
                <!--
                <h3> 用户：<a href="personal.php?name=<?php echo $rs['userid']?>&myname=<?php echo $get?>"> <?php echo $rs['userid']?></a></h3>
                <h4>标题：<?php echo $rs['title'] ?>  </h4> <!--删除需要传递id
                <p><?php echo $rs['contents'] ?></p>

                <li><?php echo $rs['dates'] ?></li>
                -->
                <a href="comment.php?comment=<?php echo $rs['id'] ?>&myname=<?php echo $get?>">评论</a>    

                <?php if ($get==$name): ?>
                    <a href="del.php?del=<?php echo $rs['id']?>&myname=<?php echo $get?>">删除</a>
                <?php endif; ?>

                <?php
	                }
                ?>
            </div>
        </div>
    </body>
</html>
