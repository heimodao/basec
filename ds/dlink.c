#include<stdio.h>
#include<stdlib.h>

#include "dlink.h"

DLink* dlink_init(char *name) {
	DLink *dlink = (DLink *) malloc(sizeof(DLink));
	if (dlink == NULL) {
		printf("failed to allowcate double-link memory:%s\n",name);
		return NULL;
	}
	dlink->size = 0;
	dlink->name = name;
	dlink->head = NULL;
	dlink->tail = NULL;
	return dlink;
}

int dlink_lpush(DLink *dlink,int val) {
	Node *node = (Node *) malloc(sizeof(Node));
	if (node == NULL) {
		printf("failed to allowcate node memory:%s\n",dlink->name);
		exit(1);
	}
	node->val = val;
	node->prev = NULL;
	node->next = dlink->head;
	if (dlink->head != NULL) {
		dlink->head->prev = node;
	} else {
		dlink->tail = node;
	}
	dlink->head = node;
	dlink->size = dlink->size + 1;
	return 1;
}

int dlink_rpush(DLink *dlink,int val) {
	if (dlink->size < 1) {
		return dlink_lpush(dlink,val);
	}
	Node *node = (Node *) malloc(sizeof(Node));
	if (node == NULL) {
		printf("failed to allowcate node memory:%s\n",dlink->name);
		exit(1);
	}
	node->val = val;
	node->prev = dlink->tail;
	node->next = NULL;
	dlink->tail = node;
	node->prev->next = node;
	dlink->size = dlink->size + 1;
	return 1;
}

int dlink_getleft(DLink *dlink) {
	if (dlink->head == NULL) {
		return -1;
	}
	return dlink->head->val;
}

int dlink_getright(DLink *dlink) {
	if (dlink->tail == NULL) {
		return -1;
	}
	return dlink->tail->val;
}

int dlink_lpop(DLink *dlink) {
	if (dlink->head == NULL) {
		return 0;
	}
	Node *node = dlink->head;
	int val = node->val;
	dlink->head = node->next;
	if (dlink->head != NULL) {
		dlink->head->prev = NULL;
	}
	free(node);
	node = NULL;
	return val;
}

int dlink_rpop(DLink *dlink) {
	if (dlink->tail == NULL) {
		return 0;
	}
	Node *node = dlink->tail;
	int val = node->val;
	dlink->tail = node->prev;
	if (dlink->tail != NULL) {
		dlink->tail->next = NULL;
	}
	free(node);
	node = NULL;
	return val;
}

// A = B = C = D
// B = A = C = D
// C = B = A = D
// D = C = B = A
void dlink_reverse(DLink *dlink) {
	Node *node = dlink->head;
	Node *temp = NULL;
	while(node->next != NULL) {
		temp = node->next;
		node->next = temp->next;
		if (temp->next != NULL) {
			temp->next->prev = node;
		}
		temp->next = dlink->head;
		dlink->head->prev = temp;
		dlink->head = temp;
	}
	dlink->tail = node;
}

int dlink_isfind(DLink *dlink,int val) {
	Node *node = dlink->head;
	while (node != NULL) {
		if (node->val == val) {
			return 1;
		}
		node = node->next;
	}
	return 0;
}

void dlink_print(DLink *dlink) {
	Node *node = dlink->head;
	printf("\n--------------------\n");
	printf("link_print:");
	while (node != NULL) {
		printf("->%d",node->val);
		node = node->next;
	}
	printf("\n--------------------\n\n");
}

void dlink_free(DLink *dlink) {
	Node *node = dlink->head;
	while (node != NULL) {
		dlink->head = node->next;
		free(node);
		node = dlink->head;
	}
	node = NULL;
	free(dlink);
	dlink = NULL;
}



