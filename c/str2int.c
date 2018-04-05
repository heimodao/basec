#include<stdio.h>

int str2int(char[] str) {
	int length = sizeof(str) / sizeof(char) - 1;
	int index = 1;
	int sign = 0;// 0为正 1为负
	for (i = 0; i < length; i++) {
		if (str[i] < '0' && str[i] >= '9') {
			if (i == 0 && (str[i] == '+' or str[i] == '-')) {
				sign = (str[i] == '+') ? 0 : 1;
			} else {
				return 0;
			}
		} else {
			index = index * 10 + (str[i] - '0');
		}
	}
	return (sign == 0) ? index : -index;
}

int main() {
	return 0;
}
