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

// 普通算法: 按照排列组合对所有总重量低于300的进行排列，选择最合适的方案
// 效率极低，时间复杂度很大



// 贪婪: 从前往后或者从后往前选择当前最佳方案组合 
// 问题: 可能会避开正确方案，有较大空间浪费的可能性


// 动态规划:
// 将原问题分解为相对简单的子问题
// 如将背包问题：第一个不放的最优、第二个不放的最有，则第n个最优为之前所有最优的整合
// int f[100];
// f[0] = f[1] = 1;
// for (i = 2; i < 99; i += 1) {
//		f[i] = f[i - 2] + f[i - 1];
// }


int main() {
	return 0;
}
