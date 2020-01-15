<!--混编-->
<html>
    <head>
        <title>微博大厅</title>
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
      <?php
        include("conn.php");

        if (!empty($_GET['myname'])){
          $get=$_GET['myname'];

          //int tag==0, follow       tag==1,fans
          $sql_follow="select count(*) from `follownfans` where `userid`='$get' and `tag`=0";
          $query_follow=mysql_query($sql_follow);
          $rs_follow=mysql_fetch_array($query_follow);

          $sql_fans="select count(*) from `follownfans` where `userid`='$get' and `tag`=1";
          $query_fans=mysql_query($sql_fans);
          $rs_fans=mysql_fetch_array($query_fans);

        }
      ?>
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
				    <a class="navbar-brand" href="#">微博大厅</a>
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
                <?php

                    $sql="select * from `entries` order by id desc limit 20"; //倒序， 只显示前20条
                    $query=mysql_query($sql);   //取出所有数据

                    while($rs=mysql_fetch_array($query))    //取出一条数据
                    {
                ?>
                <!--<h3 class="user-page-title">
                    <a href="personal.php?name=<?php echo $rs['userid']?>&myname=<?php echo $get?>">
                        <?php echo $rs['title'] ?>
                    </a>
                </h3>-->
                <p class="user-page-meta">
                  <?php echo '微博用户' ?>
                  <a href='personal.php?name=<?php echo $rs['userid']?>&myname=<?php echo $get?>' >
                    <?php echo '#' . $rs['userid'] . '#' ?></a>


                </p>
                <h4><?php echo $rs['contents'] ?></h4>
                <p>  <?php echo $rs['dates'] ?></p>
                <p><a href="comment.php?comment=<?php echo $rs['id'] ?>& myname=<?php echo $get?>">评论</a></p>
                <!----这里是自己查看别人的主页，所以name!=myname---->
                <hr>
                <?php
                    }
                ?>
            </div>

            <div class="col-sm-3 col-sm-offset-1">
                <div class="sidebar-module">
                    <a href='personal.php?name=<?php echo $get?>&myname=<?php echo $get?>'><h4>个人主页</h4></a>
                        <li>关注数：<a href="follow.php?userid=<?php echo $get?>"><?php echo $rs_follow[0] ?> </a></li>
                        <li>粉丝数：<a href="fans.php?userid=<?php echo $get?>"><?php echo $rs_fans[0] ?> </a></li>
                    <a href='add.php?myname=<?php echo $get ?>' >写微博</a><?php echo "   " ?>
                    <a href='login.php' >退出</a>

                </div>
            </div>
        </div>

    </body>

</html>
