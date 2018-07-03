// dlink.h

#ifndef DLINK_H

#define DLINK_H

typedef int val_type;

typedef struct Node {
	val_type val;
	struct Node *prev,*next;
} Node;

typedef struct DLink {
	char *name;
	unsigned long size;
	struct Node *head,*tail;
} DLink;


DLink* dlink_init(char *name);

// push
val_type dlink_lpush(DLink *dlink,val_type val);

val_type dlink_rpush(DLink *dlink,val_type val);

// get
val_type dlink_getpos(DLink *dlink,val_type pos);

val_type dlink_getleft(DLink *dlink);

val_type dlink_getright(DLink *dlink);

// find
val_type dlink_isfind(DLink *dlink,val_type val);

// pop
val_type dlink_valpop(DLink *dlink,val_type val);

val_type dlink_lpop(DLink *dlink);

val_type dlink_rpop(DLink *dlink);

// reverse
void dlink_reverse(DLink *dlink);

// prval_type
void dlink_prval_type(DLink *dlink);

// print
void dlink_print(DLink *dlink);

// free
void dlink_free(DLink *dlink);

#endif
