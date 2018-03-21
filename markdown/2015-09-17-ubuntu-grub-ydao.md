---
layout: post
title: "ubuntu grub引导"
author: "曾巍"
categories: ubuntu error
excerpt: ubuntu grub引导
---

* content
{:toc}

## 导语

在体验一把双系统时（win7+ubuntu）,安装ubuntu完成后重启出现无法引导进入ubuntu，直接默认进入win7，查询后发现是grub引导出现问题。   

## 解决办法

### 1.首先找到ubuntu安装的分区

输入命令查询找到ubuntu安装的分区  

	sudo fdisk -l


### 2.挂载ubuntu所在分区到mnt下

输入命令  

	sudo mount /dev/sda7 /mnt

挂载ubuntu所在分区到mnt下  

### 3.安装grub

输入命令  

	sudo grub-install --root-directory=/mnt /dev/sda

安装grub  

### 4.执行完成，重启电脑

输入命令  

	reboot pc

### 后续

如果以上完成后还是不能进入ubuntu，打开终端，输入命令

	sudo update-grub

重启电脑，就可以出现grub引导界面
