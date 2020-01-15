<html>
    <head>
        <title>粉丝详细名单</title>
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

	        $get=$_GET['userid'];
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

        <div class="container-fluid">
            <div class="row">
                <?php

	                //int tag==0, follow       tag==1,fans
	                $sql_fans="select * from `follownfans` where `userid`='$get' and `tag`=1";
	                $query_fans=mysql_query($sql_fans);


	                //echo "粉丝详细名单";
	                while($rs_fans=mysql_fetch_array($query_fans))    //取出一条数据
	                {
                ?>
                <div class="col-sm-3">
                    <li>
                    <a href="personal.php?name=<?php echo $rs_fans['followorfans']?>
					                      &myname=<?php echo $get?>">
                    <?php echo $rs_fans['followorfans'] ?>
                    </li>
                </div>

                <?php
	                }
                ?>
            </div>
        </div>
    </body>
</html>
