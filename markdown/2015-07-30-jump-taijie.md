---
layout: post
title: "跳台阶问题-java"
date: 2015-07-30 11:19:26
categories: Java Algorithm
tags: Java Algorithm
author: linkzw
---

* content
{:toc}

## 跳台阶问题

![跳台阶问题]({{"/css/pics/jump-taijie1.png"}})

### 题目描述：

一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法。  

### 解析

这个问题归根结底还是一个费布拉奇数列，仔细找一下规律即可，刚开始做的时候我是直接写出前六个数的结果来找规律的。   

一级台阶：1种 fib(1)=1   
二级台阶：2种 fib(2)=2   
三级台阶：3种 fib(3)=fib(1)+fib(2)=3   
四级台阶：5种 fib(4)=fib(2)+fib(3)=5   
五级台阶：8种 fib(5)=fib(3)+fib(4)=8   
六级台阶：13种 fib(6)=fib(4)+fib(5)=13  

现在看出规律了吧，fib(n)=fib(n-1)+fib(n-2),fib(1)=1,fib(2)=2。   
java代码如下所示（直接在main函数中调用即可）：  

	public int jumpFloor(int number) {
        if (number == 1)
            return 1;
        else if (number == 2)
            return 2;
        else 
            return jumpFloor(number-1)+jumpFloor(number-2); 

    } 


## 跳台阶问题变态版

### 题目描述

一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法。   

### 解析

这个也是如上所示的推理方法，没什么技术含量。写出前六个的跳台阶的结果，这个有一部分在上面的已经数出来了，所以我们就只要算上可以跳2阶台阶以上的结果就行了。然后算出   

一级台阶：1种 f=fib(1)=1=2^0   
二级台阶：2种 f=fib(2)=2=2^1   
三级台阶：3种 f=fib(3)+1=4=2^2   
四级台阶：5种 f=fib(4)+3=8=2^3   
五级台阶：8种 f=fib(5)+8=16=2^4   
六级台阶：13种 f=fib(6)+19=32=2^5  

然后这个思路清晰了，代码就好写了，和上面类似，都是考察递归和循环的知识点。  

	public int jumpFloor2(int number) {
        if (number ==1)
            return 1;
        else if(number==2)
            return 2;
        else
            return jumpFloor2(number-1)*2;
    }
 
## 总结：

在做题的时候，刚开始总要学会动笔找一些规律，先想好思路，找出规律，把问题用数学方法找出解决规律办法，然后再用编程来实现。当然方法有很多种，递归、循环。
