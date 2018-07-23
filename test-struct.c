#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
	int val;
	struct Node *next;
} Node;

int main() {
	Node *node = (Node *) malloc(sizeof(Node));
	if (node == NULL) {
		printf("failed to allocate memory!!");
		exit(0);
	}
	node->next = NULL;
	printf("test:%d\n",node->val);
	return 0;
}
