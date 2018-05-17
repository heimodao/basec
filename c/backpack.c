// 背包问题
#include<stdio.h>

#define MAX_WEIGHT  300

typedef struct _world {
	int weight;
	int value;
} World, *pWorld;

World new_world(int weight,int value) {
	World world;
	world.weight = weight;
	world.value = value;
	return world;
}

World* create_world(int num) {
	World *pworld = (World*)malloc(num * sizeof(World));
	if (pworld == NULL) {
		exit(1);
	}
	int weight,value;
	for (i = 0; i < num; i++) {
		weight = 10 * (i + 1);
		value = 100 * (i + 1);
		*(pworld + i) = new_world(weight,value);
	}
	return pworld;
}


// 穷举:效率极低，时间复杂度很大


// 贪婪: 从前往后或者从后往前选择当前最佳方案组合 
// 问题: 可能会避开正确方案，有较大空间浪费的可能性
void greedy(int weight[],int prices[],int maxweight,int len) {
	int i;
	double value[];
	for (i = 0; i < len; i++) {
		if (weight[i] == 0) {
			printf("重量不能为0\n");
			return;
		}
		value[i] = prices[i] / weight[i];
	}
	int programe[];
	printf("-----当前最佳方案-----\n");
	for (i = 0; programe[i] != '\0'; i++) {
		int id = programe[i];
		printf("programe:%d\tweight:%d\tprice:\n",id,weight[id],price[id]);
	}
	printf("-----打印完毕-----\n");
}


// 动态规划:
// 将原问题分解为相对简单的子问题
// 如将背包问题：第一个不放的最优、第二个不放的最有，则第n个最优为之前所有最优的整合


int main() {
	int weight[] = {1,2,5,6,7};
	int prices[] = {1,6,18,22,28}
	int maxweight = 11;
	int len = 5
	greedy(weight,prices,maxweight,len);

	return 0;
}
