#include<stdio.h>
// LIFO: 后进先出

typedef struct _Node {
	int data;
	struct Node *prev;
	struct Node *next;
} Node;

typedef struct _Stack {
	int size;
	int top;
	Node *node;
} Stack;

Stack init_stack() {
	Stack *stack;
	stack = (Stack *)malloc(sizeof(Stack));
}

// 采用头插
void push(Stack *stack) {

}

int pop(Stack *stack) {

}

void destroy_stack(Stack *stack) {

}

int main(void) {
	return 0;
}
