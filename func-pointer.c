#include<stdio.h>

int callback_test(int a,int b,int c,int (*max)(int,int)) {
	return max(max(a,b),c);
}

int max(int x,int y) {
	return x > y ? x : y;
}

int main(void) {
	int (*p)(int,int) = &max;
	int a = 1, b = 2, c = 3, d;
	d = p(p(a,b),c);
	printf("max:%d\n",d);
	printf("p:%p\tmax:%p\n",p,max);
	printf("callback_test:%d\n",callback_test(a,b,c,p));
	return 0;
}
