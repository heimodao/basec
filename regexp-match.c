#include<stdio.h>
#include<stdbool.h>

// rugular:
// . 表示任意一个字符
// * 表示前面的字符和可以出现任意次(包括0次)
// str		pattern		return
// aaa		a.a			true
// aaa		ab*ac*c		true
// aaa		aa.a		false
// aaa		ab*a		false
bool regexp_match(char *str, char *pattern) {

	return true;
}

int main(void) {
	char *str = "aaa";
	char *pattern[4] = {"a.a", "ab*ac*c", "aa.a", "ab*a"};
	int i;
	for (i = 0; i < 4; i++) {
		bool ret = regexp_match(str,pattern[i]);
		printf("str:%s\tpattern:%s\tispattern:%d\n", str, pattern[i], ret);
	}
	return 0;
}
