#include<stdio.h>
#include<stdlib.h>

// 冒泡修改版，交替扫描,第一趟排序关键最大的放后面，最小的放前面

void swap(int *a, int *b) {
	*a = (*a) ^ (*b);
	*b = (*a) ^ (*b);
	*a = (*a) ^ (*b);
}

int main(void) {
	int keys[] = {1, 5, 8, 10, 20, 18, 22};
	unsigned int size = sizeof(keys) / sizeof(keys[0]);
	int left = 0, right = size -1;
	while (left < right) {
		int min_pos = left, max_pos = right;
		//
		for (int i = left; i < right; i++) {
			if (keys[i] > keys[i + 1]) {
				swap(&keys[i], &keys[i + 1]);
			}
		}
		//
		for (int i = right - 1; i > left; i--) {
			if (keys[i - 1] > keys[i]) {
				swap(&keys[i - 1], &keys[i]);
			}
		}
		left++;
		right--;
	}

	printf("after:\n");
	for (int i = 0; i < size; i++) {
		printf("%d\t", keys[i]);
	}
	printf("\n");

}
