## select/poll/epoll模型
	
	- 阻塞 I/O（blocking IO）
	- 非阻塞 I/O（nonblocking IO）
	- I/O 多路复用（ IO multiplexing）
	- 信号驱动 I/O（ signal driven IO）
	- 异步 I/O（asynchronous IO）

	注：由于signal driven IO在实际中并不常用，所以我这只提及剩下的四种IO Model。

## MapReduce

## ProtoBuf

## Spark

## Hadoop

## dubbo

## 创建者/消费者模型

生产者消费者问题（英语：Producer-consumer problem）,也称有限缓冲问题（英语：Bounded-buffer problem），是一个多线程同步问题的经典案例。

	该问题描述了共享固定大小缓冲区的两个线程——即所谓的“生产者”和“消费者”——在实际运行时会发生的问题。
	生产者的主要作用是生成一定量的数据放到缓冲区中，然后重复此过程。与此同时，消费者也在缓冲区消耗这些数据。
	该问题的关键就是要保证生产者不会在缓冲区满时加入数据，消费者也不会在缓冲区中空时消耗数据。

解决方法:

	要解决该问题，就必须让生产者在缓冲区满时休眠（要么干脆就放弃数据），等到下次消费者消耗缓冲区中的数据的时候，生产者才能被唤醒，开始往缓冲区添加数据。
	同样，也可以让消费者在缓冲区空时进入休眠，等到生产者往缓冲区添加数据之后，再唤醒消费者。
	通常采用进程间通信的方法解决该问题，常用的方法有信号灯法等。
	如果解决方法不够完善，则容易出现活锁的情况。出现死锁时，两个线程都会陷入休眠，等待对方唤醒自己。该问题也能被推广到多个生产者和消费者的情形。

## 正则匹配

> https://c.runoob.com/front-end/854

	^(?!commit_by_shell).*$									<=> 过滤掉commit_by_shell
	(baidu|ali|tencent)										<=> 匹配baidu、ali、tencent

## Lua5.3

> [目录](http://cloudwu.github.io/lua53doc/contents.html)


> [内容](http://cloudwu.github.io/lua53doc/manual.html)

## lua语法静态检查
	
	luacheck
	sudo apt-get install luarocks
	luarocks install luacheck
	luacheck --config .luacheckrc ../src/gamelogic/* > /tmp/luacheck.log
	luacheck /home/nomogaserver/gamesrv_3/src/gamelogic/* > /tmp/luacheck.log

## 动态规划、贪婪算法、NP完全

贪婪算法：解决最优化的问题。

	因为用贪心算法只能通过解局部最优解的策略来达到全局最优解，因此，一定要注意判断问题是否适合采用贪心算法策略，找到的解是否一定是问题的最优解。

	1. 建立数学模型来描述问题。
	2. 把求解的问题分成若干个子问题。
	3. 对每一子问题求解，得到子问题的局部最优解。
	4. 把子问题的解局部最优解合成原来解问题的一个解。

	对于大部分的问题，贪心法通常都不能找出最佳解（不过也有例外），因为他们一般没有测试所有可能的解。贪心法容易过早做决定，因而没法达到最佳解。例如，所有对图着色问题。
	贪心法在系统故障诊断策略生成乃至高校的排课系统中都可使用。


动态规划(Dynamic programming，简称DP)：

	通过把原问题分解为相对简单的子问题的方式求解复杂问题的方法。
	动态规划常常适用于有重叠子问题和最优子结构性质的问题，动态规划方法所耗时间往往远少于朴素解法。
	动态规划在查找有很多重叠子问题的情况的最优解时有效。它将问题重新组合成子问题。
	为了避免多次解决这些子问题，它们的结果都逐渐被计算并被保存，从简单的问题直到整个问题都被解决。因此，动态规划保存递归时的结果，因而不会在解决同样的问题时花费时间。

	动态规划只能应用于有最优子结构的问题。最
	优子结构的意思是局部最优解能决定全局最优解（对有些问题这个要求并不能完全满足，故有时需要引入一定的近似）。简单地说，问题能够分解成子问题来解决。
	

## telnet退出

	ctrl + ]
	quit
	
	

	
	
	
	
