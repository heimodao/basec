---
layout: post
title: "Ubuntu开发环境配置"
categories: 开发工具 Faq
tags: vim ubuntu tools
author: linkzw
---

* content
{:toc}


## ubuntu安装
	
* [iso下载](https://www.ubuntu.com/download)：https://www.ubuntu.com/download
* [软碟通下载(ultraISO)](https://cn.ultraiso.net/uiso9_cn.exe):https://cn.ultraiso.net/uiso9_cn.exe

制作ubuntu启动盘
	0.软碟通安装
	1.导入iso，文件->打开
	2.选择U盘，启动->写入硬盘映像
	制作完毕
	
	
插上U盘，重启电脑，在BIOS中设置U盘为第一启动项。
打开BIOS，台式通常为Delete,笔记本根据不同类型设置不同，通常是F8、F10或者F12
	
按照指引安装ubuntu。

ubuntu建议分区为
	
	swap交换分区：大小设置为电脑内存大小10G
	boot引导分区：大小设置为200M
	/.主分区:大小设置为50G
	home分区：剩下所有
	
	
## [git](http://blog.linkzw.com/2018/04/09/git-lines/)

	http://blog.linkzw.com/2018/04/09/git-lines/
	
## [vim](http://blog.linkzw.com/2018/05/08/vim-lines/)

	http://blog.linkzw.com/2018/05/08/vim-lines/
	
## svn

	sudo apt-get install subversion
	svn --version

## shadowsocks

pip安装

	sudo apt-get update
	sudo apt-get install python-pip
	sudo apt-get install python-setuptools m2crypto
	pip install shadowsocks

ubuntu自带apt安装

	sudo apt install shadowsocks

gui安装
	sudo add-apt-repository ppa:hzwhuang/ss-qt5
	sudo apt-get update
	sudo apt-get install shadowsocks-qt5
	
文档
	sslocal --help

启动
	sslocal -c config.json 

switchomega:

	https://github.com/FelisCatus/SwitchyOmega/releases/

规则列表:

	https://raw.githubusercontent.com/gfwlist/gfwlist/master/gfwlist.txt
	
	socks5	127.0.0.1 
	
	
## java、maven、mysql、tomcat

## redis
	
	wget http://download.redis.io/releases/redis-4.0.9.tar.gz
	tar -zxvf redis-4.0.9.tar.gz
	cd redis-4.0.9
	sudo make clean
	sudo make install

## lua
 
	wget http://www.lua.org/ftp/lua-5.3.4.tar.gz
	tar -zxvf lua-5.3.4.tar.gz
	cd lua-5.3.4
	sudo make clean
	sudo make linux
	sudo make install
 


## 安转ssh服务

	sudo apt-get install openssh-server
	
检查ssh服务是否启动
	
	ps -ef |　grep ssh

启动: /etc/init.d/ssh start
重启: /etc/init.d/ssh restart
关闭: /etc/init.d/ssh stop

查看监听端口

	netstat -anp | grep ssh

	如果监听端口不是22，则修改配置文件/etc/ssh/sshd_config中的Port字段

设置sshd开机启动
	
	在配置文件/etc/rc.local文件exit 0前加入下面一行
	/etc/init.d/ssh start

## nginx
	
	http://www.runoob.com/linux/nginx-install-setup.html
	
## 无法安装谷歌浏览器插件

	./google/chrome/chrome --enable-easy-off-store-extension-install
	
	