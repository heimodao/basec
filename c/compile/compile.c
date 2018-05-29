#include<stdio.h>

#include "test.h"

// compile: gcc test.c main.c
int main() {
	welcome("编译多个程序");
	int a = 10,b = 20;
	printf("a:%d\tb:%d\ta+b:%d\n",a,b,add(a,b));
	return 0;
}
