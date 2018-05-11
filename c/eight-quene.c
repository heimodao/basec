#include<stdio.h>
#include<stdlib.h>

#define QUENE 8

int quene(int quene_num);

typedef struct Pos {
	int row;
	int column;
} Pos;

Pos new_pos(int row,column) {
	Pos pos = (Pos)malloc(sizeof(Pos));
	if (pos == NULL) {
		exit(0);
	}
	pos->row = row;
	pos->column = column;
	return pos
}

void print_pos(Pos pos[],int len) {
	int i;
	for (i = 0; i < len; i++) {
		printf("\(%d,%d\),\t",pos[i]->row,pos[i]->column);
	}
	printf("\n");
}

int check_success(Pos poss[],int last){
	int i;
	for (i = 0; i <= last; i++) {
		
	}
	return 0;
}

int black_pos(Pos pos) {
}

int quene(int quene_num) {
	int method = 0;
	Pos pos[8];
	Pos black_pos[64];
	int row,column;
	for (row = 0;row < quene_num;row++) {
		for (column = 0;column < quene_num;column++) {
			
		}
	}
		int left = 64;
	return method;
}

int main() {
	int method = quene(QUENE);
	printf("%d皇后共有%d种解法.",QUENE,method);
	return 0;
}
