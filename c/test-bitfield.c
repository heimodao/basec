#include<stdio.h>
#include<stdlib.h>

typedef struct Data {
	int a;
	int b;
} Data;

typedef struct Data2 {
	int a : 1;
	int b : 1;
} Data2;

typedef struct Data3 {
	int a0 : 1;
	int a1 : 1;
	int a2 : 1;
	int a3 : 1;
	int a4 : 1;
	int a5 : 1;
	int a6 : 1;
	int a7 : 1;
	int a8 : 1;
	int a9 : 1;
	int b0 : 1;
	int b1 : 1;
	int b2 : 1;
	int b3 : 1;
	int b4 : 1;
	int b5 : 1;
	int b6 : 1;
	int b7 : 1;
	int b8 : 1;
	int b9 : 1;
	int c0 : 1;
	int c1 : 1;
	int c2 : 1;
	int c3 : 1;
	int c4 : 1;
	int c5 : 1;
	int c6 : 1;
	int c7 : 1;
	int c8 : 1;
	int c9 : 1;
	int d0 : 1;
	int d1 : 1;
} Data3;

typedef struct Data4 {
	int a0 : 1;
	int a1 : 1;
	int a2 : 1;
	int a3 : 1;
	int a4 : 1;
	int a5 : 1;
	int a6 : 1;
	int a7 : 1;
	int a8 : 1;
	int a9 : 1;
	int b0 : 1;
	int b1 : 1;
	int b2 : 1;
	int b3 : 1;
	int b4 : 1;
	int b5 : 1;
	int b6 : 1;
	int b7 : 1;
	int b8 : 1;
	int b9 : 1;
	int c0 : 1;
	int c1 : 1;
	int c2 : 1;
	int c3 : 1;
	int c4 : 1;
	int c5 : 1;
	int c6 : 1;
	int c7 : 1;
	int c8 : 1;
	int c9 : 1;
	int d0 : 1;
	int d1 : 1;
	int d2 : 1;
} Data4;

typedef struct Data5 {
	unsigned int a : 3;
} Data5;

int main() {
	printf("data:\t%ld\n",sizeof(Data));
	printf("data2:\t%ld\n",sizeof(Data2));
	printf("data3:\t%ld\n",sizeof(Data3));
	printf("data4:\t%ld\n",sizeof(Data4));
	Data5 *data = (Data5*) malloc(sizeof(Data5));
	data->a = 4;
	printf("data5:\t%ld\n",sizeof(Data5));
	printf("%d\n",data->a);
	data->a = 7;
	printf("%d\n",data->a);
	//data->a = 8; --> compile error
	printf("%d\n",data->a);
	free(data);
	return 0;
}
