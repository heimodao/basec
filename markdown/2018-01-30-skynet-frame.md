---
layout: post
title: "SKynet框架"
categories: 框架
tags: skynet frame 框架
author: linkzw
---

* content
{:toc}


# skynet学习研究


##	安装skynet
> https://github.com/cloudwu/skynet
> https://github.com/cloudwu/skynet/wiki
> http://blog.csdn.net/column/details/15735.html
> http://blog.csdn.net/119365374/article/details/77790653

	git clone https://github.com/cloudwu/skynet.git
	cd skynet
	make linux 						# make 'PLATFORM'  # PLATFORM can be linux, macosx, freebsd now

## 跑起来
	
	./skynet examples/config	# Launch first skynet node  (Gate server) and a skynet-master (see config for standalone option)
	./3rd/lua/lua examples/client.lua 	# Launch a client, and try to input hello.

## 细究
	
	skynet.timeout(delay,callback) 					-- delay单位是ms
	
## Actor模式
	
	共享内存适用于单机多核的并发变成。
	Actor模式相反，所有的线程（或进程）通过消息传递的方式进行合作，适用于并发编程、多核时代以及分布式系统。
	

	
## 附录

	for key,value in pairs(skynet) do print(key,value) end
	[LB0]	PTYPE_RESPONSE	1
	[LB0]	register	function: 0x7f8e170b8840
	[LB0]	PTYPE_SNAX	11
	[LB0]	endless	function: 0x7f8e170b5840
	[LB0]	abort	function: 0x7f8e170b5870
	[LB0]	exit	function: 0x7f8e17044bd0
	[LB0]	PTYPE_CLIENT	3
	[LB0]	register_protocol	function: 0x7f8e170b8780
	[LB0]	address	function: 0x7f8e170b8c40
	[LB0]	PTYPE_HARBOR	5
	[LB0]	uniqueservice	function: 0x7f8e170b8bc0
	[LB0]	PTYPE_TEXT	0
	[LB0]	getenv	function: 0x7f8e170b53f0
	[LB0]	PTYPE_QUEUE	8
	[LB0]	wakeup	function: 0x7f8e17012080
	[LB0]	init	function: 0x7f8e170b8cc0
	[LB0]	dispatch	function: 0x7f8e170b8b40
	[LB0]	yield	function: 0x7f8e170b5300
	[LB0]	name	function: 0x7f8e170b8880
	[LB0]	timeout	function: 0x7f8e17020b60
	[LB0]	time	function: 0x7f8e170b53c0
	[LB0]	unpack	function: 0x7f8e1709bb00
	[LB0]	rawcall	function: 0x7f8e17012030
	[LB0]	mqlen	function: 0x7f8e170b8d80
	[LB0]	dispatch_unknown_request	function: 0x7f8e170b54e0
	[LB0]	start	function: 0x7f8e17012300
	[LB0]	info_func	function: 0x7f8e170b5b70
	[LB0]	redirect	function: 0x7f8e170b8ac0
	[LB0]	PTYPE_DEBUG	9
	[LB0]	cache	table: 0x7f8e170106e0
	[LB0]	PTYPE_MULTICAST	2
	[LB0]	genid	function: 0x7f8e1709b940
	[LB0]	PTYPE_SOCKET	6
	[LB0]	error	function: 0x7f8e170b8c80
	[LB0]	starttime	function: 0x7f8e170b89c0
	[LB0]	forward_type	function: 0x7f8e170123a0
	[LB0]	PTYPE_ERROR	7
	[LB0]	tostring	function: 0x7f8e1709ba40
	[LB0]	retpack	function: 0x7f8e170b54b0
	[LB0]	dispatch_unknown_response	function: 0x7f8e170b5570
	[LB0]	harbor	function: 0x7f8e170b56f0
	[LB0]	PTYPE_LUA	10
	[LB0]	launch	function: 0x7f8e170b8940
	[LB0]	pack	function: 0x7f8e1709bac0
	[LB0]	kill	function: 0x7f8e170b8a00
	[LB0]	packstring	function: 0x7f8e1709bb40
	[LB0]	term	function: 0x7f8e170b58a0
	[LB0]	newservice	function: 0x7f8e170b56c0
	[LB0]	response	function: 0x7f8e170b8b00
	[LB0]	PTYPE_SYSTEM	4
	[LB0]	ret	function: 0x7f8e170b5480
	[LB0]	tcall	function: 0x7f8e170c5d00
	[LB0]	filter	function: 0x7f8e17012350
	[LB0]	fork	function: 0x7f8e17012120
	[LB0]	now	function: 0x7f8e170b8980
	[LB0]	setenv	function: 0x7f8e170b5420
	[LB0]	task	function: 0x7f8e170b8dc0
	[LB0]	wait	function: 0x7f8e17011f40
	[LB0]	self	function: 0x7f8e170b88c0
	[LB0]	localname	function: 0x7f8e170b8900
	[LB0]	sleep	function: 0x7f8e17020bc0
	[LB0]	queryservice	function: 0x7f8e170b8c00
	[LB0]	send	function: 0x7f8e170b8a40
	[LB0]	monitor	function: 0x7f8e170123f0
	[LB0]	call	function: 0x7f8e17011fe0
	[LB0]	queue	function: 0x7f8e171b6d20
	[LB0]	rawsend	function: 0x7f8e170b8a80
	[LB0]	reducepool	function: 0x7f8e170b8e00
