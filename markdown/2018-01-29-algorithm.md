关于项目，我出两个练手题目：

	一、多机数据处理。有 10 台机器，每台机器上保存着 10 亿个 64-bit 整数（不一定刚好 10 亿个，可能有上下几千万的浮动），一共约 100 亿个整数（其实一共也就 80GB 数据，不算大，选这个量级是考虑了 VPS 虚拟机的容量，便于实验）。

	编程求出：
	1. 这些数的平均数。
	2. 这些数的中位数。
	3. 出现次数最多的 100 万个数。
	*4. （附加题）对这 100 亿个整数排序，结果顺序存放到这 10 台机器上。
	*5. （附加健壮性要求）你的程序应该能正确应对输入数据的各种分布（均匀、正态、Zipf）。
	*6. （附加伸缩性要求）你的程序应该能平滑扩展到更多的机器，支持更大的数据量。比如 20 台机器、一共 200 亿个整数，或者 50 台机器、一共 500 亿个整数。
 


 	二、N-皇后问题的多机并行求解。利用多台机器求出 N-皇后问题有多少个解。（注意目前的世界纪录是 N = 26，A000170 - OEIS ）
 	1. 8 皇后问题在单机上的运算时间是毫秒级，有 92 个解，编程实现之。
 	2. 研究 N-皇后问题的并行算法，写一个单机多线程程序，争取达到线性加速比（以 CPU 核数计）。再设法将算法扩展到多机并行。
 	3. 用 10 台 8 核的机器（一共 80 个 CPU cores），求解 19-皇后和 20-皇后问题，看看分别需要多少运行时间。你的方案能否平滑扩展到更多的机器？
 	*4. （附加题）如果这 10 台机器的型号不一，有 8 核也有 16 核，有旧 CPU 也有更快的新 CPU，你该采用何种负载均衡策略，以求缩短求解问题的时间（至少比 plain round-robin 算法要好）？你可以用 Amazon EC2 或 Google GCE 来验证你的程序的正确性和性能，这两家的虚拟机都是按小时（甚至更短）收费，开 10 台虚拟机做一个下午的实验也花不了多少钱。
 