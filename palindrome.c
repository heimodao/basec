#include<stdio.h>

int ispalindrome(const char *str) {
	int len;
	for (len = 0; *(str + len) != '\0'; len++);
	int left = 0, right = len - 1;
	while(left < right && *(str + left++) == *(str + right--));
	if (left < right) {
		return 0;
	}
	return 1;
}

int ispalindrome_mid(const char *str) {
	int len;
	for (len = 0; *(str + len) != '\0'; len++);
	int mid = (len - 1) >> 1;
	mid = (mid >= 0) ? mid : 0;
	int first = mid;
	int second = len - 1 - mid;
	while(first >= 0 && (*(str + second) != '\0')) {
		if (*(str + first++) != *(str + second++)) {
			return 0;
		}
	}
	return 1;
}

int main() {
	char str[] = "abcdef";
	char str2[] = "abcdefedcba";
	char str3[] = "a123454321a";
	printf("------method1-------\n");
	printf("%s是否是回文%d\n",str,ispalindrome(str));
	printf("%s是否是回文%d\n",str2,ispalindrome(str2));
	printf("%s是否是回文%d\n",str3,ispalindrome(str3));
	printf("------method2-------\n");
	printf("%s是否是回文%d\n",str,ispalindrome_mid(str));
	printf("%s是否是回文%d\n",str2,ispalindrome_mid(str2));
	printf("%s是否是回文%d\n",str3,ispalindrome_mid(str3));

	return 0;
}
