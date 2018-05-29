---
layout: post
title: "ubuntu命令行"
categories: Faq
tags: ubuntu
author: linkzw
---

* content
{:toc}


# ubuntu的使用

## 空间
	
	du -sh /home/linkzw/*
	du -lh /home/linkzw/ | egrep '[0-9]G'
	
	
## 软件类


以vim为例：(现在ubutnu16.04可以使用apt)

	sudo apt-get install vim
	sudo apt install vim
	sudo apt-get install vim --reinstall 		# 重新安装vim
	sudo apt-get -f install 					# 修复安装完全安装
	sudo apt-get source package 				# 下载该包的源代码

ubuntu源更新：

	sudo apt-get update							# 更新源
	sudo apt-get upgrade						# 更新已安装的包


软件卸载: 

	sudo apt-get remove --purge vim && sudo apt-get autoremove
		删除vim配置							删除无用包
	sudo apt-get clear && sudo apt-get autoclean
		清理无用包							自动清理无用包

搜索包:
	
	apt-cache search package
	apt-cache show package						# 获取包的相关信息，如说明、大小、版本等

## 软件位置

1.查询版本

1)aptitude show 软件名

	例如：aptitude show kde-runtime 

2)dpkg -l软件名

	例如：dpkg -l gedit

2.查询安装路径
1)dpkg -L 软件名

	例如：dpkg -L gedit  

2)whereis 软件名

例如：whereis gedit


## 用户切换

	su root 									# 切换成root用户
	su linkzw									# 切换成linkzw用户
	passwd										# 如没有密码设置密码
	passwd linkzw								# 修改linkzw密码
	

## 文件操作

查看当前目录:

	pwd


打开某个目录：比如当前用户linkzw,打开/home/username/workspace

	cd /home/linkzw/workspace	或者 cd ~/workspace


查看某个目录：如查看workspace目录下所有文件
 	ls ~/workdspace	同理 ls /home/linkzw/workspace

 	列表查看
 	ls -la ~/workspace
 	参数使用输入ls --help了解


文件权限：将workspace文件夹赋给linkzw组linkzw用户使用

	chown -R linkzw:linkzw /home/linkzw/workspace

复制:如复制workspace到/opt/workspace下

	sudo cp workspace /opt/workspace

移动：

	sudo mv wordspace /opt/workspace
	还有一些关于mv的小技巧，如改名test.txt 改成test2.txt（文件夹改名同理）
	sudo mv test.txt test2.txt

删除：
	
	sudo rm -rf workspace 						# 删除当前文件夹下所有
	由于ubuntu中没有回收站这个东西，不建议直接删除，建议新建一个Delete文件夹，然后写个脚本定时清除。
	sudo mv workspace ~/Delete	


## 关机重启

现在关机：

	sudo shutshutdown -h now					# 现在关机
	sudo shutshutdown -h +3 					#分钟后关机
	sudo shutshutdown -h 12:00 					# 12点关机
	sudo shutshutdown-c 						# 取消自动关机


重启：

	sudo reboot
	sudo shutshutdown -r now 					# 现在重启
	sudo shutshutdown -r +3					 	# 3分钟后重启
	sudo shutshutdown -r 12:00 					# 12点重启
	sudo shutshutdown -r 12:00 & 				# 12点重启任务放置后台，用户可以继续操作终端


## 进程 
查询某个进程:查询vim进程

	ps -ef | grep vim 


查看端口号8080使用情况

	netstat -ap | grep 8080


强制关闭某个进程

	kill -s 9 processid 						# processid 为进程id

## 文本

查看:如查看test.txt

	cat test.txt 								# 查询当前所有目录所有文本中包含"test"字符串的文本
	head test.txt 								# test.txt前10行
	head -20 test.txt 							# test.txt前20行
	tail test.txt 								# test.txt后10行
	tail -100 test.txt 							# test.txt后100行
	tail -f test.txt 							# 持续输出test.txt新增行数，常用于查看日志


查询：如查询字符串"helloworld"

	cat test.txt | grep helloworld 或者 cat test.txt | grep "helloworld"
	cat *.txt | grep "helloworld"
	cat **/*.txt | grep "helloworld" 			# 当前目录下的递归目录文档中包含helloworld字符串的文件
	cat **/*.lua | grep "function.*helloworld"  # 查询当前目录下所有关于helloworld函数的定义
 
当然在vim中也有这种操作：
	
	:vim /function.*helloworld/ **/*.lua

