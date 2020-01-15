


<html>
	<head>
		<title>登录</title>
		<meta charset="utf-8">
		<meta name="viewport" content="width=device-width, initial-scale=1.0">
		<link href="css/bootstrap.min.css" rel="stylesheet" media="screen">
		<style type="text/css">
			body {
				padding-top: 40px;
				padding-bottom: 40px;
				background-color: #f5f5f5;
			}

			div.alert{
				max-width: 300px;
				margin: 0 auto 20px;
			}
			.form-signin {
				max-width: 300px;
				padding: 19px 29px 29px;
				margin: 0 auto 20px;
				background-color: #fff;
				border: 1px solid #e5e5e5;
				-webkit-border-radius: 5px;
				-moz-border-radius: 5px;
						border-radius: 5px;
				-webkit-box-shadow: 0 1px 2px rgba(0,0,0,.05);
				-moz-box-shadow: 0 1px 2px rgba(0,0,0,.05);
						box-shadow: 0 1px 2px rgba(0,0,0,.05);
			}
			.form-signin .form-signin-heading,
			.form-signin .checkbox {
				margin-bottom: 10px;
			}
			.form-signin input[type="text"],
			.form-signin input[type="password"] {
				font-size: 16px;
				height: auto;
				margin-bottom: 15px;
				padding: 7px 9px;
			}

		</style>
	</head>
	<body>
		<div class="container" id="content">
			<form class="form-signin" id="login-form" action="logincheck.php" method="post">
				<h2 class="form-signin-heading">登录微博</h2>
				<!--<img src="/img/zhwiki.png" class="img-rounded">-->
				<input name="userid" type="text" class="form-control" placeholder="用户名">
				<input name="password" type="password" class="form-control" placeholder="密码">
				<a href="register.php" class="pull-right">注册</a>
				<input id="btn-login" class="btn btn-lg btn-primary btn-block form-control" name="Submit" type="submit" value="登陆" />
			</form>

		</div>
		<script src="js/jquery.min.js"></script>
		<script src="js/bootstrap.min.js"></script>
	</body>

</html>
