---
layout: post
title: "C++面试要求及题型"
categories: C++
tags: C++
author: linkzw
---

* content
{:toc}


## 基本要求

语言（c/c++），算法（强调性能），linux系统编程及内核原理 （才知道如何调优），网络。这是基础。

	1. 网络通信：最低要求能理解 Tcp 是流，Udp 是包，并会创建连接通信，写 epoll 的程序。
		1.1 进阶可以看 《TCP/IP详解》
	2. 多线程编程：最低要求理解为啥要用锁，并且学会用锁。
		2.1 进阶可以研究一下各种不同的锁，比如读写锁、自旋锁等
		2.2 再可以研究一下 Lock-Free2.3 也可以玩一下协程
	3. 数据库：最少会读会写，优化可以交给 DBA （什么你们没 DBA？那么自己点 DBA 技能吧）
	4. 了解 HTTP 协议等一些你的工作范围可能用到的协议
	5. 学会使用库和其他语言写的服务交互，比如 Redis* 上面这些是写服务器的基础技能，不需要进阶就可以先写*  如果想点 Linux 专精，平时在 Linux 下工作，弄本 《Linux 编程》之类的书学习。


## 实践路径

1. 做HTTP服务器，或者一个内存数据库服务器（要求高一些）
2. 如果编程能力强，操作系统和数据结构的底子好，做一个键值数据库服务器。
3. HTTP服务器，需要进程、数据结构、异步网络IO。
4. 内存数据库服务器，多一个锁。
5. 键值数据库服务器，再多一个存储引擎。

无论是做哪一个，都要考虑到高性能、高可靠、高可用。

了解libevent、缓存替换算法


深度学习专用芯片、高频交易的专/用芯片、比特币的专用芯片（ASIC也属于门阵列）。
而国内国际上搞计算机体系结构的并不多了，除了少数几个学校公司。现在的计算机系统结构的研究，已经根据用途，划分了多个领域。


全局唯一有序 ID。 snowflake ，timestamp 加前面，然后后面加上机器 id 等冯诺依曼体系shell 命令的执行过程信息熵程序运行中的栈式结构，栈溢出攻击TCP/IP 有关知识。TCP 传输层加端口号，IP 网络层加 ip 地址；路由器就主要工作在 IP 网络层同步与阻塞并行与并发Java 线程的本质，内核线程与用户线程，线程调度，并行级别内核态与用户态，中断CPU 与内存与磁盘缓存行与伪共享内存分配管理，段页式。jemalloc


## 面试知识点

* 计算机网络相关 

	1 TCP三次握手、四次挥手
	2 TCP滑动窗口机制
	3 TCP拥塞控制机制
	4 socket模型

* C/C++相关 

	1 虚析构、模板和宏
	2 虚函数实现机制
	3 vector与list的区别，map是如何实现的，查找效率是多少
	4 extern 关键字有什么用
	5 malloc和new的区别，能否malloc(1.2G)

* linux以及操作系统相关 

	1 内存池实现
	2 进程间通信机制
	3 Linux ps命令，以及看内存当前使用状态的命令
	4 进程与线程的区别，共享的数据
	5 进程的内存空间

* 算法与数据结构(手写代码实现)

	1 大整数加、减、乘、除、求模运算实现
	2 很多整数，找其中出现次数最多的那个数
	3 单链表翻转（两个指针如何实现）、查找、删除、插入以及双向链表、有序链表合并
	4 判断一个整数是否是2的整数次幂.(n&(n-1))
	5 二分查找（注意边界条件）
	6 常见排序算法的实现以及稳定性（快排跟归并考的很多）
	7 字符串翻转（O(n)）、匹配（KMP算法）
	8 最长递增子序列（nlogn的算法）
	9 链表判断是否有环，环的入口，两个链表是否相交（快慢指针）。
	10 指定一个数组，求2个数的和等于指定的和（某一个数），如果是3,4,5，n个等于个的和（某一个数）呢？（可以看作背包问题）
	11 跳台阶问题

* 其他 

	1 红黑树的性质以及插入和删除
	2 解析XML文件
	3 千万级的用户，提供一个服务，该服务有很多模块，现在有一个底层模块需要优化，问怎么实现，在不影响其他服务模块以及用户体验的情况下。（面IEG）
	4 卡特兰数以及公式推导（应多很多）
	5 未知大小的文件，翻转整个文件
	6 如果内存中有个cache存储qq号和最近登录时间问怎么样做hit和淘汰
	7 检测短信敏感词
	8 大数据问题
	9 C++、java和PHP有什么本质区别


