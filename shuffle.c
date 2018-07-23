#include<stdio.h>

#define MAXCARD 54

int gen_random(int min,int max);
void swap(int *a,int *b);
void cards_init(int cards[]);
void cards_print(int cards[]);
void shuffle(int cards[]);

int gen_random(int min,int max) {
	return (rand() % (max - min + 1)) + min;
}

void swap(int *a,int *b) {
	if (*a == *b) {
		return;
	}
	*a = (*a) ^ (*b);
	*b = (*a) ^ (*b);
	*a = (*a) ^ (*b);
}

void cards_init(int cards[]) {
	int i;
	for (i = 0; i < MAXCARD; i++) {
		cards[i] = i + 1;
	}
}

void cards_print(int cards[]) {
	int i;
	for (i = 0; i < MAXCARD; i++) {
		printf("%d\t",cards[i]);
		if (i % 10 == 9) {
			printf("\n");
		}
	}
	printf("\n");
}

void shuffle(int cards[]) {
	int count = 100;//gen_random(0,MAXCARD - 1); // 低于20时有将近27个卡牌位置没有变动
	printf("rand:%d\n",count);
	int i;
	for (i = 0; i < MAXCARD; i++) {
		int random = gen_random(0,MAXCARD-1);
		swap(&cards[i],&cards[random]);
	}
}

void check_diff(int cards[]) {
	int i,count = 0;
	for (i = 0; i < MAXCARD; i++) {
		if (cards[i] == i + 1) {
			count++;
		}
	}
	printf("\n共有%d个扑克牌位置没变\n",count);
}

int main() {
	int cards[MAXCARD];
	
	cards_init(cards);
	cards_print(cards);

	shuffle(cards);
	cards_print(cards);

	check_diff(cards);
	return 0;
}
