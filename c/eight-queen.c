#include <stdio.h>

#define QUEENS       8 /*皇后数量*/

// 栈
typedef struct Node {
	int pos_x;
	int pos_y;
	struct Node *next;
} Node;

typedef struct Stack {
	int size;
	struct Node *head;
}

Stack* init_stack() {
	Stack *stack = (Stack *) malloc(sizeof(Stack));
	if (stack == NULL) {
		printf("内存分配失败");
		exit(1);
	}
	stack->head = NULL;
	stack->size = 0;
	return stack;
}

void lpush_stack(int pos_x,int pos_y) {
	
}

void lpop_stack(Stack *stack) {
}

// pos[0] = 2 表示 x=0y=3
// line[0] & 11111111 表示棋盘 0无子可落子处 1为有子
void init_queen(int pos[],int lines[]) {
	// init
	int i;
	for (i = 0; i < QUEENS; i++) {
		pos[i] = -1;
		lines[i] = 0;
	}

}

// x= 3,y = 3
void setpos(int x,int y,int pos[], int lines[]) {
	pos[x] = y;
	int i = 0;
	for (i = 0; i < QUEENS; i++) {
		// 横
		lines[x] = lines[x] | (0 << (i + 1));
		if (i != x) {
			// 竖
			int temp = 1 << (y + 1)
			lines[i] = line[i] | (1 << (y + 1));
			// 撇 y0 < y
			int y0 = i + y - x;
			if (y0 >= 0) {
				lines[i] = lines[i] | (1 << y0);
			}
			// 揦 y1 = y1 > y
			int x1 = 2 * x + i;
			if (x1 < QUEENS) {
				lines[x1] = lines[x1] | (1 << y0);
			}
		}
	}
}

// x行是否还有有效位置 todo:优化：计算出有效位置
int iszeropos(int x,int lines[]) {
	int i;
	int key = 0;
	for (i = 0; i < QUEENS; i++) {
		key = key | (0 << (i + 1));
	}
	return (lines[x] & key) < key;
}

void print_pos(int pos[],int lines[],int count) {
	int i,j;
	printf("---->start:%d\n",count);
	for (i = 0; i < QUEENS; i++) {
		for (j = 0; j < QUEENS; j++) {
			if (pos[i] == j) {
				printf("1");
			} else {
				printf("0");
			}
		}
		printf("\n");
	}
	printf("---->end%d\n\n",count);
}

void eight_queen(int pos_x,int pos_y,int pos[],int lines[],int count) {
	int x,y;
	for (x = pos_x; x < QUEENS; x++) {
		for (y = pos_y; y < QUEENS; y++) {
			if (can_setpos()) {
				pos[x] = y;
				setpos(x,y,pos,lines);
			}
		}
		Stack *stack = pop();
		x = (stack->pos_x) - 1;
		y = stack->pos_y;
		free(stack);
		stack = NULL;
	}
}

int main(void) {
	int pos[QUEENS],lines[QUEENS];
	init_queen(pos,lines);
	int count = eight_queen(0,0,pos,lines,0);
	printf("%d皇后共有%d种解法\n",QUEENS,count);
	return 0;
}














