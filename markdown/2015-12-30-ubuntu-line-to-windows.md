---
layout: post
title: "ubuntu远程连接windows"
categories: Ubuntu
tags: ubuntu windows
author: linkzw
---

* content
{:toc}

## 1.首先在ubuntu上安装rdesktop


    sudo apt-get install rdesktop

---

## 2.连接windows


    rdesktop 192.168.1.1 -u user -p password


这个是直接连接，默认为全屏模式

---

## 3.扩展

>  用法： rdesktop[options] server[:port] 

---

### 3.1更多参数

    -u用户名
    -p密码
    -n客户端主机名（显示windows任务管理器中的连接客户端名）
    -g桌面大小（ 宽＊ 高）[也可以用 x(小写的X)]
     -f全屏模式,从全屏模式切换出来按Ctrl+Alt+Enter
    -a连接颜色深度（最高到16位），一般选16才会显示真彩色（window7支持32位）
    -0数字0表示连接上windows控制台，等效mstsc/console命令

---

### 3.2更多例子


    rdesktop -f -a 16 192.168.1.1 -u user -p password 


a后面的参数可以根据电脑自行选择


    rdesktop 192.168.1.1:8080 -u user -p password -g 800*600


800*600是窗口大小，端口号为8080
