#include<stdio.h>

int string_contain(char *a,char *b);

// a: 长字符串 b:短字符串
// 1.暴力扫描
int string_contain(char *a,char *b) {
	int i,j;
	for (i = 0; *(b + i) != '\0';i++) {
		for (j = 0; *(a + j) != '\0' && *(a + j) != *(b + i);j++);
		if (*(a + j) == '\0') {
			return 0;
		}
	}
	return 1;
}

// 2.排序后线性扫描
int string_contain_2(char *a,char *b) {
	// sort a
	// sort b
	int i = 0,j = 0;
	while(*(a + i) != '\0' && *(b + j) != '\0') {
		int pos = *(a + i) - *(b + j);
		if (pos == 0) {
			i++;
		} else if (pos > 0) {
			j++;
		} else {
			return 0;
		}
	}
	if (*(a + i) == '\0') {
		return 1;
	}
	return 0;
}

// 3.素数相乘 有溢出风险
int string_contain_3(char *a,char *b) {
	int i,j;
	int count = 0;
	int arr[26];
	// 26个素数
	for (i = 2; count <= 26; i++) {
		for (j = 2; j * j <= i; j++) {
			if (i % j == 0) {
				break;
			}
		}
		if (j * j > i) {
			arr[count++] = i;
		}
	}
	// 素数相乘
	int sum = 1;
	for (i = 0; *(a + i) != '\0'; i++) {
		int pos = *(a + i) - 'A';
		sum *= arr[pos];
	}
	for (j = 0; *(b + j) != '\0'; j++) {
		int pos = *(b + j) - 'A';
		if (sum % arr[pos] != 0) {
			return 0;
		}
	}
	return 1;
}

// 4.hashtable
int string_contain_4(char *a,char *b) {
	int hash = 0;
	int i,j;
	for (i = 0; *(a + i) != '\0'; i++) {
		hash |= (1 << (*(a + i) - 'A'));
	}
	for (j = 0; *(b + j) != '\0'; j++) {
		if ((hash & (1 << (*(b + j) - 'A'))) == 0) {
			return 0;
		}
	}
	return 1;
}

// 兄弟字符串: 字符一样，顺序不一样
// 解决思路：在确保不溢出的情况下使用素数相乘
// 最佳方法:使用之前的hashtable方法，只在意是否包含这个数据不在意数据 
int brother_string(char *a,char *b) {

}

int main() {
	char str[] = "ZENGWIAHUPSLC";
	char str1[] = "ABC";
	char str2[] = "ANG";
	char str3[] = "HUAP";
	// 暴力扫描
	printf("-----------暴力扫描----------\n");
	printf("A:%s\tB:%s\tresult:%d\n",str,str1,string_contain(str,str1));
	printf("A:%s\tB:%s\tresult:%d\n",str,str2,string_contain(str,str2));
	printf("A:%s\tB:%s\tresult:%d\n",str,str3,string_contain(str,str3));
	// 排序扫描
	printf("-----------排序扫描----------\n");
	char str4[] = "ABCDEFGH";
	printf("A:%s\tB:%s\tresult:%d\n",str4,str1,string_contain_2(str4,str1));
	// sort
	printf("-----------素数相乘----------\n");
	char str5[] = "AGH";
	printf("A:%s\tB:%s\tresult:%d\n",str4,str1,string_contain_3(str4,str1));
	printf("A:%s\tB:%s\tresult:%d\n",str4,str5,string_contain_3(str4,str5));
	// hash
	printf("-----------哈希----------\n");
	printf("A:%s\tB:%s\tresult:%d\n",str,str1,string_contain_4(str,str1));
	printf("A:%s\tB:%s\tresult:%d\n",str,str2,string_contain_4(str,str2));
	printf("A:%s\tB:%s\tresult:%d\n",str,str3,string_contain_4(str,str3));
	return 0;
}
