#include<stdio.h>

#include "dlink.h"


int main(void) {
	
	DLink *dlink = dlink_init("test1");
	
	// lpush
	dlink_lpush(dlink,1);
	dlink_lpush(dlink,2);
	dlink_lpush(dlink,3);
	dlink_lpush(dlink,4);
	dlink_lpush(dlink,5);
	dlink_lpush(dlink,6);
	dlink_lpush(dlink,7);
	dlink_lpush(dlink,8);
	
	// rpush
	dlink_rpush(dlink,9);
	dlink_rpush(dlink,10);
	dlink_rpush(dlink,11);
	dlink_rpush(dlink,12);
	dlink_rpush(dlink,13);
	dlink_rpush(dlink,14);
	dlink_rpush(dlink,15);
	dlink_rpush(dlink,16);

	dlink_print(dlink);

	// get
	printf("getpos:%d=>%d\n",1,dlink_getpos(dlink,1));
	printf("getpos:%ld=>%d\n",dlink->size,dlink_getpos(dlink,dlink->size));
	printf("getpos:%d=>%d\n",2,dlink_getpos(dlink,2));
	printf("getpos:%d=>%d\n",5,dlink_getpos(dlink,5));
	printf("getpos:%d=>%d\n",6,dlink_getpos(dlink,6));
	printf("getpos:%d=>%d\n",7,dlink_getpos(dlink,7));

	printf("getleft:%d\n",dlink_getleft(dlink));
	printf("gettight:%d\n",dlink_getright(dlink));

	// find
	int temp1 = 10, temp2 = 15, temp3 = 18;
	printf("find->%d:%d\n",temp1,dlink_isfind(dlink,temp1));
	printf("find->%d:%d\n",temp2,dlink_isfind(dlink,temp2));
	printf("find->%d:%d\n",temp3,dlink_isfind(dlink,temp3));

	// pop
	printf("valpop:%d=>%d\n",13,dlink_valpop(dlink,13));
	printf("lpop:%d\n",dlink_lpop(dlink));
	printf("rpop:%d\n",dlink_rpop(dlink));

	// print
	dlink_print(dlink);

	printf("\nreverse:\n");
	// reverse
	dlink_reverse(dlink);

	//print
	dlink_print(dlink);

	printf("\nsecond-reverse:\n");
	// reverse
	dlink_reverse(dlink);

	//print
	dlink_print(dlink);


	dlink_free(dlink);

	return 0;
}
