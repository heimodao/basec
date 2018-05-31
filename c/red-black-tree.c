#include<stdio.h>
#include<stdlib.h>

#define RED 0
#define BLACK 1

typedef struct RBTree {
	int val;
	int color : 1;
	struct RBTree *parent,*lchild,*rchild;
} RBTree;


int main() {
	return 0;
}
