// author : linkzw
// date	: 2018-04-09
// purpose : 链表
#include<stdio.h>

// 建议参考stack-list.c 以及test-link.c
typedef struct _Node {
	int data;
	struct Node *next;
} Node;

// 初始化
Node init_node() {
	Node *pNode;
	pNode = (Node *)malloc(sizeof(Node));
	if (pNode == NULL) {
		printf("链表初始化失败");
		return;
	}
	pNode->next = NULL;
}

// 获取链表规格
int getnode_size(Node *pNode) {
	Node *p = pNode->next;
	int count = 0;
	while(p != NULL) {
		count++;
		p = p->next;
	}
	return count;
}

// 从pos插入 pos=0头插 pos=node.size为尾插
Node insert_pos(Node *pNode, int pos, int num) {
	int count = 1;
	Node *prev = pNode, *p = pNode, *node;
	node = (Node *)malloc(sizeof(Node));
	while(p != NULL && count++ <= pos) {
		prev = p;
		p = p->next;
	}
//	if (p != NULL) { // pos > node.size 默认尾插
		prev->next = node;
		node->next = p;
		node->data = num;
		return node->data;
//	}
}

// 头插
Node insert_head(Node *pNode, int num) {
	Node *p, *node, *pnode = pNode;
	node = (Node *)malloc(sizeof(Node));
	p = pNode->next;
	pNode->next = node;
	node->next = p;
	return node;
}

// 尾插
Node insert_tail(Node *pNode, int num) {
	Node *node, *ptail_node = pNode;
	node = (Node *)malloc(sizeof(Node));
	while(ptail_node->next != NULL) {
		ptail_node = ptail_node->next;
	}
	node = ptail_node->next;
	node->data = num;
	node->next = NULL;
	return node;
}

// 根据pos获取node pos > node.size 获取尾部数据
Node getnode_pos(Node *pNode, int pos) {
	Node *prev, *node = pNode;
	int index = 0;
	while(node != NULL && index++ <= pos) {
		prev = node;
		node = node->next;
	}
	if (node != NULL) {
		return node;
	}
	return perv;
}

// 根据pos获取数据
int getdata_pos(Node *pNode, int pos) {
	Node *prev, *node = pNode;
	int index = 0;
	while(node != NULL && index++ <= pos) {
		prev = node;
		node = node->next;
	}
	if (node != NULL) {
		return node->data;
	}
	return -1;
}

// 删除pos = num
int delete_node_pos(Node *pNode, int pos) {
	Node *prev, *node = pNode;
	int index = 0;
	while(node->next != NULL && index++ <= pos) {
		prev = node;
		node = node->next;
	}
	if (node != NULL) {
		prev->next = node->next;
		int retnum = node->data;
		free(node);
		return retnum;
	}
}

// 删除data = num
int delete_node_num(Node *pNode, int num) {
	Node *prev = pNode, *pnode = pNode;
	while(pnode != NULL && pnode->data != num) {
		prev = pode;
		pnode = pnode->next;
	}
	if (pnode != NULL) {
		prv->next = pnode->next;
		int retnum = pnode->data;
		free(pnode);
		return retnum;
	}
	return -1;
}

// 销毁链表 完全不可用
void destroy_node(Node *pNode) {
	Node *p, *pnode = pNode;
	if (pnode == NULL) {
		return;
	}
	while(pnode != NULL) {
		*p = *pnode->next;
		free(pnode);
		pnode = p;
	}
}

// 清空链表 后续可用
void clear_node(Node *pNode) {
	Node *pnode = pNode->next;
	while(pnode != NULL) {
		*p = *pnode->next;
		free(pnode);
		pnode = p;
	}
	pNode->next = NULL;
}

// 批量修改
void patch_change(Node *pNode, int num) {
	Node *pnode = pNode->next;
	while(pnode != NULL) {
		pnode->data = num;
		pnode = pnode->next;
	}
}

int main(void) {
	int arr[10] = {1,2,3,4,5,6,7,8,9,10};
	init_node();
	return 0;
}
