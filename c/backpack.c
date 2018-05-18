// 背包问题
#include<stdio.h>

// 穷举:效率极低，时间复杂度很大


// 贪婪: 从前往后或者从后往前选择当前最佳方案组合 
// 问题: 可能会避开正确方案，有较大空间浪费的可能性
/*
 *	int weight[] = {1,2,5,6,7};
	int prices[] = {1,6,18,22,28}
	int maxweight = 11;
 */
void greedy(int weight[],int prices[],int maxweight,int len) {
	int i;
	double value[len];
	for (i = 0; i < len; i++) {
		if (weight[i] == 0) {
			printf("重量不能为0\n");
			return;
		}
		value[i] = prices[i] / weight[i];
		printf("prices:%f\t",value[i]);
	}
	int sumweight = 0;
	printf("\nmaxweight:%d\n",maxweight);
	while (sumweight < maxweight) {
		int max = 0;
		for (i = 1; i < len; i++) {
			if (value[i] > value[max]) {
				max = i;
			}
		}
		sumweight += weight[i];
		if (sumweight > maxweight || value[max] == 0) {
			printf("break");
			break;
		}
		printf("id:%d\tweight:%d\tprice:%d\n",max,weight[max],prices[max]);
		value[max] = 0;
	}
}


// 动态规划:
// 将原问题分解为相对简单的子问题
// 如将背包问题：第一个不放的最优、第二个不放的最有，则第n个最优为之前所有最优的整合


int main() {
	int weight[] = {1,2,5,6,7};
	int prices[] = {1,6,18,22,28};
	int maxweight = 30;
	int len = 5;
	greedy(weight,prices,maxweight,len);

	return 0;
}
