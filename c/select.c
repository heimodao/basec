#include<stdio.h>

// 二分查找，适用于有序数组
int binary_select(int arr[], int num, int len) {
	int low = 0, high = len - 1;
	while(low <= high) {
		int mid = (low + high) >> 1;
		if (num > arr[mid]) {
			low = mid + 1;
		} else if (num < arr[mid]) {
			high = mid - 1;
		} else {
			return mid;
		}
	}
	return -1;
}

int main(void) {
	int arr[] = {1,2,3,5,6,7,8,9,10};
	long unsigned int len = sizeof(arr) / sizeof(arr[0]);
	int length = (int)len;
	printf("find:%d\tpos:%d\n",3,binary_select(arr,3,length));
	printf("find:%d\tpos:%d\n",5,binary_select(arr,5,length));
	printf("find:%d\tpos:%d\n",7,binary_select(arr,7,length));
	printf("find:%d\tpos:%d\n",4,binary_select(arr,4,length));
	return 0;
}
