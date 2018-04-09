---
layout: post
title: "mysql一些常见错误"
author: "曾巍"
categories: DB Fixbug
tags: mysql fixbug
author: linkzw
---

* content
{:toc}



## mysql中的1064错误和字符处理

在java程序中的一些字符串想要保存到数据库中，就不得不注意这个问题，直接贴代码。   

 
	sql="insert into data_tb(purpose,user_name) " + " values(\'"+purpose+"\',\'"+userName+"\');";

	Insert ins=new Insert();
	ins.insert(sql);

要对有字符串的打单引号，单引号要用转义字符”\’”。    
很多时候MySQL的1064的错误就是由它引起的。    
这是个细节问题，很容易就出现错误。   
    

## mysql错误代码1045

> 错误代码：1045

> Access denied for user ‘root’@’localhost’ (using password:YES)

通过网上查资料，最后得出结论是要修改mysql的root密码。     
修改密码的办法网上也是普遍有点麻烦，而且由于我的是mysqlserver5.7所以很多的办法都不适用。    

> 我就直接把mysql存储数据的那个文本文档给删除了，在数据库中数据已备份的情况下删除数据库中的my.ini，然后就简单了，这时的MySQL的root密码已经被清除了。然后打开数据库运行一下查询语句即可修改密码。
 
	use mysql;
	update user set password=password('newpassword') where user='root';
	flush privileges;

我的解决办法比较粗暴，但是这个问题最终都是要通过修改密码来解决的。    
在数据库已备份的情况下或者对数据库操作不熟悉的情况下可以直接使用这个办法。但是不推荐使用这个办法。    
等以后有其他办法的时候在继续更新吧。    

---





