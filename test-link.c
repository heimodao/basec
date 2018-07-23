#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
	int val;
	struct Node *next;
} Node;

typedef struct Stack {
	int size;
	char *name;
	struct Node *node;
} Stack;

int main() {
	// link list
	struct Node *pnode = (Node*) malloc(sizeof(Node));
	if (pnode == NULL) {
		printf("内存分配失败");
		exit(0);
	}
	pnode->val = 100;
	pnode->next = NULL;
	printf("node:%d\n",pnode->val);

	// stack
	struct Stack *stack = (Stack*) malloc(sizeof(Stack));
	if (stack == NULL) {
		printf("栈内存分配失败");
		exit(0);
	}
	stack->size = 1;
	stack->name = "stack";
	stack->node = pnode;

	printf("stack.size:%d,stack.name:%s,stack.node:%d\n",stack->size,stack->name,stack->node->val);

	free(pnode);
	pnode = NULL;

	free(stack);
	stack = NULL;
	return 0;
}
