#include<stdio.h>

int max (int x, int y) {
	return x > y ? x : y;
}

int main(void) {
	int a = 10, b = 20, c = 30;
	int (*p)(int x, int y) = &max;
	printf("x=%d, y=%d, z=%d, max=%d\n", a, b, c, p(p(a,b), c));
	return 0;
}
