#include<stdio.h>

int sum_solution(int n) {
	int sum = n;
	sum && (sum += sum_solution(n - 1));
	return sum;
}

int add(int a, int b) {
	while(b != 0) {
		int sum = a ^ b;
		b = (a & b) << 1;
		a = sum;
	}
	return a;
}

int main() {
	int i;
	for (i = 1; i < 100; i++) {
		//printf("n:%d\tsum:%d\n", i, sum_solution(i));
		printf("a:%d\tb:%d\tsum:%d\n", i, 2 * i + 1, add(i, 2 * i + 1));
	}
	return 0;
}
