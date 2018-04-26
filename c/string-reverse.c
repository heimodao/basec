#include<stdio.h>

/**
 * 字符串旋转:
 * abcdef	==> defabc
 */

/**
 * 暴力移动:每次右移一个到字符串尾部
 */
void string_reverse(char str[], int num) {
	while(num-- > 0) {
		left_remove2tail(str);
	}
}

void left_remove2tail(char str[]) {
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
	int len = 0;
	_string_reverse(str, 0, num - 1);
	_string_reverse(str, num, len - 1);
	_string_reverse(str, 0, len - 1);
}

void _string_reverse(char str[], int low, int high) {

}

int main() {
	char str[7] = "abcdef";
	printf("before:%s\n",str);
	string_reverse(str, 3);
	printf("after:%s\n", str);
	return 0;
}












