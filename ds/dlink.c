#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
	void *val;
	typedef *prev,*next;
} Node;

typedef struct DLink {
	char *name;
	int size;
	struct Node *head,*tail;
} DLink;

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

int dlink_lpush(DLink *dlink,void* val) {
	Node *node = (Node *) malloc(sizeof(Node));
	if (node == NULL) {
		printf("failed to allowcate node memory:%s\n",dlink->name);
		return 0;
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
	return 1;
}

int dlink_rpush(DLink *dlink,void* val) {
	if (dlink->size < 1) {
		return dlink_lpush(dlink,val);
	}
	Node *node = (Node *) malloc(sizeof(Node));
	if (node == NULL) {
		printf("failed to allowcate node memory:%s\n",dlink->name);
		return 0;
	}
	node->val = val;
	node->prev = dlink->tail;
	node->next = NULL;
	dlink->tail = node;
	return 1;
}

int dlink_lpop(DLink *dlink) {
	if (dlink->head == NULL) {
		return 0;
	}
	Node *node = dlink->head;
	dlink->head = node->next;
	if (dlink->head != NULL) {
		dlink->head->prev = NULL;
	}
	free(node);
	node = NULL;
	return 1;
}

void* dlink_getleft(DLink *dlink) {
	if (dlink->head != NULL) {
		return NULL;
	}
	return dlink->head->val;
}

void* dlink_getright(DLink *dlink) {
	if (dlink->tail != NULL) {
		return NULL;
	}
	return dlink->tail->val;
}

void* dlink_rpop(DLink *dlink) {
	if (dlink->tail == NULL) {
		return 0;
	}
	Node *node = dlink->tail;
	dlink->tail = node->prev;
	if (dlink->tail != NULL) {
		dlink->tail->next = NULL;
	}
	free(node);
	node = NULL;
	return 1;
}

void dlink_reverse(DLink *dlink) {
	
}

int dlink_isfind(DLink *dlink,void* val) {
	Node *node = dlink->head;
	while (node != NULL) {
		if (node->val == val) {
			return 1;
		}
	}
	return 0;
}

void dlink_print(DLink *dlink,char *val_type) {
	Node *node = dlink->head;
	printf("\n--------------------");
	while (node != NULL) {
		if (val_type == "integer") {
			printf("->%d",(int)node->val);
		} else if (val_type == "char") {
			printf("->%c",(char)node->val);
		} else {
			printf("->%s",(char *)node->val);
		}
	}
	printf("--------------------\n\n");
}

void dlink_free(DLink *dlink,void* val) {
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



