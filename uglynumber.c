#include<stdio.h>

//
typedef struct _DataStruct {
	int head;
	int tail;
} DataStruct;

DataStruct set_datastruct(int head, int tail) {
	DataStruct ds;
	ds.head = head;
	ds.tail = tail;
	return ds;
}

// num	head	tail
// num > 4
DataStruct get_datastruct(int num) {
	int sum = 4;
	int head = 3, tail = 0;
	while(sum + head * (head - 1) <= num) {
		sum = sum + head * (head - 1);
		head++;
	}
	tail = num - sum;
	return set_datastruct(head, tail);
}

void _print(int arr[], int num) {
	int i;
	for (i = 0; i < num; i++) {
		printf("%d\t", arr[i]);
		if (i % 10 == 9) {
			printf("\n");
		}
	}
	printf("\n");
}

int pow(int x, int y) {
	int i;
	int sum = 1;
	for (i = 0; i < y; i++) {
		sum = sum * x;
	}
	return sum;
}

// 只包含因子2\3\5的数称为丑数
// 通过2,3,5求取丑数
void uglynumber(int num) {
	int i;
	int ugly_arr[num];
	int arr[4] = {1, 2, 3, 5};
	for (i = 0; i < num; i++) {
		ugly_arr[i] = arr[i];
	}
	if (num <= 4) {
		_print(ugly_arr, num);
	} // head,tail 执行到第head行tail列
	DataStruct ds = get_datastruct(num);
	int count = 4;
	int line, row;
	for (line = 3; line < ds.head; line++) {
		// 生成5^x * 3^y * 2^z  <=> x + y + z = line
		int x, y, z;
		for (x = 0; x <= line; x++) {
			for (y = 0; y <= line - x; y++) {
				z = line - x - y;
				ugly_arr[count++] = pow(5,x) * pow(3,y) * pow(2,z);
			}
		}
	}
	for (row = 1; row <= ds.tail; row++) {
		// 生成5^x * 3^y * 2^z  <=> x + y + z = line
		int x, y, z;
		for (x = 0; x <= ds.head; x++) {
			for (y = 0; y <= ds.head - x; y++) {
				z = ds.head - x - y;
				ugly_arr[count++] = pow(5,x) * pow(3,y) * pow(2,z);
				if (count >= num) {
					return _print(ugly_arr, num);
				}
			}
		}
	}

}

int main(void) {
	int num;
	printf("请输入需要打印的丑数个数:");
	scanf("%d", &num);
	uglynumber(num);
}
