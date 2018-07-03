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

val_type dlink_lpush(DLink *dlink,val_type val) {
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

val_type dlink_rpush(DLink *dlink,val_type val) {
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

val_type dlink_getpos(DLink *dlink,val_type pos) {
	if (dlink->size == 0) {
		return -1;
	}
	if (dlink->size < pos) {
		return dlink->head->val;
	}
	int count = 1;
	Node *node = dlink->head;
	while (node->next != NULL && count++ < pos) {
		node = node->next;
	}
	return node->val;
}


val_type dlink_getleft(DLink *dlink) {
	if (dlink->head == NULL) {
		return -1;
	}
	return dlink->head->val;
}

val_type dlink_getright(DLink *dlink) {
	if (dlink->tail == NULL) {
		return -1;
	}
	return dlink->tail->val;
}

val_type dlink_valpop(DLink *dlink,val_type val) {
	Node *node = dlink->head;
	while (node != NULL) {
		if (node->val == val) {
			break;
		}
		node = node->next;
	}
	if (node == NULL) {
		return 0;
	}
	if (node == dlink->head) {
		dlink->head = node->next;
		dlink->head->prev = NULL;
	} else if (node == dlink->tail) {
		dlink->tail = node->prev;
		dlink->tail->next = NULL;
	} else {
		node->prev->next = node->next;
		node->next->prev = node->prev;
	}
	free(node);
	node = NULL;
	return 1;
}

val_type dlink_lpop(DLink *dlink) {
	if (dlink->head == NULL) {
		return 0;
	}
	Node *node = dlink->head;
	val_type val = node->val;
	dlink->head = node->next;
	if (dlink->head != NULL) {
		dlink->head->prev = NULL;
	}
	free(node);
	node = NULL;
	return val;
}

val_type dlink_rpop(DLink *dlink) {
	if (dlink->tail == NULL) {
		return 0;
	}
	Node *node = dlink->tail;
	val_type val = node->val;
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

int dlink_isfind(DLink *dlink,val_type val) {
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



