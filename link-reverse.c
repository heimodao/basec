#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
	int val;
	struct Node *next;
} Node;

void insert_node(Node *head,int val) {
	Node *node = (Node*) malloc(sizeof(Node));
	if (node == NULL) {
		printf("内存分配失败");
		return;
	}
	node->val = val;
	node->next = head->next;
	head->next = node;
}

void free_node(Node *head) {
	Node *tail = head->next;
	while(tail != NULL) {
		head->next = tail->next;
		free(tail);
		tail->next = head->next;
	}
	free(head);
}

void print_node(Node *head) {
	Node *tail = head->next;
	while (tail != NULL) {
		printf("%d\t",tail->val);
		tail = tail->next;
	}
	printf("\n");
}

// 遍历取出每一位数头插
void reverse_node(Node *head) {
	Node *end = head->next;
	while(end->next != NULL) {
		Node *current = end->next;
		end->next = end->next->next;
		current->next = head->next;
		head->next = current;
	}
}


int main(void) {
	Node *head = (Node*)malloc(sizeof(Node));
	if (head == NULL) {
		printf("内存分配失败\n");
		return 0;
	}
	head->next = NULL;
	insert_node(head,1);
	insert_node(head,2);
	insert_node(head,3);
	insert_node(head,4);
	insert_node(head,5);
	print_node(head);
	reverse_node(head);
	print_node(head);
	return 0;
}
