#include<stdio.h>

int length(int arr[]) {
	printf("%d\t%d\t%d\t%d\t\n",arr[0],arr[1],arr[2],arr[3]);
	printf("sizeof_arr:%ld\n",sizeof(arr));
	printf("sizeof_arr0:%ld\t%ld\n",sizeof(arr[0]),sizeof(int));
	long int len = sizeof(arr) / sizeof(arr[0]);
	int len_test = sizeof(arr) / sizeof(arr[0]);
	printf("len:%ld\tlen_test:%d\n",len,len_test);
	return sizeof(arr) / sizeof(arr[0]);
}

// sizeof(数组名) and sizeof(指针)
int main(void) {
	int arr[] = {1,2,3,5,8,9};
	//int arr[] = {1,2,3,5,6,7,8,9,10};
	printf("sizeof_arr:%ld\n",sizeof(arr));
	printf("sizeof_arr0:%ld\t%ld\n",sizeof(arr[0]),sizeof(int));

	long int len = sizeof(arr) / sizeof(arr[0]);
	int len_test = sizeof(arr) / sizeof(arr[0]);
	printf("len:%ld\tlen_test:%d\n",len,len_test);

	printf("arr.len:%d\n",length(arr));
	return 0;
}
