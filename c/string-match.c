#include<stdio.h>
#include<time.h>

// 朴素匹配
int IndexMatch(char *str,char *pattern);
// KMP匹配
int KMPMatch(char *str,char *pattern);

int main() {
	char str[] = "bbc abcdab abcdabcdabde";
	//char str[] = "abcdabcdabde";
	char pattern[] = "abcdabd";
	time_t beforeindex_time = time(NULL);
	int index = IndexMatch(str,pattern);
	time_t afterindex_time = time(NULL);
	double spendtime = difftime(afterindex_time,beforeindex_time);
	printf("朴素匹配:\nstr1:%s\tpattern:%s\tindex:%d\tspendtime:%f\t\n",str,pattern,index,spendtime);
	return 0;
}

int
IndexMatch(char *str,char *pattern) {
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

// 算法思想:
// http://www.ruanyifeng.com/blog/2013/05/Knuth%E2%80%93Morris%E2%80%93Pratt_algorithm.html
int
KMPMatch(char *str,char *pattern) {
	return 0;
}
