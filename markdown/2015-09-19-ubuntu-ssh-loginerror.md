---
layout: post
title: "ubuntu中ssh登录错误"
date: 2015-09-19 10:54:26
categories: ubuntu error
excerpt: ubuntu中ssh登录错误
---

* content
{:toc}

## 错误提示

> WARNING: REMOTE HOST IDENTIFICATION HAS CHANGED! 


## 解决办法一
	
> 执行命令行

	#mv /homt/zw/.ssh/known_hosts /tmp


## 解决办法二

> 直接编辑known_hosts文件,把里面与所要连接IP(114.215.133.120)相关的内容删掉即可.

