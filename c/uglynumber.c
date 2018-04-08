#include<stdio.h>

typedef struct _Num {
	int head;
	int tail;
} Num;

Num ret_num(int num) {
	int i = 1;
	int sum = 1;
	while(sum + 3 * i < num) {
		sum = sum + 3 * i++;
	}
	Num retnum;
	retnum.head = i;
	retnum.tail = num - (sum + 3 * i);
	return retnum;
}

// 只包含因子2\3\5的数称为丑数
// 通过2,3,5求取丑数
void uglynumber(int num) {
	if (num <= 0) {
		return;
	}
	int i,j;
	int index = count = 1;
	int uglyarray[num];
	int tail = 0;
	uglyarray[0] = 1;
	Num countdata =	 ret_num(num);
	while(index <= countdata.head && tail <= countdata.tail) {

	}
	for (i = 0; i < num; i++) {
		printf("第%d个丑数\t:\t%d\n", i + 1, uglyarray[i]);
	}
}

int main(void) {
	int num;
	printf("请输入需要打印的丑数个数:");
	scanf("%d", &num);
	uglynumber(num);
}