## 面试问题

	1.c++虚拟函数：	阐述c++中虚拟函数的实现机制
	2.指针：	 	请描述指针数组和数组指针的区别
	3.malloc-free：	请描述malloc-free和new-delete的区别
	4.sizeof和strlen 请描述sizeof和strlen的区别
	5.函数调用 			请描述函数调用的整个过程
	6.c++ stl中的vectory  c++ stl中的vector的实现机制，在调用push_back成员函数时，怎么实现？
	7.c++ stl中的clear  	在c++ stl中，当调用clear成员函数时，做什么操作？要释放内存该怎么做？
	* 提示：调用析构函数clear没有释放内存，clear只是将数组中的元素置为空了，释放内存需要delete。


1. C++基本的认识，问得比较多的是指针、多态（虚函数表、内存 layout等）、作用域、内存的管理等等。（通常只有宣称熟悉 C++或者简历中有很多 C++项目的人，我才会把这个当做一个重要的方面考察；对语言细节研究不深入，或者一直用其它语言比如 go/java 之类的，那也无妨，这块可以稍微放宽要求。）
2. 算法和数据结构，数据结构我比较关注哈希、优先级队列等，算法则是字符串处理、简单的 DFS、BFS、动态规划都有
3. 系统的知识：进程、线程、协程、锁的使用、消息队列、共享内存、还有网络协议、epoll、select等。顺便会考察一些处理问题的基本思路，比如通过哈希来划分、通过队列来序列化操作等等。此外，往往很多同学的项目经历中，有很多点可以结合系统的知识来考察，看看是否真的做过项目。比如我就碰到过自己写过 web server 的，搞过 key-value 数据库的，声称读过 redis 源码的，这些很适合配合系统知识考察，确认是不是真的做过这些项目，理解如何。
4. 和应聘者背景经历有关的知识，比如学信息安全，刚好是我的专业，我会问一些简单的安全知识，比如缓冲区溢出、SQL 注入、虚拟机、https、数字签名原理等等。当然，后面从事了个性化推荐有关的工作，机器学习也稍微懂一点，偶尔可以聊聊。这个主要是发现一些学习态度也特别好，但是又想做后台的同学。


## 大数据题目

多机数据处理。有 10 台机器，每台机器上保存着 10 亿个 64-bit 整数（不一定刚好 10 亿个，可能有上下几千万的浮动），一共约 100 亿个整数（其实一共也就 80GB 数据，不算大，选这个量级是考虑了 VPS 虚拟机的容量，便于实验）。

编程求出：
1. 这些数的平均数。
2. 这些数的中位数。
3. 出现次数最多的 100 万个数。
4. （附加题）对这 100 亿个整数排序，结果顺序存放到这 10 台机器上。
5. （附加健壮性要求）你的程序应该能正确应对输入数据的各种分布（均匀、正态、Zipf）。
6. （附加伸缩性要求）你的程序应该能平滑扩展到更多的机器，支持更大的数据量。比如 20 台机器、一共 200 亿个整数，或者 50 台机器、一共 500 亿个整数。


## Java

程序的运行原理普通可执行程序的运行原理缓存行与伪共享。
从浏览器发出请求开始，到服务端应用接受到请求为止的过程HashMap ，hash 碰撞，hash 算法的优化单点登录正向代理与反向代理反爬机制，爬虫模拟浏览器行为cglib 方法拦截动态代理依赖注入Servlet 的本质TCP 长连接。
心跳包，websocketNetty 百万级长连接优化DSL 解析到 AST 。lexer 和 parserJVM 相关。
你读过 GC 相关源码吗？代码规范，包命名规范
大学里最有成就感的事，读过的 Java 书籍。（四大名著之类）

## 名企面试题

### 微软十五道面试题

1：有一个整数数组，请求出两两之差绝对值最小的值。记住，只要得出最小值即可，不需要求出是哪两个数。

2：写一个函数，检查字符是否是整数，如果是，返回其整数值，（或者：怎样只用 4 行代码编写出一个从字符串到长整形的函数？）

3：给出一个函数来输出一个字符串的所有排列。

4：请编写实现 malloc()内存分配函数功能一样的代码。

5：给出一个函数来复制两个字符串 A 和 B。字符串 A 的后几个字节和字符串 B 的前几个字节重叠。

6：怎样编写一个程序，把一个有序整数数组放到二叉树中？

7：怎样从顶部开始逐层打印二叉树结点数据？请编程。

8：怎样把一个链表掉个顺序（也就是反序，注意链表的边界条件并考虑空链表）？

