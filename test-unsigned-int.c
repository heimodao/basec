#include<stdio.h>

int main(void) {
	int i = -2;
	unsigned int j = 1;
	printf("%d + %d = %d\n",i,j,i+j);
	if ((i + j) >= 0) {
		printf("i + j >= 0\n");
	} else {
		printf("i + j < 0\n");
	}
	return 0;
}
