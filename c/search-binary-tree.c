// 二叉搜索树
#include<stdio.h>
#include<stdlib.h>

typedef struct SearchTree {
	int val;
	SearchTree *parent,*lchild,*rchild;
} SearchTree;

int insert(Node *node,int val) {
	if (node->parent == NULL && node->val != 0) {
		node->val = val;
		node->lchild = NULL;
		node->right = NULL;
	}
}
