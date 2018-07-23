#include<stdio.h>

int main() {
	enum color_t {RED,GREEN,BLUE};
	int c = RED;
	int *cp = &c;
	printf("step1:%d\n",c);
	printf("step1:%p->%d\n",cp,*cp);
	switch(c) {
		case RED:printf("test1\n");break;
		case GREEN:printf("test2\n");break;
		case BLUE:printf("test3\n");break;
		default : printf("gg\n");
	}
	return 0;
}
