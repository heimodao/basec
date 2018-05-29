#include<stdio.h>
#include<stdlib.h>

// 二叉搜索树
typedef struct SearchTree {
	int val;
	struct SearchTree *parent,*lchild,*rchild;
} SearchTree;

typedef struct Node {
	struct SearchTree *tree;
	struct Node *next;
} Node;

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

void tree_free(SearchTree *tree) {
	if (tree != NULL) {
		if (tree->lchild != NULL) {
			tree_free(tree->lchild);
		}
		if (tree->rchild != NULL) {
			tree_free(tree->rchild);
		}
		free(tree);
		tree = NULL;
	}
	return;
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

Node* node_init() {
	Node *node = (Node *) malloc(sizeof(Node));
	if (node == NULL) {
		printf("栈初始化失败\n");
		exit(0);
	}
	node->next = NULL;
	return node;
}

int node_isnull(Node *node) {
	return node->next == NULL;
}

// common method : stack queue
void node_free(Node *node) {
	Node *temp = node->next;
	while(temp != NULL) {
		node->next = temp;
		free(temp);
		temp = node->next;
	}
	free(node);
}

// pop head
SearchTree* node_pop(Node *node) {
	Node *ret = node->next;
	node->next = ret->next;
	SearchTree *tree = ret->tree;
	free(ret);
	return tree;
}

// 栈后进先出 简单实现：头插
void head_push(Node *stack,SearchTree *tree) {
	Node *node = (Node *) malloc(sizeof(Node));
	if (node == NULL) {
		printf("栈内存分配失败:%d\n",tree->val);
		exit(0);
	}
	node->tree = tree;
	node->next = stack->next;
	stack->next = node;
}


// 队列先进先出: 尾插
void tail_push(Node *queue,SearchTree *tree) {
	Node *node = (Node *) malloc(sizeof(Node));
	if (node == NULL) {
		printf("栈内存分配失败:%d\n",tree->val);
		exit(0);
	}
	node->tree = tree;

	Node *tail = queue;
	while(tail->next != NULL) {
		tail = queue->next;
	}
	node->next = tail->next;
	tail->next = node;
}

// DFS深度优先:
// 1.首先以一个未被访问过的顶点作为其实顶点，沿当前顶点的边走到未访问过的顶点
// 2.当没有未访问过的顶点，回到上一个顶点，直到所有顶点被访问过
void deep_first_search(SearchTree *tree,Node *node) {
	if (tree == NULL) {
		if (node_isnull(node)) {
			return;
		}
		return deep_first_search(node_pop(node),node);
	}
	printf("->%d",tree->val);
	if (tree->lchild != NULL) {
		if (tree->rchild != NULL) {
			head_push(node,tree->rchild);
		}
		deep_first_search(NULL,node);
	}
}

// BFS
// 1.首先将根节点放入队列中。
// 2.从队列中取出第一个节点，并检验它是否为目标。
//		如果找到目标，则结束搜寻并回传结果。
//		否则将它所有尚未检验过的直接子节点加入队列中。
// 3.若队列为空，表示整张图都检查过了——亦即图中没有欲搜寻的目标。结束搜寻并回传“找不到目标”。
// 4.重复步骤2
void breadth_first_search(SearchTree *tree,Node *node) {
	if (tree == NULL) {
		if (node_isnull(node)) {
			return;
		}
		return breadth_first_search(node_pop(node),node);
	}
	printf("->%d",tree->val);
	if (tree->lchild != NULL) {
		if (tree->lchild != NULL) {
			tail_push(node,tree->lchild);
		}
		if (tree->rchild != NULL) {
			tail_push(node,tree->rchild);
		}
		breadth_first_search(NULL,node);
	}
}

int main(void) {

	SearchTree *tree;
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

	Node *stack = node_init();
	deep_first_search(tree,stack);
	node_free(stack);
	
	Node *queue = node_init();
	breadth_first_search(tree,queue);
	node_free(queue);

	tree_free(tree);

	return 0;
}
