#include<stdio.h>
#include<stdlib.h>

char* ret_array(int len) {
	char *test = (char *)malloc((len + 1) * sizeof(char));
	if (test == NULL) {
		printf("Can\'t creat char point!");
		exit(0);
	}
	int i;
	for (i = 0; i < len; i++) {
		*(test + i) = 'a';
	}
	return test;
}

int main() {
	char *test = ret_array(10);
	int i;
	for (i = 0; i < 10; i++) {
		printf("%c",*(test + i));
	}
	printf("\n");
	return 0;
}