统计:

	wc 
	-c 统计字节数。
	-l 统计行数。
	-m 统计字符数。这个标志不能与 -c 标志一起使用。
	-w 统计字数。一个字被定义为由空白、跳格或换行字符分隔的字符串。
	-L 打印最长行的长度。
	-help 显示帮助信息
	--version 显示版本信息
	
	wc **/*.lua									# 统计所有lua文件的行数、字节数
	wc player.lua
	3063	7542	86786 player.lua
	行数	单词数	字节数
	ls -l | wc -l

## 查找

http://www.ruanyifeng.com/blog/2009/10/5_ways_to_search_for_files_using_the_terminal.html
	
find

	find <指定目录> <制定条件> <指定动作>
	find . -name 'my*' 					# 搜索当前目录（含子目录，以下同）中，所有文件名以my开头的文件。
	find . -name "my*" ls 				# 搜索当前目录中，所有文件名以my开头的文件，并显示它们的详细信息。
	find . -type f -mmin -10			# 搜索当前目录中，所有过去10分钟中更新过的普通文件。如果不加-type f参数，则搜索普通文件+特殊文件+目录。



	find  $PWD -maxdepth 1  | xargs ls -ld
	列出当前目录下的所有文件（包括隐藏文件）的绝对路径， 对目录不做递归

	find  $PWD | xargs ls -ld
	递归列出当前目录下的所有文件（包括隐藏文件）的绝对路径
	
	locate
	whereis
	which
	type

## 远程连接
	
	ssh -p 220 user@host

这样每次连接都要输入密码，太麻烦了

	ssh-keygen 									# 本地电脑生成ssh-key密钥
	ssh-copy-id user@host						# 接下来一路同意
	ssh user@host								# 这样就不要每次登录都输入密码了

##系统

	# uname -a               # 查看内核/操作系统/CPU信息
	# head -n 1 /etc/issue   # 查看操作系统版本
	# cat /proc/cpuinfo      # 查看CPU信息
	# hostname               # 查看计算机名
	# lspci -tv              # 列出所有PCI设备
	# lsusb -tv              # 列出所有USB设备
	# lsmod                  # 列出加载的内核模块
	# env                    # 查看环境变量


## 资源

	# free -m                # 查看内存使用量和交换区使用量
	# df -h                  # 查看各分区使用情况
	# du -sh <目录名>        # 查看指定目录的大小
	# grep MemTotal /proc/meminfo   # 查看内存总量
	# grep MemFree /proc/meminfo    # 查看空闲内存量
	# uptime                 # 查看系统运行时间、用户数、负载
	# cat /proc/loadavg      # 查看系统负载


## 磁盘、内存
> http://blog.csdn.net/jzp12/article/details/7560450
> http://blog.csdn.net/newjueqi/article/details/7054582

	# mount | column -t      # 查看挂接的分区状态
	# fdisk -l               # 查看所有分区
	# swapon -s              # 查看所有交换分区
	# hdparm -i /dev/hda     # 查看磁盘参数(仅适用于IDE设备)
	# dmesg | grep IDE       # 查看启动时IDE设备检测状况


## 网络

	# ifconfig               # 查看所有网络接口的属性
	# iptables -L            # 查看防火墙设置
	# route -n               # 查看路由表
	# netstat -lntp          # 查看所有监听端口
	# netstat -antp          # 查看所有已经建立的连接
	# netstat -s             # 查看网络统计信息

## 进程

	# ps -ef                 # 查看所有进程
	# top                    # 实时显示进程状态


## 用户

	# w                      # 查看活动用户
	# id <用户名>            # 查看指定用户信息
	# last                   # 查看用户登录日志
	# cut -d: -f1 /etc/passwd   # 查看系统所有用户
	# cut -d: -f1 /etc/group    # 查看系统所有组
	# crontab -l             # 查看当前用户的计划任务


## 服务

	# chkconfig --list       # 列出所有系统服务
	# chkconfig --list | grep on    # 列出所有启动的系统服务


## 程序

	# rpm -qa                # 查看所有安装的软件包

## 网络配置
	
	ifconfig

## 解压

	.tar
	解包：tar xvf FileName.tar
	打包：tar cvf FileName.tar DirName
	（注：tar是打包，不是压缩！）
	---------------------------------------------
	.gz
	解压1：gunzip FileName.gz
	解压2：gzip -d FileName.gz
	压缩：gzip FileName
	.tar.gz 和 .tgz
	解压：tar zxvf FileName.tar.gz
	压缩：tar zcvf FileName.tar.gz DirName
	---------------------------------------------
	.bz2
	解压1：bzip2 -d FileName.bz2
	解压2：bunzip2 FileName.bz2
	压缩： bzip2 -z FileName
	.tar.bz2
	解压：tar jxvf FileName.tar.bz2
	压缩：tar jcvf FileName.tar.bz2 DirName
	---------------------------------------------
	.bz
	解压1：bzip2 -d FileName.bz
	解压2：bunzip2 FileName.bz
	压缩：未知
	.tar.bz
	解压：tar jxvf FileName.tar.bz
	压缩：未知
	---------------------------------------------
	.Z
	解压：uncompress FileName.Z
	压缩：compress FileName
	.tar.Z
	解压：tar Zxvf FileName.tar.Z
	压缩：tar Zcvf FileName.tar.Z DirName
	---------------------------------------------
	.zip
	解压：unzip FileName.zip
	压缩：zip FileName.zip DirName
	---------------------------------------------
	.rar
	解压：rar x FileName.rar
	压缩：rar a FileName.rar DirName

	rar请到：http://www.rarsoft.com/download.htm 下载！
	解压后请将rar_static拷贝到/usr/bin目录（其他由$PATH环境变量指定的目录也可以）：
	[root@www2 tmp]# cp rar_static /usr/bin/rar
	---------------------------------------------
	.lha
	解压：lha -e FileName.lha
	压缩：lha -a FileName.lha FileName

	lha请到：http://www.infor.kanazawa-it.ac.jp/~ishii/lhaunix/下载！
	>解压后请将lha拷贝到/usr/bin目录（其他由$PATH环境变量指定的目录也可以）：
	[root@www2 tmp]# cp lha /usr/bin/
	---------------------------------------------
	.rpm
	解包：rpm2cpio FileName.rpm | cpio -div
	---------------------------------------------
	.deb
	解包：ar p FileName.deb data.tar.gz | tar zxf -
	---------------------------------------------
	.tar .tgz .tar.gz .tar.Z .tar.bz .tar.bz2 .zip .cpio .rpm .deb .slp .arj .rar .ace .lha .lzh .lzx .lzs .arc .sda .sfx .lnx .zoo .cab .kar .cpt .pit .sit .sea
	解压：sEx x FileName.*
	压缩：sEx a FileName.* FileName


