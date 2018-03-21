# ubuntu 必装软件教程

## git

> http://blog.csdn.net/ithomer/article/details/7529022

安装git
> sudo apt-get install git

设置本机用户名和邮箱
> git config --global user.name "yourname"
> git config --global user.email "youremail@qq.com"

生成密钥
> ssh-keygen -t rsa -C "youremail@qq.com"

查看密钥并将其复制进github-->setting-->SSH keys
> cat ~/.ssh/id_rsa.pub

新增文件
> git add wenjian_name

新增所有
> git add .

提交
> git commit -m "评论"

首次推送至服务器
> git remote add origin git@github.com:wenruo95/markdown.git

后续提交至服务器
> git push -u origin master

	echo "# algorithm" >> README.md
	git init
	git add README.md
	git commit -m "first commit"
	git remote add origin git@github.com:wenruo95/algorithm.git
	git push -u origin master

## vim
vim使用vundle管理插件，具体操作参考：
> https://github.com/wenruo95/note/blob/master/vim%E5%AE%89%E8%A3%85

## nodejs
安装nodejs
> sudo apt-get install nodejs

## python
ubuntu16.04 是自带python2.7.12
ctrl+alt+t打开命令行，输入python 显示python版本以及其他信息 输入'quit()'退出命令行


## 网易云音乐

	在官网下载网易云安装包
	> sudo dpkg -i net*.deb
	此处如果出现安装错误，通常出现依赖错误.安装依赖包
	> sudo apt-get -f install libqt5multimedia5-plugins libqt5multimediawidgets5
	如果提示仍有未安装的依赖包,运行以下语句再继续执行上述语句
	> sudo apt-get -f install
	继续安装依赖包
	> sudo apt-get -f install libqt5multimedia5-plugins libqt5multimediawidgets5 libqgsttools-p1
	然后再继续安装网易云音乐


> http://blog.csdn.net/wqs1010/article/details/10003621

	sudo /etc/init.d/apache2 restart
	sudo svnserve -d -r /home/wys/svn

	/etc/init.d/svnserve start   

	/var/log/apache2/error.log

	http://blog.51cto.com/xujunyan/243958


## java

wget http://download.java.net/java/GA/jdk9/9/binaries/jdk-9+181_linux-x64_bin.tar.gz



## nginx
https://vsxen.github.io/2017/04/09/nginx-sourse-compile-on-ubuntu/
https://segmentfault.com/a/1190000007116797
https://moonbingbing.gitbooks.io/openresty-best-practices/content/ngx/nginx_brief.html

wget http://nginx.org/download/nginx-1.12.2.tar.gz

tar -zxvf nginx-1.12.2.tar.gz


 ~ /usr/local/webserver/nginx/sbin/nginx           #启动 nginx 服务
 ~ /usr/local/webserver/nginx/sbin/nginx -s stop   #停止 nginx 服务

pcre 下载
https://sourceforge.net/projects/pcre/files/pcre/8.41/pcre-8.41.tar.gz/download

tar -xf pcre-8.20.tar.gz   
[root@lxp2 Downloads]# cd pcre-8.20  
[root@lxp2 pcre-8.20]# ./configure  
[root@lxp2 pcre-8.20]# make  
[root@lxp2 pcre-8.20]# sudo make install  



## QT
http://blog.csdn.net/keith_bb/article/details/51533584