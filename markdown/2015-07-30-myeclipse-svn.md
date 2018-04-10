---
layout: post
title: myeclipse集成svn
date: 2015-07-30 11:43:01
categories: svn myeclipse tools
author: svn myeclipse tools
---

* content
{:toc}
 

## svn安装
 
具体svn的安装我就不多说了，下载好svn客户端，一直next就行了。

## myeclipse集成svn

安装好svn后，开始配置svn插件，下载好svn插件， 详细说一下这个，有两种方法。

### 方法一

将插件下载下来解压后，直接复制到MyEclipse安装目录下dropins中即可。重启myeclipse，任意建立一个项目，右键项目–>team–>share Project..，打开后如果看到了SVN代表插件安装成功。

### 方法二

插件下载下来解压后，将其中的features和plugings复制下来，在myeclipse安装目录下的dropins新建一个SVN文件夹，将刚刚复制下来的粘贴进去。然后任意建立一个项目，右键项目–>team–>share Project..，打开后如果看到了SVN代表插件安装成功。 

### 方法三

有的也可以直接通过myeclipse直接安装插件

>1.打开myeclipse-->help-->MyEclipse Configuration Center，然后切换到SoftWare标签页

>2.点击Add Site 打开对话框，在对话框Name输入Svn，URL中输入：http://subclipse.tigris.org/update_1.6.x

>3.在左边栏中找到Personal Site中找到SVN展开。将Core SVNKit Library和Optional JNA Library添加(右键Add to Profile)，Subclipse下面的Subclipse Integration for Mylyn 3.0可以不添加（特别注意，此处不要添加）。

>4.在右下角窗格(Pending Changes )中点击Apply。安装重启后MyEclipse即可。
