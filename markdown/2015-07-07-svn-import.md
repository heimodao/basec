---
layout: post
title: myeclipse导入svn项目
date: 2015-07-07 11:16:01
categories: Tools
tags: svn myeclipse tools
author: linkzw
---

* content
{:toc}
 
## 前言

> 在已建立好svnserver服务器的情况下，且所用电脑上已装好svn，在电脑上导入svn项目.

## 将项目导入电脑

> 首先，新建文件夹，点击鼠标右键，选择TortoiseSVN–>export

![svn项目导入2]({{"/css/pics/svn-import-1.png"}})

> 然后，在URL of repository中输入导入的网址，这个可以从svn服务器上获取，管理员会发给你的
> 打开svn server服务器，然后如下图所示，鼠标右键单击respositories下的项目，然后选择 copy URL to clipboard 这样网址就在你的剪贴板里面了，直接粘贴进去就行了，也可直接把下图所示右边面板中的网址输入进去就行了

![svn项目导入2]({{"/css/pics/svn-import-2.png"}})

> svn export图片中的Export directory是你所要保存到路径，其实这个可以自己输入。其中需要输入账号密码（账号密码管理员设置），导入成功然后ok

![svn项目导入3]({{"/css/pics/svn-import-3.png"}})

> 查看结果

![svn项目导入4]({{"/css/pics/svn-import-4.png"}})
 
 
## 项目导入myeclipse

在myeclipse中import-->import maven project，我的是maven项目，你的根据你自己的项目类型导入即可。

