# algorithm

> 学习过程中的算法知识总结

> [博客](https://blog.linkzw.com) 


# [基础结构](https://github.com/wenruo95/algorithm/blob/master/ds)

## 链表、栈、队列
	
链表实现栈和链表实现队列本质上是一样的，栈是后进先出，队列是先进先出。假设出栈都是从头出，那么栈采取头插，队列采取遍历到尾部插入。至于初始化、出栈、释放都是一样的。可以参照二叉树深度优先和广度优先对队列的简单实现[参考链接](https://github.com/wenruo95/algorithm/blob/master/c/tree.c) 。
	

- [x] [链表反转](https://github.com/wenruo95/algorithm/blob/master/c/link-reverse.c)
- [x] [链表实现栈](https://github.com/wenruo95/algorithm/blob/master/c/stack-link.c)
- [x] [链表实现队列](https://github.com/wenruo95/algorithm/blob/master/c/queue-link.c)
- [x] [双向链表](https://github.com/wenruo95/algorithm/blob/master/c/double-link.c)

## 哈希表/散列表 (Hash Table)

- [ ] 散列函数
- [ ] 碰撞解决


## 树

- [x] [二叉树、先序遍历、中序遍历、后序遍历、深度优先、广度优先](https://github.com/wenruo95/algorithm/blob/master/c/tree.c) 
- [x] [二叉查找树](https://github.com/wenruo95/algorithm/blob/master/c/search-binary-tree.c)  
- [ ] [红黑树](https://github.com/wenruo95/algorithm/blob/master/c/red-black-tree.c)  
- [ ] [斐波那契堆(Fibonacci Heap)]() 


## 图

- [ ] A Star算法
- [ ] 图的存储结构和基本操作（建立，遍历，删除节点，添加节点）   
- [ ] 最小生成树  
- [ ] 拓扑排序  
- [ ] 关键路径 
- [ ] [最小生成树==>Dijkstra]()
- [ ] [最小生成树==>Floyd]() 
- [ ] 最短路径: Floyd,Dijkstra,bellman-ford,spfa
- [ ] 图搜索: 深度优先(DFS)、广度优先(BFS)

# 算法

## 排序 <=> [C](https://github.com/wenruo95/algorithm/blob/master/c/sort.c)

- [x] 1.直接插入排序				
- [x] 2.折半插入排序						
- [x] 3.希尔排序
- [x] 4.简单选择排序					
- [x] [5.堆排序](https://github.com/wenruo95/algorithm/blob/master/c/tree.c) ==> 中序遍历即为升序
- [x] 6.冒泡排序
- [x] 7.快速排序
- [x] 8.归并排序递归版、迭代版

- [ ] 9.基数排序	
- [ ] 10.计数排序
- [ ] 11.桶排序


## 字符串

- [x] [字符串旋转](https://github.com/wenruo95/algorithm/blob/master/c/string-reverse.c)
- [ ] [字符串匹配(BF、BM、KMP)](https://github.com/wenruo95/algorithm/blob/master/c/kmp.c)
- [x] [交替字符串](https://github.com/julycoding/The-Art-Of-Programming-By-July/issues/460)
- [ ] [正则表达式](https://github.com/wenruo95/algorithm/blob/master/c/regexp-match.c)
- [ ] 数据压缩



## 动态规划、贪心算法

- [ ] 背包问题 [C](https://github.com/wenruo95/algorithm/blog/master/c/knapsack.c)


## 常用算法

- [x] [和为S的连续正数序列](https://github.com/wenruo95/algorithm/blob/master/find-continuous-sequence.c)
- [x] [汉诺塔问题](https://github.com/wenruo95/algorithm/blob/master/c/hannuota.c)
- [ ] [字符串反转](https://github.com/wenruo95/algorithm/blob/master/c/algo-string.c)
- [x] [求质数更高效方法](https://github.com/wenruo95/algorithm/blob/master/c/prime-number.c)
- [x] [大整数乘法](https://github.com/wenruo95/algorithm/blob/master/lua/bigint-multipli.lua)
- [x] [费波那契数列](https://github.com/wenruo95/algorithm/blob/master/lua/fibonacci.lua)
- [x] [各类hash算法整理](https://github.com/wenruo95/algorithm/blob/master/c/hash.c) [Test](https://github.com/wenruo95/algorithm/blob/master/c/hashtest.c)
- [x] [八皇后问题](https://github.com/wenruo95/algorithm/blob/master/c/eight-queen.lua):有点问题后续需要修改
- [x] [全排列、部分排列](https://github.com/wenruo95/algorithm/blob/master/c/permutation.c)


## 海量数据处理方式

	* 分而治之/hash映射 + hash统计 + 堆/快速/归并排序；
	* 双层桶划分
	* Bloom filter(布隆过滤器)/Bitmap(位图)；
	* Trie树/数据库/Inverted Index(倒排索引)；
	* 外排序；
	* 分布式处理之Hadoop/MapReduce。
	* simhash框架


- [ ] 1.哈希分治；
- [ ] 2.simhash算法
- [ ] 3.外排序
- [ ] MapReduce
- [ ] 多层划分
- [ ] 位图
- [ ] Bloom filter布隆过滤器
- [ ] Trie树
- [ ] 数据库；
- [ ] 10.倒排索引


# 其他

## 小工具

- [x] [简单随机数生成验证](https://github.com/wenruo95/algorithm/blob/master/lua/randcode.lua)
- [x] [微信通讯录导出](https://github.com/wenruo95/algorithm/blob/master/lua/name-email.lua) [Output](https://github.com/wenruo95/algorithm/blob/master/lua/contacts.txt)
- [x] [根据文件生成git url地址导航](https://github.com/wenruo95/algorithm/blob/master/lua/giturl.lua) [Input](https://github.com/wenruo95/algorithm/blob/master/lua/filename.lua)
- [x] [c静态库动态库编译](https://github.com/wenruo95/algorithm/tree/master/c/compile)

## 博文详述

- [x] [算法](https://blog.linkzw.com/2018/01/29/algorithms/)

 
