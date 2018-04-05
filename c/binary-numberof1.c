/*
 * 二进制中1的个数
 * https://www.nowcoder.com/practice/8ee967e43c2c4ec193b040ea7fbb10b8?tpId=13&tqId=11164&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
*/
#include<stdio.h>

int numberof1(int n) {
	int count = 0;
	while (n != 0) {
		n = n & (n - 1);
		count++;
	}
	return count;
}

int main() {
	int i;
	for (i = -10; i <= 10; i++) {
		printf("%d : %d\n", i, numberof1(i));
	}
}
