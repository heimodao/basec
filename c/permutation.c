#include<stdio.h>

void swap(char *a, char *b) {
	if (*a == *b) {
		return;
	}
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;
}

void deepcopy(char copy[],char str[],int len) {
	int i;
	for (i = 0; i < len; i++) {
		copy[i] = str[i];
	}
	copy[i] = '\0';
}


// 全排列问题:可能有重复元素
// 递归思路:固定一个元素作为排列的第一个元素，然后对剩余的元素进行全排列
int _permutation(char str[],int pos,int len,int count) {
	int i,hash = 0;
	// 最后两个直接输出 等价于len - 1 - pos == 1
	if (len - pos == 2) {
		printf("count:%4d\tstr:%s\n",++count,str);
		if (str[len - 1] != str[len -2]) {
			swap(&str[len -1],&str[len - 2]);
			printf("count:%4d\tstr:%s\n",++count,str);
		}
		return count;
	}
	for (i = pos; str[i] != '\0'; i++) {
		int temp = 1 << (*(str + i) - 'A');
		if ((hash & temp) == 0) {
			hash |= temp;
			char copy[len + 1];
			deepcopy(copy,str,len);
			swap(&copy[pos],&copy[i]);
			count = _permutation(copy,pos + 1,len,count);
		}
	}
	return count;
}

int permutation(char str[]) {
	int len,count = 0;
	for (len = 0; str[len] != '\0';len++);
	return _permutation(str,0,len,count);
}

// 部分排列 从0-9选取3个数字进行排列，打印所有结果
int partial_arrangement() {
	// 先选三个 再排序 _permutation 无意义
}

// 部分排列 优化版
// 无重复,直接按顺序选取三个,选了后面的还可以选前面的
int partial_arrangement_s() {
	char arr[] = {'a','a','a'};
	char str[] = {'0','1','2','3','4','5','6','7','8','9'};
	int i,j,k,count = 0;
	for (i = 0; i < 10; i++) {
		arr[0] = str[i];
		for (j = 0; j < 10; j++) {
			if (str[j] == arr[0]) {
				continue;
			}
			arr[1] = str[j];
			for (k = 0; k < 10; k++) {
				if (str[k] == arr[0] || str[k] == arr[1]) {
					continue;
				}
				arr[2] = str[k];
				printf("%4d\t%s\n",++count,arr);
			}
		}
	}
	return count;
}

int main() {
	char str[] = "ABC";
	char str2[] = "ABCDEF";
	char str3[] = "ABCA";
	char str4[] = "ABCAB";
	printf("%s共有%d种全排列方法\n",str,permutation(str));
	//printf("%s共有%d种全排列方法\n",str2,permutation(str2));
	//printf("%s共有%d种全排列方法\n",str3,permutation(str3));
	printf("%s共有%d种全排列方法\n",str4,permutation(str4));
	printf("部分排列优化版共有%d种排列方法\n",partial_arrangement_s());
	return 0;
}
