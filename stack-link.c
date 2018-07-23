#include<stdio.h>
#include<stdlib.h>

// 栈 后进先出 使用链表头插，头删除
// stack.push stack.pop

typedef struct Node {
	int val;
	struct Node *next;
} Node;

typedef struct Stack {
	char *name;
	struct Node *head;
	int size;
} Stack;

// new
Stack* new_stack(char *str) {
	Node *phead = (Node*)malloc(sizeof(Node));
	if (phead == NULL) {
		printf("%s初始化失败:头结点内存分配失败",str);
		exit(1);
	}
	phead->next = NULL;

	Stack *stack = (Stack*) malloc(sizeof(Stack));
	if (stack == NULL) {
		printf("%s初始化失败:栈内存分配失败",str);
		exit(1);
	}
	stack->head = phead;
	stack->size = 0;
	stack->name = str;
	return stack;
}

// push
int stack_push(Stack *stack,int val) {
	Node *pnode = (Node*) malloc(sizeof(Node));
	if (pnode == NULL) {
		printf("创建节点失败");
		exit(1);
	}
	pnode->val = val;
	pnode->next = stack->head->next;
	stack->head->next = pnode;

	stack->size += 1;
	return val;
}

// pop
int stack_pop(Stack *stack) {
	if (stack->size <= 0) {
		printf("栈数据为空，无法执行删除操作");
		return -1;
	}
	Node *pop = stack->head->next;
	stack->head->next = pop->next;
	stack->size -= 1;

	int val = pop->val;
	free(pop);
	pop = NULL;
	return val;
}

// size
int stack_size(Stack *stack) {
	return stack->size;
}

// isempty
int stack_isempty(Stack *stack) {
	return stack->size == 0;
}

// destroy
char* destroy_stack(Stack *stack) {
	Node *pnode = NULL;
	char *stack_name = stack->name;
	while(stack->head != NULL) {
		pnode = stack->head;
		stack->head = stack->head->next;
		free(pnode);
		pnode = NULL;
	}
	free(stack);
	stack = NULL;
	return stack_name;
}

// print
void print_stack(Stack *stack) {
	if (stack_isempty(stack)) {
		return;
	}
	printf("\n%s栈共有%d个元素.\n",stack->name,stack->size);
	Node *pnode = stack->head->next;
	while(pnode != NULL) {
		printf("%d\n",pnode->val);
		pnode = pnode->next;
	}
	pnode = NULL;
	printf("--------输出完毕----------\n\n");
}

// gethead
int stack_gethead(Stack *stack) {
	if (stack_isempty(stack)) {
		printf("%s栈为空",stack->name);
		return -1;
	}
	return stack->head->next->val;
}

int main() {
	Stack *stack = (Stack*)new_stack("test");
	stack_push(stack,1);
	stack_push(stack,2);
	stack_push(stack,3);
	stack_pop(stack);
	stack_push(stack,4);
	print_stack(stack);
	printf("%s栈表头元素%d\n",stack->name,stack_gethead(stack));
	printf("销毁栈:%s\n",destroy_stack(stack));
	return 0;
}




