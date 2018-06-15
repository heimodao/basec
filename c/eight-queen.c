#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define QUEENS 8 /*皇后数量*/

// 栈
typedef struct Node {
	int pos_x;
	int pos_y;
	struct Node *next;
} Node;

typedef struct Stack {
	int size;
	struct Node *head;
} Stack;

static int sitekey = 0;
static int init_num = 1 << (QUEENS + 1);

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

void lpush_stack(Stack *stack,int pos_x,int pos_y) {
	Node *node = (Node *) malloc(sizeof(Node));
	if (node == NULL) {
		printf("内存分配失败");
		exit(1);
	}
	node->next = stack->head;
	node->pos_x = pos_x;
	node->pos_y = pos_y;
	stack->head = node;
	stack->size = stack->size + 1;
}

Node* lpop_stack(Stack *stack) {
	if (stack->head == NULL) {
		return NULL;
	}
	Node *node = stack->head;
	stack->head = node->next;
	stack->size = stack->size - 1;
	return node;
}

void print_stack(Stack *stack) {
	int count = 0;
	Node *node = stack->head;
	while (node != NULL) {
		printf("step%d:node->pos_x:%d\tnode->pos_y:%d\n",++count,node->pos_x,node->pos_y);
		node = node->next;
	}
}

void free_stack(Stack *stack) {
	while(stack->head != NULL) {
		Node *node = stack->head;
		stack->head = node->next;
		free(node);
		node = NULL;
	}
	free(stack);
	stack = NULL;
}

// pos[0] = 2 表示 x=0y=3
// line[0] & 11111111 表示棋盘 0无子可落子处 1为有子
void init_queen(int pos[],int x) {
	// init
	int i;
	/*
	for (i = x; i < QUEENS; i++) {
		pos[i] = init_num;
		sitekey = sitekey ^ (1 << (pos[i] + 1));
	}
	*/
	sitekey = 0;
	for (i = 0; i < QUEENS; i++) {
		if (i >= x) {
			pos[i] = init_num;
		} else {
			sitekey = sitekey | (1 << (pos[i] + 1));
		}
	
	}
}

// 后续需要优化
int can_setpos(int x,int y,int pos[]) {
	if (x == 0) {
		return 1;
	}
	// 检查横是否有重复元素 未检查y=0情形
	if ((sitekey & (1 << (y + 1))) != 0) {
		return 0;
	}
	int i;
	for (i = 0; i < x; i++) {
		// 横0
		if (pos[i] == y) {
			return 0;
		}
		// 撇揦
		if ((y == pos[i] + (x - i)) || (y == pos[i] - (x - i))) {
			return 0;
		}
	}
	return 1;
}

void insert_pos(int x,int y,int pos[],Stack *stack) {
	int i;
	for (i = QUEENS - 1; i > y; i--) {
		if (can_setpos(x,y,pos)) {
			lpush_stack(stack,x,i);
		}
	}
}

// x= 3,y = 3
void setpos(int x,int y,int pos[]) {
	pos[x] = y;
	sitekey = sitekey | (1 << (y + 1));
}

void print_pos(int pos[],int count) {
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

// check
int check_queen(int pos[]) {
	int i;
	int sum = 0;
	for (i = 0; i < QUEENS; i++) {
		sum += pos[i];
	}
	//printf("step:check_sum:%d\n",sum);
	return sum * 2 == (QUEENS * (QUEENS - 1));
}

// 采用pos[x]=y标志是坐标 可尝试使用位操作来实现八皇后
int eight_queen(int pos_x,int pos_y,int pos[]) {
	int x,y;
	int count = 0;
	Stack *stack = init_stack();
	for (x = pos_x; x < QUEENS; x++) {
		int tempkey = 0;
		for (y = pos_y; y < QUEENS; y++) {
			if (can_setpos(x,y,pos)) {
				// 插入其他可用选择
				insert_pos(x,y,pos,stack);
				setpos(x,y,pos);
				break;
			}
		}
		if (x == QUEENS -1) {
			//print_stack(stack);
			if (pos[x] != init_num && check_queen(pos)) {
				print_pos(pos,++count);
			}
			if (stack->size <= 0) {
				return;
			}
			Node *node = lpop_stack(stack);
			init_queen(pos,node->pos_x);
			x = node->pos_x - 1;
			y = node->pos_y - 1;
			free(node);
			node = NULL;
		}
	}
	free_stack(stack);
	return count;
}

int main(void) {
	int pos[QUEENS];
	init_queen(pos,0);
	int count = eight_queen(0,0,pos);
	printf("%d皇后共有%d种解法\n",QUEENS,count);
	return 0;
}














