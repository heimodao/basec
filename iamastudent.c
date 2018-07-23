#include<stdio.h>

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

void string_reverse(char str[]) {
	int len;
	int begin = 0;
	// 断词、单句翻转、整句翻转
	for (len = 0; str[len] != '\0'; len++) {
		if (str[len] == ' ') {
			_string_reverse(str,begin,len - 1);
			begin = len + 1;
		}
	}
	_string_reverse(str,begin,len - 1);
	_string_reverse(str,0,len - 1);
}

int main() {
	char str[] = "i am a student.";
	string_reverse(str);
	printf("%s\n",str);
	return 0;
}
