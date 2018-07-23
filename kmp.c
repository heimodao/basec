#include<stdio.h>
#include<time.h>

// 朴素匹配
int index_match(char *str,char *pattern);
// KMP匹配
int kmp_match(char *str,char *pattern);


int index_match(char *str,char *pattern) {
	int tarindex = 0;
	while(str[tarindex] != '\0') {
		int i;
		int tarlen = tarindex;
		for (i = 0; pattern[i] != '\0'; i++) {
			if (str[tarlen++] != pattern[i]) {
				break;
			}
		}
		if (pattern[i] == '\0') {
			return tarindex;
		}
		tarindex++;
	}
	return -1;
}

// 参考资料:
// http://www.ruanyifeng.com/blog/2013/05/Knuth%E2%80%93Morris%E2%80%93Pratt_algorithm.html
// https://blog.csdn.net/v_july_v/article/details/7041827
int kmp_match(char *str,char *pattern) {
	return 0;

}

int main() {
	char str[] = "bbc abcdab abcdabcdabde";
	char str2[] = "abcdabcdabde";
	char pattern[] = "abcdabd";
	printf("朴素匹配:str1:%s\tpattern:%s\tindex:%d\n",str,pattern,index_match(str,pattern));
	printf("朴素匹配:str2:%s\tpattern:%s\tindex:%d\n",str2,pattern,index_match(str2,pattern));
	return 0;
}



