<!--连接数据库-->


<!--
db name------- blogs
table name --- entries 
	1	id(primary)		int(5)								否	无		AUTO_INCREMENT	 		

	2	title			varchar(50)	gb2312_chinese_ci		否	无			 					

	3	dates			date								否	无			 				

	4	contents		text		gb2312_chinese_ci		否	无		


-->

<?php 
	//默认mysql用户,屏蔽错误
	@mysql_connect("localhost:3306", "root", "") or die ("mysql连接失败");
	mysql_select_db("blogs") or die ("db连接失败");
	mysql_query("set names 'utf8'");
	
?>