9：请编写能直接实现 int atoi(const char * pstr)函数功能的代码。

10：编程实现两个正整数的除法，当然不能用除法操作符。

11：在排序数组中，找出给定数字的出现次数，比如 [1, 2, 2, 2, 3] 中 2 的出现次数是 3 次。

12：平面上 N 个点，每两个点都确定一条直线，求出斜率最大的那条直线所通过的两个点（斜率不存在的情况不考虑）。时间效率越高越好。

13：设计一个算法，找出二叉树上任意两个结点的最近共同父结点。

14：一棵排序二叉树，令 f=(最大值+最小值)/2，设计一个算法，找出距离 f 值最近、大于 f 值的结点。复杂度如果是 O(n2)则不得分。

15：一个整数数列，元素取值可能是 1~N（N 是一个较大的正整数）中的任意一个数，相同数值不会重复出现。设计一个算法，找出数列中符合条件的数对的个数，满足数对中两数的和等于 N+1。复杂度最好是 O(n)，如果是 O(n2)则不得分。



### 谷歌七道面试题

1：有一个由大小写组成的字符串，现在需要对他进行修改，将其中的所有小写字母排在答谢字母的前面（大写或小写字母之间不要求保持原来次序），如有可能尽量选择时间和空间效率高的算法 c 语言函数原型 void proc（char *str） 也可以采用你自己熟悉的语言

2：如何随机选取 1000 个关键字：给定一个数据流，其中包含无穷尽的搜索关键字（比如，人们在谷歌搜索时不断输入的关键字）。如何才能从这个无穷尽的流中随机的选取 1000 个关键字？

3：判断一个自然数是否是某个数的平方，说明：当然不能使用开方运算。

4：给定能随机生成整数 1 到 5 的函数，写出能随机生成整数 1 到 7 的函数。

5：1024! 末尾有多少个 0？

6：有 5 个海盗，按照等级从 5 到 1 排列，最大的海盗有权提议他们如何分享 100 枚金币。

7：但其他人要对此表决，如果多数反对，那他就会被杀死。他应该提出怎样的方案，既让自己拿到尽可能多的金币又不会被杀死？



### 百度三道面试题

1：用 C 语言实现一个 revert 函数，它的功能是将输入的字符串在原串上倒序后返回。

2：用 C 语言实现函数 void * memmove(void *dest, const void *src, size_t n)。memmove，函数的功能是拷贝 src 所指的内存内容前 n 个字节到 dest 所指的地址上。

3：有一根 27 厘米的细木杆，在第 3 厘米、7 厘米、11 厘米、17 厘米、23 厘米这五个位置上各有一只蚂蚁。木杆很细，不能同时通过一只蚂蚁。开始时，蚂蚁的头朝左还是朝右 是任意的，它们只会朝前走或调头，但不会后退。当任意两只蚂蚁碰头时，两只蚂蚁会同时调头朝反方向走。假设蚂蚁们每秒钟可以走一厘米的距离。编写程序，求所有蚂蚁都离开木杆的最小时间和最大时间。



### 腾讯七道面试题

1：请定义一个宏，比较两个数 a、b 的大小，不能使用大于、小于、if 语句

2：两个数相乘，小数点后位数没有限制，请写一个高精度算法

3：有 A、B、C、D 四个人，要在夜里过一座桥。他们通过这座桥分别需要耗时 1、2、5、10 分钟，只有一支手电，并且同时最多只能两个人一起过桥。请问，如何安排，能够在 17分钟内这四个人都过桥？

4：有 12 个小球,外形相同,其中一个小球的质量与其他 11 个不同，给一个天平,问如何用 3 次把这个小球找出来，并且求出这个小球是比其他的轻还是重

5：在一个文件中有 10G 个整数，乱序排列，要求找出中位数。内存限制为 2G。只写出思路即可。

6：一个文件中有 40 亿个整数，每个整数为四个字节，内存为 1GB，写出一个算法：求出这个文件里的整数里不包含的一个整数

7：腾讯服务器每秒有 2w 个 QQ 号同时上线，找出 5min 内重新登入的 qq 号并打印出来。


## 参考

- [名企面试题](https://mp.weixin.qq.com/s?__biz=MzIwNTc4NTEwOQ==&mid=2247485264&idx=1&sn=9d89d36776b0f0711e746e1cc50d2b88&chksm=972ad62aa05d5f3c0cc3a2073bf2ed7d7460fb7aa7686894468e690e403b5f178e036b4ebb9e&scene=0#rd)
- [牛客网面试](https://www.nowcoder.com/ta/coding-interviews)