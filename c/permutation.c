#include<stdio.h>

void swap(char *a, char *b) {
	if (*a == *b) {
		return;
	}
	printf("Test1a:%c\tb:%c\n",*a,*b);
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;
	printf("Test2a:%c\tb:%c\n",*a,*b);
}

void deepcopy(char str[],char copy[]) {
	int i;
	for (i = 0; str[i] != '\0'; i++) {
		copy[i] = str[i];
	}
}


// 全排列问题:可能有重复元素
// 递归思路:固定一个元素作为排列的第一个元素，然后对剩余的元素进行全排列
int _permutation(char str[],int pos,int len) {
	int i,hash = 0,count = 0;
	printf("%d\t%d\n",pos,len);
	if (len - pos == 2) {
		printf("count:%d\tstr:%s\n",++count,str);
		if (str[len - 1] != str[len -2]) {
			swap(&str[len -1],&str[len - 2]);
			printf("count:%d\tstr:%s\n",++count,str);
		}
		return count;
	}
	for (i = pos; str[i] != '\0'; i++) {
		int temp = 1 << (*(str + i) - 'A');
		if ((hash & temp) == 0) {
			hash |= temp;
			char copy[len + 1];
			deepcopy(str,copy);
			swap(&copy[pos],&copy[i]);
			count += _permutation(copy,pos + 1,len);
		}
	}
	return count;
}

int permutation(char str[]) {
	int len;
	for (len = 0; str[len] != '\0';len++);
	return _permutation(str,0,len);
}

int main() {
	char str[] = "ABC";
	char str2[] = "ABCDEF";
	char str3[] = "ABCA";
	char str4[] = "ABCAB";
	//printf("%s共有%d种全排列方法\n",str,permutation(str));
	//printf("%s共有%d种全排列方法\n",str2,permutation(str2));
	//printf("%s共有%d种全排列方法\n",str3,permutation(str3));
	printf("%s共有%d种全排列方法\n",str4,permutation(str4));
	return 0;
}
