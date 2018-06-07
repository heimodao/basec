---
layout: post
title: "树的介绍及应用"
categories: 算法
tags: Algorithm Tree
author: linkzw
---

* content
{:toc}

## [深度优先、广度优先实现](https://github.com/wenruo95/algorithm/blob/master/c/tree.c) 

## 二叉树
> 二叉查找树（BST） 笛卡尔树 MVP树 Top tree T树

深度为K的二叉树至多总共有2^(K+1) - 1个节点数，根节点深度为0
满二叉树(Full Binary Tree): 一棵深度为k，且有2^(K+1) - 1个节点的二叉树
完全二叉树(Complete Binary Tree):在一棵二叉树中，除最后一层外，若其余层都是满的，并且最后一层或者是满的，或者是在右边缺少连续若干节点.

具有n个节点的完全二叉树的深度为log2(n) + 1。深度为k的完全二叉树，至少有2^k个节点，至多有2^(k+1) - 1个节点


将一棵树转换为二叉树的方法：
	在兄弟之间加一连接；
	对每个结点，除了其左孩子外，去除其与其余孩子之间的联系；
	以树的根结点为轴心，将整树顺时针转45度。


## 自平衡二叉查找树	
> AA树 AVL树 左倾红黑树 红黑树 替罪羊树 伸展树 树堆 加权平衡树

### 红黑树
	红黑树是每个节点都带有颜色属性的二叉查找树，颜色为红色或黑色。在二叉查找树强制一般要求以外，对于任何有效的红黑树我们增加了如下的额外要求：

	1).节点是红色或黑色。
	2).根是黑色。
	3).所有叶子都是黑色（叶子是NIL节点）。
	4).每个红色节点必须有两个黑色的子节点。（从每个叶子到根的所有路径上不能有两个连续的红色节点。）
	5).从任一节点到其每个叶子的所有简单路径都包含相同数目的黑色节点。

## B树	

> B+树 B\*树 Bx树 UB树 2-3树 2-3-4树 (a,b)-树 Dancing tree H树


## 堆	
> 二叉堆 二项堆 斐波那契堆 左偏树 Pairing heap 斜堆 Van Emde Boas tree

## Trie	
> 后缀树 基数树 三叉查找树 X-快速前缀树 Y-快速前缀树

## 二叉空间分区（BSP）树	
> 四叉树 八叉树 k-d树 隐式k-d树 VP树

## 非二叉树	
>指数树 融合树 区间树 PQ树 Range tree SPQR树

## 空间数据分区树	
>R树 R\*树 R+树 X树 M树 线段树 希尔伯特R树 优先R树

## 其他树	
> 散列日历 散列树 Finger tree Order statistic tree Metric tree Cover tree BK树 Doubly chained tree iDistance Link-cut tree Log-structured merge-tree 树状数组



## 参考链接

[2-3树和红黑树](https://riteme.github.io/blog/2016-3-12/2-3-tree-and-red-black-tree.html)
