// 二叉搜索树
#include<stdio.h>
#include<stdlib.h>

typedef struct SearchTree {
	int val;
	struct SearchTree *parent,*lchild,*rchild;
} SearchTree;

int insert(SearchTree **tree,int val,SearchTree *parent) {
	SearchTree *node = (SearchTree*) malloc(sizeof(SearchTree));
	if (node == NULL) {
		printf("分配内存失败:%d\n",val);
		return 0;
	}
	node->val = val;
	node->lchild = NULL;
	node->rchild = NULL;
	if ((*tree) == NULL) {
		node->parent = parent;
		(*tree) = node;
		return 1;
	}
	if (val < (*tree)->val && (*tree)->lchild == NULL) {
		node->parent = (*tree);
		(*tree)->lchild = node;
		return 1;
	}
	if (val > (*tree)->val && (*tree)->rchild == NULL) {
		node->parent = (*tree);
		(*tree)->rchild = node;
		return 1;
	}
	free(node);
	if (val < (*tree)->val) {
		return insert(&(*tree)->lchild,val,(*tree));
	}
	if (val > (*tree)->val) {
		return insert(&(*tree)->rchild,val,(*tree));
	}
	return 1;
}

// 先序遍历:中->左->右
void pre_order(SearchTree *tree) {
	if (tree == NULL) {
		return;
	}
	printf("->%d",tree->val);
	if (tree->lchild != NULL) {
		pre_order(tree->lchild);
	}
	if (tree->rchild != NULL) {
		pre_order(tree->rchild);
	}
}

// 中序遍历:左->中->右
void middle_order(SearchTree *tree) {
	if (tree == NULL) {
		return;
	}
	if (tree->lchild != NULL) {
		middle_order(tree->lchild);
	}
	printf("->%d",tree->val);
	if (tree->rchild != NULL) {
		middle_order(tree->rchild);
	}
}

// 后序遍历:左->右->后
void post_order(SearchTree *tree) {
	if (tree == NULL) {
		return;
	}
	if (tree->lchild != NULL) {
		post_order(tree->lchild);
	}
	if (tree->rchild != NULL) {
		post_order(tree->rchild);
	}
	printf("->%d",tree->val);
}

// 搜索
int search(SearchTree *tree,int val) {
	if (tree == NULL) {
		return 0;
	}
	if (val < tree->val) {
		return search(tree->rchild,val);
	}
	if (val == tree->val) {
		return 1;
	}
	if (val > tree->val) {
		return search(tree->rchild,val);
	}
}

int main(void) {

	SearchTree *tree = NULL;
	insert(&tree,8,NULL);
	insert(&tree,3,NULL);
	insert(&tree,10,NULL);
	insert(&tree,1,NULL);
	insert(&tree,6,NULL);
	insert(&tree,4,NULL);
	insert(&tree,7,NULL);
	insert(&tree,14,NULL);
	insert(&tree,13,NULL);

	printf("先序排列:");
	pre_order(tree);
	printf("\n");

	printf("中序排列:");
	middle_order(tree);
	printf("\n");

	printf("后序排列:");
	post_order(tree);
	printf("\n");

	printf("是否找到%d:%d\n",10,search(tree,10));
	printf("是否找到%d:%d\n",15,search(tree,15));

	return 0;
}
