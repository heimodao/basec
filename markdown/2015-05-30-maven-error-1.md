---
layout: post
title: "maven常见问题或错误解决"
categories: maven error
tags: maven error
author: linkzw
---

* content
{:toc}

## Versions of Spring facet could not be detected

在导入已存在的maven web项目的时候，总是出现Versions of Spring facet could not be detected的问题。   

查资料知道有两种解决方法：   

一个是在项目根目录中 [新建.springBeans文件](http://blog.csdn.net/wuqinghai2012/article/details/44223301)   

另一个是org.springframework下没有exception的这个包,需要重新导入这个包。   

但是我在解决的过程中发现都没有成功，我的解决办法是把maven的jar包重新导入一下，或者重载一下pom.xml文件，只要把pom.xml随便打个空格或者直接换行保存，然后重启服务器就可以了   

---

## 解决Maven的“Missing artifact ……”问题

这个问题出现的根源还是maven的jar包导入问题，有可能是下载的时候出了问题，导致没有完全下载成功，pom找不到jar包。   
我的解决办法就是直接把jar下载好，然后直接粘贴到myeclipse设置好的maven的jar包存放地址，然后在pom.xml随便打个空格或换行，保存（ctrl+s）即可。   

---

## Project configuration is not up-to-date with pom.xml

#### 异常

> Description Resource Path Location Type Project configuration is not up-to-date with pom.xml. Run project configuration update rdc line 1 Maven Configuration Problem

#### 错误原因

需要更新maven

#### 解决办法

在myeclipse里面右键项目，选择Maven4MyEclipse–>update project 问题成功解决



