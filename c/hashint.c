#include<stdio.h>

unsigned int hashint(void *val) {
	int *location;
	location = (int *) val;
	return (unsigned int) *location;
}


int main() {
	int arr[] = {1,11,23,4,6,7,89,10000,50000};
	int len = sizeof(arr) / sizeof(arr[0]);
	int i;
	for (i = 0; i < len; i++) {
		printf("%d --hash--> %d\n",arr[i],hashint(arr + i));
	}
	// 数组指针 https://blog.linkzw.com/2018/03/23/C-Faq/#%E6%8C%87%E9%92%88%E6%95%B0%E7%BB%84%E5%92%8C%E6%95%B0%E7%BB%84%E6%8C%87%E9%92%88
	char *(str[]) = {"test1","test2","zengweitest","test3"};
	for (i = 0; i < 4; i++) {
		printf("%s --hash--> %d\n",*(str + i),hashint(str + i));
	}
	return 0;
}
