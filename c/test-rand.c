#include<stdio.h>

int gen_random(int min,int max) {
	return (rand() % (max - min + 1)) + min;
}

void test_arr(int arr[]) {
	int i;
	for (i = 0; i < 30; i++) {
		arr[i] = i + 1;
	}
}

void test_arr2(int arr[]) {
	arr[10] = 20;
}

void print_arr(int arr[]) {
	int i;
	for (i = 0; i < 30; i++) {
		printf("%d\t",arr[i]);
		if (i % 10 == 9) {
			printf("\n");
		}
	}
	printf("\n");
}


int main() {
	int i;
	for (i = 0; i < 30; i++) {
		printf("%d:%d\n",i,gen_random(0,53));
	}
	int arr[30];
	test_arr(arr);
	print_arr(arr);
	test_arr2(arr);
	print_arr(arr);
	return 0;
}
