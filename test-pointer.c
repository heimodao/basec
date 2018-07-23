#include<stdio.h>

int main() {
	int i = 20;
	int *p = &i;
	printf("i:%d\ti_add:%p\tp:%d\tp_addr:%p\n",i,&i,*p,p);
	*p = 19;
	int c = *p;
	printf("i:%d\ti_add:%p\tp:%d\tp_addr:%p\n",i,&i,*p,p);
	printf("c:%d\tc_addr:%p\n",c,&c);
	return 0;
}
