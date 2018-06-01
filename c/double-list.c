#include<stdio.h>
#include<stdlib.h>

// 双向链表
typedef struct Node {
	int val;
	struct Node *pre,*next;
} Node;

Node* new_node() {
	Node *node = (Node*) malloc(sizeof(Node));
	if (node == NULL) {
		printf("结点内存分配失败");
		exit(1);
	}
	node->pre = NULL;
	node->next= NULL;
	return node;
}
