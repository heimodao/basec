#include<stdio.h>

#define MINSIZESEQUENCE 2

int _sum(int num, int size) {
	int i, sum = 0;
	for (i = 0; i < size; i++) {
		sum = sum + num++;
	}
	return sum;
}

void _print(int num, int size) {
	int i;
	for (i = 0; i < size; i++) {
		printf("%d\t", num + i);
	}
	printf("\n");
}

// 寻找连续正数和为sum的序列
void find_continuou_sequence(int sum) {
	int i,j;
	int count = 1;
	int maxsize = (sum >> 1) + 1;
	for (i = 1; i <= sum; i++) {
		int tempsum;
		for (j = MINSIZESEQUENCE; j <= maxsize && (tempsum = _sum(i, j)) < sum; j++);
		if (tempsum == sum) {
			printf("第%d种方案:\t",count++);
			_print(i, j);
		}
	}
}

int main() {
	int sum;
	printf("请输入sum:");
	scanf("%d", &sum);
	find_continuou_sequence(sum);
}
