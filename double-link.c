#include<stdio.h>
#include<stdlib.h>

// 节点
typedef struct Node {
	int val;
	struct Node *pre,*next;
} Node;

// 双向无环链表
typedef struct DList {
	unsigned int size;
	struct Node *head;
	struct Node *tail;
} DList;

DList* new_dlist() {
	DList *list = (DList *) malloc(sizeof(DList));
	if (list == NULL) {
		printf("双向链表内存分配失败");
		exit(1);
	}
	list->size = 0;
	list->head = NULL;
	list->tail = NULL;
	return list;
}

// head_insert
void lpush(DList *list,int val) {
	Node *node = (Node*) malloc(sizeof(Node));
	if (node == NULL) {
		printf("结点内存分配失败");
		exit(1);
	}
	node->val = val;
	node->pre = NULL;
	if (list->size < 1) {
		node->next = NULL;
		list->tail = node;
	} else {
		node->next = list->head;
		list->head->pre = node;
	}
	list->head = node;
	list->size = list->size + 1;
}

// tail_insert
void rpush(DList *list,int val) {
	if (list->size == 0) {
		return lpush(list,val);
	}
	Node *node = (Node*) malloc(sizeof(Node));
	if (node == NULL) {
		printf("结点内存分配失败");
		exit(1);
	}
	node->val = val;
	node->next = NULL;
	node->pre = list->tail;
	list->tail->next = node;
	list->tail = node;
	list->size = list->size + 1;
}

int lpop(DList *list) {
	if (list->size < 1) {
		return -1;
	}
	Node *node = list->head;
	int retval = list->head->val;
	list->head = list->head->next;
	free(node);
	node = NULL;
	if (list->size == 1) {
		list->tail = NULL;
	} else {
		list->head->pre = NULL;
	}
	list->size = list->size - 1;
	return retval;
}

int rpop(DList *list) {
	if (list->size <= 1) {
		return lpop(list);
	}
	Node *node = list->tail;
	int retval = list->tail->val;
	list->tail = list->tail->pre;
	free(node);
	node = NULL;
	list->tail->next = NULL;
	list->size = list->size - 1;
	return retval;
}

int getsize(DList *list) {
	return list->size;
}

void list_print(DList *list) {
	Node *node = list->head;
	printf("head");
	while (node != NULL) {
		printf("->%d",node->val);
		node = node->next;
	}
	printf("->end\n\n");
}

void list_free(DList *list) {
	while (list->head->next != NULL) {
		// 节省时间 pre tail size 都不处理
		Node *node = list->head->next;
		list->head->next = node->next;
		free(node);
		node = NULL;
	}
	free(list->head);
	list->head = NULL;
	list->tail = NULL;

	free(list);
	list = NULL;
}

int main() {
	DList *list = (DList *) new_dlist();
	lpush(list,1);
	lpush(list,2);
	lpush(list,3);
	lpush(list,4);
	lpush(list,5);
	
	printf("lpop:%d\n",lpop(list));
	printf("rpop:%d\n",rpop(list));
	printf("getsize:%d\n",list->size);
	list_print(list);

	rpush(list,6);
	rpush(list,7);
	rpush(list,8);
	rpush(list,9);
	rpush(list,10);

	printf("lpop:%d\n",lpop(list));
	printf("rpop:%d\n",rpop(list));
	printf("getsize:%d\n",list->size);
	list_print(list);

	list_free(list);
	return 0;
}



