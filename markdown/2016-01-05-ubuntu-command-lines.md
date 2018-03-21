---
layout: post
title: "ubuntu常用命令行"
categories: ubuntu
---

* content
{:toc}

## 前言

> 启动shell后，首先可以看到"zw@localhost:~$"或者"localhost:~#"形式的命令提示符。

* 其中zw和root指的是当前登录的用户账户名，localhost表示本机的主机名
* 最后的"#"字符表示当前登录的用户是管理员账户，"$"表示普通用户
* "~"是一个特殊符号，泛指用户的家目录，可以在命令行输入
```
pwd
```
查看当前目录，root用户的家目录就是
```
/root
```
,普通用户的user的家目录是
```
/home/user
```
,如普通用户zw的家目录就是
```
/home/zw
```

---

## shell命令

> shell命令是由命令名、选项、参数三部分组成，基本格式如下：
 
    命令名 [选项][参数] 
    shutdown -r now #系统重启，这个需要获取root权限

## 用户切换&&权限获取

---

#### 获取管理员(root)权限

更改可以不用切换用户登录，直接在命令行中输入
```
sudo -i
```
或者
```
su root
```
获取root权限。
如果这样不行的话那就在命令行中输入
```
sudo passwd
```
然后输入两次密码，这个就是修改好的root密码。然后再输入
```
sudo root
```
输入修改好的root密码就能获取root权限。

---

#### root切换成普通用户和普通用户间的切换

直接输入
```
sudo username
```
如切换成普通用户zw的直接输入
```
su zw
```

---

#### 文件权限

在修改ubuntu内部文件时经常可以看到权限不够这样的字眼，当然我们一般都是直接获取root权限，但是也可以直接输入
```
su root
```
获取root权限，或者输入
```
sudo nautilus
```
获取文件操作权限，问题基本都可以得到解决。

---

## 文件操作

ubuntu文件中有绝对目录和相对目录两种，打开当前目录的某一个文件夹(如下载)
![跳台阶问题]({{"/css/pics/ubuntu-file-play-1.png"}})

    cd 下载       #这个是相对目录
    cd ../        #返回上一级目录
    cd /usr       #在/home/zw目录下打开根目录下的/usr，这个是绝对路径

shell命令

---

#### 创建文件夹


    mkdir 新建文件夹名

---

#### 新建除文件夹外的其他文档可直接用vim直接创建


    vim /home/user/Helloworld.java

---

#### 删除文件或文件夹


    sudo rm -r 文件夹名或文档名

---

#### 查看本地目录地址

    pwd

---

## 软件安装卸载

---

#### 软件更新


    sudo apt-get update//更新软件列表

---

#### 系统、软件更新


    sudo apt-get upgrade

这个不要乱用，可能会把系统也更新

---

#### 软件安装


    sudo apt-get install 软件名

---

#### 软件卸载


    sudo apt-get purge 软件名
    sudo apt-get autoremove
    sudo apt-get clean
    sudo apt-get remove --purge 软件名
    sudo apt-get update

---

## vim的一些基本操作

> vim的一些基本操作和插件的安装使用会另外再写一篇文章


---

## git的基本操作


> 这个由于git的使用比较繁杂，内容比较多，因此也会在另一篇文章中仔细叙述
