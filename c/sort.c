/*
 * author:linkzw
 * date:2018-03-26 17:12:33
 * 排序 
 * 0.随机数组								完成
 * 内部排序==>使用内存
 * 内部排序==>插入排序
 * 1.直接插入排序							完成
 * 2.折半插入排序							完成
 * 3.希尔排序								完成
 * 内部排序==>选择排序
 * 4.简单选择排序							完成
 * 5.堆排序
 * 内部排序==>交换排序
 * 6.冒泡排序								已完
 * 7.快速排序								未完
 * 内部排序==>归并排序
 * 8.归并排序递归版、迭代版					已完
 * 内部排序==>基数排序
 * 9.基数排序								未完
 * 外部排序==>内存和外存结合使用
 * 10.堆排序
 * 11.桶排序
*/
#include<stdio.h>
#include<stdlib.h>

int min(int x,int y);
void swap(int *p,int *q);
void random_array(int size, int min, int max, int arr[]);
void print_array(int arr[], int len);
void insert_sort(int arr[], int len);
void binary_insert_sort(int arr[], int len);
void shell_sort(int arr[], int len);

void bubble_sort(int arr[], int len);
void quick_sort(int arr[], int len);
void merge_sort(int arr[], int len);
void merge_sort_recursion(int arr[], int len);
void _merge_sort(int arr[], int reg[], int start, int end);

// math.min
int min(int x, int y) {
	return x < y ? x : y;
}

// 交换两个数字
void swap(int *p, int *q) {
	if (*p == *q) {
		return;
	}
	*p = *p ^ *q;
	*q = *q ^ *p;
	*p = *p ^ *q;
}

// 产生size个[min,max]的随机数
void random_array(int size, int min, int max, int arr[]) {
	int i;
	for (i = 0; i < size; i++) {
		arr[i] = (rand() % (max - min + 1)) + 1;
	}
	print_array(arr, size);
}

// 打印数组
void print_array(int arr[], int len) {
	int i;
	for (i = 0; i < len; i++) {
		printf("%d\t",arr[i]);
		if (i % 10 == 9) {
			printf("\n");
		}
	}
	printf("\n");
}

// 1.直接插入排序
void insert_sort(int arr[], int len) {
	int i;
	for (i = 1; i < len; i++) {
		if (arr[i - 1] > arr[i]) {
			int key = arr[i], j = 0;
			while (i > 0 && arr[i - 1] > key) {
				arr[i] = arr[i - 1];
				i--;
			}
			arr[i] = key;
		}
	}
}

// 2.折半插入排序
void binary_insert_sort(int arr[], int len) {
	int i, j, low, mid, high, key;
	for (i = 1; i < len; i++) {
		if (arr[i - 1] > arr[i]) {
			low = 0, high = i - 1;
			while(low <= high) {
				mid = (high + low) >> 1;
				if (arr[mid] > arr[i]) {
					high = mid - 1;
				} else {
					low = mid + 1;
				}
			}
			key = arr[i];
			for (j = i - 1; j > high; j--) {
				arr[j + 1] = arr[j];
			}
			arr[j + 1] = key;
		}
	}
}

// 3.希尔排序
// gap插入排序
void shell_sort(int arr[],int len) {
	int gap,i,j,temp;
	for (gap = len >> 1; gap > 0; gap = gap >> 1) {
		for (i = gap; i < len; i++) {
			temp = arr[j = i];
			while (j >= gap && arr[j - gap] > temp) {
				arr[j] = arr[j - gap];
				j -= gap;
			}
			arr[j] = temp;
		}
	}
}

// 4.简单选择排序
void select_sort(int arr[], int len) {
	int i,j,temp;
	for (i = 0; i < len - 1; i ++) {
		int temp = i;
		for (j = i + 1; j < len; j++) {
			if (arr[j] < arr[temp]) {
				temp = j;
			}
		}
		swap(&arr[i],&arr[temp]);
	}
}

// 5.堆排序
void heap_sort(int arr[], int len) {

}

// 6.冒泡排序
// a.比较相邻的元素，如果第一个比第二个大，就交换两个
// b.对每一对相邻元素做同样工作，从第一对到最后一对。
// c.重复ab，直到没有任何一对数字需要比较
void bubble_sort(int arr[], int len) {
	int i, j;
	for (i = 0; i < len; i++) {
		for (j = 0; j < len - i; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(&arr[j], &arr[j + 1]);
			}
		}
	}
	/*
	// 优化版: 移动次数少，但是比较次数多 <=> 详见简单选择排序select_sort
	for (i = 0; i < len; i++) {
		int key = 0;
		for (j = 0; j < len - i; j++) {
			if (arr[j] > arr[key]) {
				key = j;
			}
		}
		swap(&arr[key], &arr[min(j, len - i - 1)]);
	}
	*/
}

// 7.快速排序
void quick_sort(int arr[], int len) {

}

// 8.1归并排序-迭代版
// a.将序列每相邻两个数字进行归并操作，形成ceil(n/2)个序列,排序后每个序列包含该两/一个元素
// b.若此时序列数不是一个将上述序列再次归并，形成ceil(n/4)个序列,每个序列包含四/三个元素
// c.重复步骤b，直到所有元素排序完毕，即序列数为1
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
			int low = start, mid = min(start + seg, len), high = min(start + seg + seg, len); int k = low;
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

// 8.2归并排序-递归版
void merge_sort_recursion(int arr[], int len) {
	int reg[len];
	// 递归法
	_merge_sort(arr,reg,0,len - 1);
}

// 8.2归并排序-递归版
// a.申请空间，使其大小为两个已经排序序列之和，该空间用来存放合并后的序列
// b.设定两个指针，最初位置分别为两个已经排序序列的起始位置
// c.比较两个指针所指向的元素，选择相对小的元素放入到合并空间，并移动指针到下一位置
// d.重复步骤c直到某一指针到达序列尾
// e.将另一序列剩下的所有元素直接复制到合并序列尾
void _merge_sort(int arr[], int reg[], int start, int end) {
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

// 9.基数排序
// 10.
int main() {
	int size = 20,min = 1,max = 100;
	// 产生100个[1,100]的随机数
	int arr[size];
	random_array(size, min, max, arr);
	/*
	// 归并排序测试 递归版 迭代版
	merge_sort_recursion(arr, size);
	print_array(arr, size);
	merge_sort(arr, size);
	print_array(arr, size);
	// 直接插入排序
	insert_sort(arr, size);
	print_array(arr, size);
	// 折半插入排序
	binary_insert_sort(arr, size);
	print_array(arr, size);
	// 希尔排序
	shell_sort(arr, size);
	print_array(arr, size);
	// 冒泡排序测试
	bubble_sort(arr, size);
	print_array(arr, size);
	*/
	select_sort(arr, size);
	print_array(arr, size);
	return 0;
}
