/*
 * 汉诺塔问题
 * linkzw
 * 2018-03-12 18:21:30
*/
#include<stdio.h>
static int step = 0;
void Hannuota(int num,char start,char mid,char end) {
	if (num < 1) {
		return;
	}
	Hannuota(num - 1, start, end, mid);
	printf("第%d步\t:\t%c ==> %c\n", ++step,start,end);
	Hannuota(num - 1, mid, start, end);
}

int main(void) {
	int num;
	printf("请输入汉诺塔数量:");
	scanf("%d", &num);
	Hannuota(num,'A','B','C');
	return 0;
}
