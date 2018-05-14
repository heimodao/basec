#include<stdio.h>

int longest_palindrome(char *str) {
	int i,len,max = 1;
	for (len = 0; *(str + len) != '\0'; len++);
	for (i = 0; i < len; i++) {
		int left = -1,right = -1,len_temp;
		if (i < len - 1 && (*(str + i) == *(str + i + 1))) {
			left = i;
			right = i + 1;
			len_temp = 0;
		} else if (i > 0 && (*(str + i - 1) == *(str + i + 1))) {
			left = i - 1;
			right = i + 1;
			len_temp = 1;
		}
		while(left >= 0 && right < len && (*(str + left--) == *(str + right++))) {
			len_temp += 2;
		}
		max = (len_temp > max) ? len_temp : max;
	}
	return max;
}

int main() {
	char str[] = "12212321";
	printf("%s最长回文子串长度%d\n",str,longest_palindrome(str));
	return 0;
}
