---
layout: post
title: "jekyll配置githubpage"
categories: Jekyll
tags: Jekyll
author: linkzw
---

* content
{:toc}

## 搭建本地jekyll环境

安装Ruby（因为Jekyll是Ruby写的）

	$ sudo apt-get install ruby ruby-dev

修改ruby软件源

	$ gem sources --remove http://rubygems.org/
	$ gem sources -a https://ruby.taobao.org/
	$ gem sources -u

安装Jekyll

	$ sudo gem install jekyll 

安装NodeJs 不然运行的话会报 Could not find a JavaScript runtime. 

	$ sudo apt-get install nodejs


## 参考
 
[jekyll本地环境搭建](https://qiujun.me/post/jekyll-blog/)

[jekyll配置选项](https://github.com/Gaohaoyang/gaohaoyang.github.io/blob/master/README-zh-cn.md)