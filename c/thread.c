#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

// pthread_create
// pthread_create(&thrd1,NULL,(void*)&thread_function,(void*)&some_argument)

// pthread_exit
// pthread_exit(void *retval)

// pthread_join
// pthread_join(thrd1,NULL)

// create and join test
void print_message_function(void *pstr);
void create_join(void);


// none lock
long sharecnt = 0;
void increase_num(void);
void non_lock(void);


void print_message_function(void *pstr) {
	int i;
	for (i = 0; i < 5; i++) {
		printf("%s:%d\n",(char *)pstr,i);
	}
}

void create_join(void) {
	char *message1 = "thread1";
	char *message2 = "thread2";

	pthread_t thread1,thread2;
	int ret_thread1 = pthread_create(&thread1,NULL,(void*)&print_message_function,(void *)message1);
	int ret_thread2 = pthread_create(&thread2,NULL,(void*)&print_message_function,(void *)message2);

	// 线程创建成功返回0，失败返回失败号
	if (ret_thread1 != 0) {
		printf("线程1创建失败\n");
	} else {
		printf("线程1创建成功\n");
	}
	if (ret_thread2 != 0) {
		printf("线程2创建失败\n");
	} else {
		printf("线程2创建成功\n");
	}

	// 同样pthread_join成功值返回为1
	void *retval;
	int temp1 = pthread_join(thread1,&retval);
	printf("thread1 return value.retval is %ld\n",(long int)retval);
	printf("thread1 return value.temp1 is %d\n",temp1);
	if (temp1 != 0) {
		printf("cannot join with thread1\n");
	}
	printf("thread1 end\n");

	int temp2 = pthread_join(thread2,&retval);
	printf("thread2 return value.retval is %ld\n",(long)retval);
	printf("thread2 return value.temp1 is %d\n",temp2);
	if (temp2 != 0) {
		printf("cannot join with thread2\n");
	}
	printf("thread2 end\n");

}


pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void increase_num(void) {
	long i,temp;
	for (i = 0; i < 10000; i++) {
		/*
		// 加锁
		if (pthread_mutex_lock(&mutex) != 0) {
			perror("pthread_mutex_lock");
			exit(EXIT_FAILURE);
		}
		*/

		temp = sharecnt;
		temp = temp + 1;
		sharecnt = temp;

		/*
		// 解锁
		if (pthread_mutex_unlock(&mutex) != 0) {
			perror("pthread_mutex_unlock");
			exit(EXIT_FAILURE);
		}
		*/
	}

}

void non_lock(void) {
	int ret;
	pthread_t thread1,thread2,thread3;

	ret = pthread_create(&thread1,NULL,(void*) increase_num,NULL);
	ret = pthread_create(&thread2,NULL,(void*) increase_num,NULL);
	ret = pthread_create(&thread3,NULL,(void*) increase_num,NULL);

	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);
	pthread_join(thread3,NULL);

	printf("sharecnt=%ld\n",sharecnt);

}

int main() {
	//create_join();
	non_lock();
	return 0;
}

