#include<stdio.h>

// 参考: https://github.com/julycoding/The-Art-Of-Programming-By-July/blob/master/ebook/zh/05.01.md

double max(double m,double n) {
	return m > n ? m : n;
}

double min(double m,double n) {
	return m > n ? n : m;
}

double maxsubstring(double a[],int length) {
	double maxend = a[0];
	double minend = a[0];
	double maxresult = a[0];
	int i;
	for (i = 1; i < length; i++) {
		double end1 = maxend * a[i];
		double end2 = minend * a[i];
		maxend = max(max(end1,end2),a[i]);
		minend = min(min(end1,end2),a[i]);
		maxresult = max(maxresult,maxend);
		printf("%f\t%f\t%f\n",maxend,minend,maxresult);
	}
	return maxresult;
}

int main() {
	double arr[7] = {-2.5,4,0,3,0.5,8,-1};
	printf("max-multiply-substring:%f\n",maxsubstring(arr,7));
	return 0;
}
