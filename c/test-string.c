#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXSIZE 256

void string_test();
int getlen_str(char *str);
void cpystr2letter(char str[],char *arr[]);
int getlen_char(char *str);
void string_test2();

// 从键盘读入含有文本的字符串 按照单词字母数顺序输出文本中所有单词
int main() {
	string_test();
	return 0;
}

// string_test
void string_test() {
	char buffer[MAXSIZE];
	gets(buffer);
	if (buffer[0] == '\0') {
		printf("\nError Reading String.\n");
		exit(1);
	}
	int letter_num = getlen_str(buffer);
	char *arr[letter_num];
	cpystr2letter(buffer,arr);
	int i,j;
	int sort[letter_num],len[letter_num];
	for (i = 0; i < letter_num; i++) {
		len[i] = getlen_char(arr[i]);
		sort[i] = i;
		if (i > 0 && sort[i] > sort[i - 1]) {
			int temp = i;
			for (j = i; j > 0 && len[temp] > len[sort[j - 1]]; j--) {
				sort[j] = sort[j - 1];
			}
			sort[j + 1] = temp;
		}
	}
	for (i = 0; i < letter_num; i++) {
		printf("%d:%s\n",i,arr[i]);
	}

	printf("\n----end-----\n\n");
}

// getnum_letter
int getlen_str(char *str) {
	int count = 0,i;
	for (i = 0; *(str + i) != '\0'; i++) {
		if (*(str + i) == ' ') {
			count++;
		}
	}
	return count;
}

// strcpy
void cpystr2letter(char str[],char *arr[]) {
	int count = 0,last = 0,i;
	for (i = 0; str[i] != '\0'; i++) {
		if (str[i] != '\0') {
			*(arr[count] + i - last -1) = str[i];
		} else {
			*(arr[count] + i - last -1) = '\0';
			last = i;
			count++;
		}
	}
}

// getlen
int getlen_char(char *str) {
	int len;
	for (len = 0; *(str + len) != '\0'; len++);
	return len;
}




