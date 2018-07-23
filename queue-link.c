#include<stdio.h>
#include<stdlib.h>

// 队列：先进先出 链表尾插，头出 头删除
// 双端队列
// 其他，对顶栈、对底栈实现队列

typedef struct Node {
	int val;
	struct Node *next;
} Node;

typedef struct Queue {
	char *name;
	int size;
	Node *head;
} Queue;

// init_queue
Queue* init_queue(char *name) {
	Node *node = (Node*) malloc(sizeof(Node));
	if (node == NULL) {
		printf("%s:节点申请失败\n",name);
		exit(1);
	}
	node->next = NULL;
	Queue *queue = (Queue*) malloc(sizeof(Queue));
	if (queue == NULL) {
		printf("%s:队列申请失败",name);
		exit(1);
	}
	queue->name = name;
	queue->size = 0;
	queue->head = node;
	return queue;
}

// push
// ret pos
int push(Queue *queue,int val) {
	return rpush(queue,val);
}

// rpush
int rpush(Queue *queue,int val) {
	Node *pnode = (Node*) malloc(sizeof(Node));
	if (pnode == NULL) {
		printf("%s队列右插失败:%d",queue->name,val);
		exit(1);
	}
	pnode->val = val;
	Node *tail = queue->head;
	while(tail->next != NULL) {
		tail = tail->next;
	}
	pnode->next = tail->next;
	tail->next = pnode;
	queue->size += 1;
	return queue->size;
}

// lpush
int lpush(Queue *queue,int val) {
	Node *pnode = (Node*) malloc(sizeof(Node));
	if (pnode == NULL) {
		printf("%s队列左插失败:%d",queue->name,val);
		exit(1);
	}
	pnode->val = val;
	pnode->next = queue->head->next;
	queue->head->next = pnode;
	queue->size += 1;
	return 1;
}

// pop
// ret val
int pop(Queue *queue) {
	if (queue->head->next == NULL) {
		printf("%s队列为空，无法删除\n",queue->name);
		return 0;
	}
	Node *left = queue->head->next;
	int val = left->val;
	queue->head->next = left->next;
	free(left);
	left = NULL;
	return val;
}

// print_queue
void print_queue(Queue *queue) {
	if (queue->head->next == NULL) {
		printf("%s队列为空\n",queue->name);
		return;
	}
	printf("\n%s队列共有%d个元素\n",queue->name,queue->size);
	Node *node = queue->head->next;
	while(node != NULL) {
		printf("%d\n",node->val);
		node = node->next;
	}
	printf("----------打印完毕------\n\n");
}

// destroy_queue
void destroy_queue(Queue *queue) {
	Node *pnode = NULL;
	// free
	while(queue->head->next != NULL) {
		pnode = queue->head->next;
		queue->head->next = pnode->next;
		free(pnode);
	}
	free(queue->head);
	queue->head = NULL;
	free(queue);
}

int main() {
	Queue *queue = init_queue("queue_test");
	push(queue,1);
	push(queue,2);
	push(queue,3);
	lpush(queue,4);
	lpush(queue,5);
	lpush(queue,6);
	printf("pop:%d\n",pop(queue));
	print_queue(queue);
	destroy_queue(queue);
	return 0;
}


