---
layout: post
title: "tomcat管理员密码设置"
date: 2015-07-30 11:19:26
categories: tomcat tools
author: linkzw
---

* content
{:toc}

打开tomcat安装目录下的conf，然后打开tomcat-users.xml 

![tomcat密码管理]({{"/css/pics/tomcat-mag-pwd.png"}})

在标签中添加

	<user name="" password="" roles="manager-gui" />

添加后如下所示

	<tomcat-users>
		<user name="zw" password="linkzw" roles="manager-gui" />
	</tomcat-users>
 
添加（修改）tomcat管理员密码成功

