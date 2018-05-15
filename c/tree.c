// 二叉树结构，先序、中序、后序
#include<stdio.h>
#include<stdlib.h>

typedef struct BinaryTree {
	char val;
	struct BinaryTree *parent,*lchild,*rchild;
	int size;
	char *name;
} BinaryTree;

BinaryTree* init(char *name,int val) {
	BinaryTree *tree = (BinaryTree*)malloc(sizeof(BinaryTree));
	if (tree == NULL) {
		printf("%s:创建节点失败\n",name);
		exit(1);
	}
	tree->size = 0;
	tree->name = name;
	tree->val = val;
	tree->parent = NULL;
	tree->lchild = NULL;
	tree->rchild = NULL;
	return tree;
}

/*
 *	BinaryTree *parent = (BinaryTree*)malloc(sizeof(BinaryTree));
	BinaryTree *lchild = (BinaryTree*)malloc(sizeof(BinaryTree));
	BinaryTree *rchild = (BinaryTree*)malloc(sizeof(BinaryTree));

	if (tree == NULL || parent == NULL || lchild == NULL || rchild == NULL) {
 */
int insert_tree(BinaryTree *tree,char val) {
	
}

// 字符串这样有风险
void insert(char *str,char ch) {
	int len;
	for (len = 0; *(str + len) != '\0';len++);
	*(str + len) = ch;
	*(str + len + 1) = '\0';
}

// 先序排列
void firstmid_sort(BinaryTree tree,char *str) {
	insert(str,tree->val);
	if (tree->lchild != NULL) {
		firstmid_sort(tree->lchild,str);
	}
	if (tree->lchild != NULL) {
		firstmid_sort(tree->rchild,str);
	}
}

// 中序排列
void secondmid_sort(BinaryTree tree,char *str) {
	if (tree->lchild != NULL) {
		firstmid_sort(tree->lchild,str);
	}
	insert(str,tree->val);
	if (tree->lchild != NULL) {
		firstmid_sort(tree->rchild,str);
	}
}

// 后序排列
void lastmid_sort(BinaryTree tree,char *str) {
	if (tree->lchild != NULL) {
		firstmid_sort(tree->lchild,str);
	}
	if (tree->lchild != NULL) {
		firstmid_sort(tree->rchild,str);
	}
	insert(str,tree->val);
}


int main() {
	
}
