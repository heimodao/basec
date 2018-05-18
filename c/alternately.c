#include<stdio.h>
#include<stdlib.h>

// https://github.com/julycoding/The-Art-Of-Programming-By-July/blob/master/ebook/zh/05.04.md

// array_stack
//
typedef struct Stack {
	int i;
	int j;
	int s;
	struct Stack *next;
} Stack;

Stack *stack_head = NULL;

void init_stack() {
	stack_head = (Stack *) malloc(sizeof(Stack));
	if (stack_head == NULL) {
		printf("栈节点内存申请失败\n");
		exit(1);
	}
	stack_head->next = NULL;
}

void push(int i,int j,int s) {
	Stack *stack = (Stack *) malloc(sizeof(Stack));
	if (stack == NULL) {
		printf("栈节点内存申请失败\n");
		exit(1);
	}
	stack->i = i;
	stack->j = j;
	stack->s = s;
	stack->next = stack_head->next;
	stack_head->next = stack;
}

void pop() {
	// 不需要检查节点是否为空，为空调用这种情况不存在
	Stack *stack = stack_head->next;
	stack_head->next = stack->next;
	free(stack);
	stack = NULL;
}

Stack* gettail() {
	return stack_head->next;
}

void destroy_stack() {
	Stack *stack = NULL;
	while(stack_head->next != NULL) {
		stack = stack_head->next;
		stack_head->next = stack->next;
		free(stack);
		stack = NULL;
	}
	free(stack_head);
	stack_head = NULL;
}

// 使用简单栈将递归变成循环

int isalternately(char *a,char *b,char *str) {
	init_stack();
	int i = 0,j = 0,s = 0;
	int use_b = 0;
	while(*(str + s) != '\0') {
		if (*(a + i) != *(str + s) && *(b + j) != *(str + s)) {
			Stack *stack = gettail();
			if (stack == NULL) {
				destroy_stack();
				return 0;
			} else {
				i = stack->i;
				j = stack->j;
				s = stack->s;
				use_b = 1;
			}
		}
		// a,b 相等
		if (*(a + i) == *(b + j)) {
			if (use_b) {
				pop();
				j++;
				s++;
			} else {
				push(i,j,s);
				i++;
				s++;
			}
		} else {
			if (*(a + i) == *(str + s)) {
				i++;
				s++;
			} else {
				j++;
				s++;
			}
		}
	}
	destroy_stack();
	// 长度不等或者有数据不等
	if (*(a + i) != '\0' || *(b + j) != '\0' || *(str + s) != '\0') {
		return 0;
	}
	return 1;
}

int main(void) {
	char *a = "aabcc";
	char *b = "dbbca";
	char *str = "aadbbcbcac";
	char *str2 = "accabdbbca";
	printf("a:%s\tb:%s\tstr:%s\tresult:%d\n",a,b,str,isalternately(a,b,str));
	printf("a:%s\tb:%s\tstr:%s\tresult:%d\n",a,b,str2,isalternately(a,b,str2));
	return 0;
}
