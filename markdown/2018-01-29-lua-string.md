Lua String
http://mobile.51cto.com/iphone-285815.htm


	string.len(str)          							-- 返回字符串s的长度；
	string.rep(str, n)     								-- 返回重复n次字符串s的串；你使用string.rep("a", 2^20)可以创建一个1M bytes的字符串（比如，为了测试需要）；
	string.lower(str)       							-- 将s中的大写字母转换成小写（string.upper将小写转换成大写）。
	string.upper(str)       							-- 将s中的小写字母转换成大写	                              
	string.sub(str,i,j)      							-- 函数截取字符串s的从第i个字符到第j个字符之间的串。
	string.reverse(str)									-- 字符串反转
	string.format(...)									-- 返回一个类似printf的格式化字符串
	string.char(arg) 和 string.byte(arg[,int])			-- char 将整型数字转成字符并连接， byte 转换字符为整数值(可以指定某个字符，默认第一个字符)。

	string.find(str, pattern, init, plain)  			-- 字符串查找
	string.gsub(str, pattern, repl, n)					-- 全局字符串替换
	string.gfind(str, pattern, init, plain) 			-- 全局字符串查找
	string.gmatch(str, pattern) 						-- 返回查找到字符串的迭代器
	string.match(str, pattern, init)  					-- string.match()只寻找源字串str中的第一个配对. 参数init可选, 指定搜寻过程的起点, 默认为1.



	.(点): 与任何字符配对  
	%a: 与任何字母配对  
	%c: 与任何控制符配对(例如\n)  
	%d: 与任何数字配对  
	%l: 与任何小写字母配对  
	%p: 与任何标点(punctuation)配对  
	%s: 与空白字符配对  
	%u: 与任何大写字母配对  
	%w: 与任何字母/数字配对  
	%x: 与任何十六进制数配对  
	%z: 与任何代表0的字符配对  
	%x(此处x是非字母非数字字符): 与字符x配对. 主要用来处理表达式中有功能的字符(^$()%.[]*+-?)的配对问题, 例如%%与%配对 


	+      匹配前一字符1次或多次  
	*      匹配前一字符0次或多次  
	-      匹配前一字符0次或多次  
	?      匹配前一字符0次或1次 

	以 '^' 开头的模式只匹配目标串的开始部分，相似的，以 '$' 结尾的模式只匹配目标串的结尾


	'%b' 用来匹配对称的字符。常写为 '%bxy' ，x和y是任意两个不同的字符；x作为匹配的开始，y作为匹配的结束。比如，'%b()' 匹配以 '(' 开始，以 ')' 结束的字符串：


	