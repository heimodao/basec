// dlink.h

#ifndef DLINK_H

#define DLINK_H


typedef struct Node {
	int val;
	struct Node *prev,*next;
} Node;

typedef struct DLink {
	char *name;
	int size;
	struct Node *head,*tail;
} DLink;


DLink* dlink_init(char *name);

// push
int dlink_lpush(DLink *dlink,int val);

int dlink_rpush(DLink *dlink,int val);

// get
int dlink_getleft(DLink *dlink);

int dlink_getright(DLink *dlink);

// find
int dlink_isfind(DLink *dlink,int val);

// pop
int dlink_lpop(DLink *dlink);

int dlink_rpop(DLink *dlink);

// reverse
void dlink_reverse(DLink *dlink);

// print
void dlink_print(DLink *dlink);

// free
void dlink_free(DLink *dlink);

#endif
