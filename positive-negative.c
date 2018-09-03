#include<stdio.h>

void swap(int *a, int *b) {
	*a = (*a) ^ (*b);
	*b = (*a) ^ (*b);
	*a = (*a) ^ (*b);
}

// 将所有负数放到证书后面
int main(void) {
	int arrs[] = {10, -20, -25, -30, 20, 45,50};
	int size = sizeof(arrs) / sizeof(arrs[0]);
	int left = 0; int right = size - 1;
	while (left < right) {
		// 从左开始寻找负数 放到right位置
		int pos;
		for (pos = left; pos <= right && arrs[pos] > 0; pos++);
		swap(&arrs[pos], &arrs[right]);
		left = pos + 1;
		right = right - 1;
	}

	printf("after:\n");
	for (int i = 0; i < size; i++) {
		printf("%d\t", arrs[i]);
	}
	printf("\n");

	return 0;
}
