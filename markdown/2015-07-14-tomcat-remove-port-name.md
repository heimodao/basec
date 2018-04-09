---
layout: post
title: "tomcat移除端口号和项目名"
date: 2015-07-14 12:51:27
categories: Tools
tags: tomcat tools
author: linkzw
---

* content
{:toc}


## 前言

通常在做网站项目最终发布的时候为了给访问者留下一个深刻的印象，要尽量将网站域名取得简单易记。   
这个时候如果使用tomcat做Web 应用服务器的话，通常都需要在网站发布之前将网站端口号和项目名去除。   

网站初始访问网址为:http://localhost:8080/LinkST   

---

## 改变tomcat端口号

tomcat端口号默认为8080，打开tomcat–>conf–>server.xml服务器配置文件，直接搜索8080，在68行的connector中，将port改为你想要取的端口号，如想去除端口号，直接将端口号改为80。   

	<Connector port="8080" protocol="HTTP/1.1"
               connectionTimeout="20000"
               redirectPort="8443" />
       <Connector port="8009" protocol="AJP/1.3" redirectPort="8443" />

现在输入：http://localhost:80/LinkST（会默认将80隐藏跳转至http://localhost/LinkST）或者http://localhost/LinkST都可访问   
 
## 移除tomcat项目名

同理，打开tomcat–>conf–>server.xml服务器配置文件，找到配置文件的最下方的host中   

	<Host name="localhost"  appBase="webapps"
            unpackWARs="true" autoDeploy="true">
         <!--可在此处添加代码--> 
        <Valve className="org.apache.catalina.valves.AccessLogValve" directory="logs"
               prefix="localhost_access_log" suffix=".txt"
               pattern="%h %l %u %t &quot;%r&quot; %s %b" />

      </Host>

在代码提示出添加如下所示代码，其中docBase为你放在tomcat中的项目文件，通常都在tomcat–>webapp中可以找到    

	<Context docBase="D:\Java\Apache Software Foundation\Tomcat 8.0\webapps\LinkST" path="" /> 

现在输入：http://localhost或者http://localhost/LinkST或者http://localhost:80/LinkST都可访问    


## 成功移除tomcat项目名和端口号

成功移除tomcat项目名和端口号：http://localhost    

---


