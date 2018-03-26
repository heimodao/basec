/*
 * author:linkzw
 * date:2018-03-26 17:12:33
 * 排序 
 * 归并排序递归版、迭代版
*/
#include<stdio.h>
#include<stdlib.h>

void merge_sort(int arr[], int len);
void merge_sort_recursion(int arr[], int len);
void _merge_sort(int arr[], int reg[], int start, int end);
int min(int x, int y);

int min(int x, int y) {
	return x < y ? x : y;
}

// 归并排序-迭代版
// 将序列每相邻两个数字进行归并操作，形成ceil(n/2)个序列,排序后每个序列包含该两/一个元素
// 若此时序列数不是一个将上述序列再次归并，形成ceil(n/4)个序列,每个序列包含四/三个元素
// 重复步骤2，直到所有元素排序完毕，即序列数为1
void merge_sort(int arr[], int len) {
	int *a = arr;
	int *b = (int*)malloc(len * sizeof(int));
	if (b == NULL) {
		printf("error:not memory!!!");
		exit(1);
	}
	int seg,start;
	for (seg = 1; seg < len; seg += seg) {
		for (start = 0; start < len; start += seg + seg) {
			/*
			int start1 = start, mid = min(start + seg, len);
			int start2 = mid, end = min(start + seg + seg, len);
			int key = start;
			printf("start:%d,mid:%d,end:%d\n",start,mid,end);
			while (start1 < mid && start2 < end) {
				//printf("start1:%d\tstart2:%d\tarr1:%d\tarr2:%d\n",start1,start2,arr[start1],arr[start2]);
				b[key++] = arr[start1] < arr[start2] ? arr[start1++] : arr[start2++];
			}
			while (start1 < mid) {
				b[key++] = arr[start1++];
			}
			while (start2 < end) {
				b[key++] = arr[start2++];
			}
			*/
			int low = start, mid = min(start + seg, len), high = min(start + seg + seg, len);
			int k = low;
			int start1 = low, end1 = mid;
			int start2 = mid, end2 = high;
			while (start1 < end1 && start2 < end2) {
				b[k++] = a[start1] < a[start2] ? a[start1++] : a[start2++];
			}
			while (start1 < end1) {
				b[k++] = a[start1++];
			}
			while (start2 < end2) {
				b[k++] = a[start2++];
			}
		}
		int *temp = a;
		a = b;
		b = temp;
	}
	// 清除a、b分配的内存
	if (a != arr) {
		int i;
		for (i = 0; i < len; i++) {
			b[i] = a[i];
		}
		b = a;
	}
	free(b);
	int i;
	for (i = 0; i < len; i++) {
		printf("%d\t",arr[i]);
	}
}

// 归并排序-递归版
void merge_sort_recursion(int arr[], int len) {
	int reg[len];
	// 递归法
	_merge_sort(arr,reg,0,len - 1);
	int i;
	for (i = 0; i < len; i++) {
		printf("%d\t", arr[i]);
	}
}

// 申请空间，使其大小为两个已经排序序列之和，该空间用来存放合并后的序列
// 设定两个指针，最初位置分别为两个已经排序序列的起始位置
// 比较两个指针所指向的元素，选择相对小的元素放入到合并空间，并移动指针到下一位置
// 重复步骤3直到某一指针到达序列尾
// 将另一序列剩下的所有元素直接复制到合并序列尾
void _merge_sort(int arr[],int reg[],int start,int end) {
	if (start >= end) {
		return;
	}
	int length = end - start;
	int mid = (length >> 1) + start;
	_merge_sort(arr,reg,start,mid);
	_merge_sort(arr,reg,mid + 1,end);
	int key = start, start1 = start, start2 = mid + 1;
	while (start1 <= mid && start2 <= end && key <= end) {
		reg[key++] = arr[start1] > arr[start2] ? arr[start2++] : arr[start1++];
	}
	while(start1 <= mid) {
		reg[key++] = arr[start1++];
	}
	while(start2 <= end) {
		reg[key++] = arr[start2++];
	}
	int i;
	for (i = start;i <= end; i++) {
		arr[i] = reg[i];
	}
}

int main() {
	int arr[20] = {11,23,4,5,47,48,90,93,8,1,23,34,52,45,15,43,22,89,10,20};
	printf("递归版本:\n");
	merge_sort_recursion(arr,20);
	int arr2[20] = {11,23,4,5,47,48,90,93,8,1,23,34,52,45,15,43,22,89,10,20};
	printf("\n迭代版本:\n");
	merge_sort(arr2,20);
	printf("\n归并排序完\n");
	return 0;
}
