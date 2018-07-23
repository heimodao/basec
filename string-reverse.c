#include<stdio.h>

void string_reverse(char str[],int num);
void left_move2right(char str[]);
void string_reverse2(char str[],int num);
void swap(char *p,char *q);
void _string_reverse(char str[],int low,int high);

/**
 * 字符串旋转:
 * abcdef	==> defabc
 */

/**
 * 暴力移动:每次右移一个到字符串尾部
 */
void string_reverse(char str[], int num) {
	while(num-- > 0) {
		left_move2right(str);
	}
}

void left_move2right(char str[]) {
	char t = str[0];
	int i;
	for (i = 1; str[i] != '\0'; i++) {
		str[i - 1] = str[i];
	}
	str[i - 1] = t;
}

/**
 * 将abcdef看做XY
 * 1.x内部翻转 y内部翻转
 * 2.xy整理翻转
 * abcdef => cbafed => defabc
*/
void string_reverse2(char str[], int num) {
	int len;
	for (len = 0; str[len] != '\0'; len++);
	_string_reverse(str, 0, num - 1);
	printf("step1:%s\n", str);
	_string_reverse(str, num, len - 1);
	printf("step2:%s\n", str);
	_string_reverse(str, 0, len - 1);
	printf("step3:%s\n", str);
}

void swap(char *p, char *q) {
	if (*p == *q) {
		return;
	}
	*p = *p ^ *q;
	*q = *p ^ *q;
	*p = *p ^ *q;
}

void _string_reverse(char str[], int low, int high) {
	int mid = (high - low) >> 1;
	int i;
	for (i = 0; i <= mid; i++) {
		swap(&str[low + i], &str[high - i]);
	}
}

int main() {
	char str[7] = "abcdef";
	printf("before:%s\n",str);
	string_reverse(str, 3);
	printf("after:%s\n", str);
	string_reverse2(str,3);
	printf("after2:%s\n", str);
	return 0;
}

