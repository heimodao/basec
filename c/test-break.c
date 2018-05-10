#include<stdio.h>

int main(void) {
	int count = 0;
	int i = 10;
	while (i > 0) {
		printf("%d\tbreak-first:%d\n", ++count, i--);
		int j = 10;
		while(j > 0) {
			if (j == 5) {
				break;
			}
			printf("%d\tbreak-second:%d\n", ++count, j--);
		}
	}
	int index;
	for (index = 0; index < 10;index++) {
		printf("%d\t",index);
	}
	printf("\n%d",index);
}
