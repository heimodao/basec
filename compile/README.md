# gcc编译多个文件

main.c调用test.c中函数

	参考示例:[test.h](test.h) [test.c](test.c) [compile.c](compile.c)
	gcc test.c compile.c -o output.o

# gcc编译静态库

	gcc -Wall -o2 -fPIC -I./ -c -o test.o test.c	# 输出test.o
	ar crv libtest.a test.o		# 输出libtest.a静态文件
	gcc static_lib.c ./libtest.a	# 编译

	ar参数
	-r		将objfile文件插入静态库尾或者替换静态库中同名文件
	-x		从静态库文件中抽取文件objfile
	-t		打印静态库的成员文件列表
	-d		从静态库中删除文件objfile
	-s		重置静态库文件索引
	-v		创建文件冗余信息
	-c		创建静态库文件

# gcc编译动态库

	method1:
	gcc -o2 -fPIC -shared test.c -o libtest.so

	method2:
	gcc -o2 -fPIC -c test.c
	gcc -shared -o libtest.so test.o
	
	gcc -o2 -Wall -L. -ltest main.c

## 找不到动态库

* 方法一 修改环境变量

	export LD_LIBRARY_PATH=$(pwd):$LD_LIBRARY_PATH

* 方法二 将库文件链接到系统目录下

	ln -s ./libwelcome.so /usr/lib

* 方法三 修改/etc/ld.so.conf

	sudo echo $(pwd) >> /etc/ld.so.conf
	sudo ldconfig

# 多线程

	gcc test.c -lpthread
