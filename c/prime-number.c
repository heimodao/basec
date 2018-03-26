#include<stdio.h>
#include<stdlib.h>

void prime_number(const int num) {
	if (num < 3) {
		printf("error input");
		return;
	}
	unsigned long first_prime = 2;
	unsigned long second_prime = 3;
	unsigned long *prime_array = (unsigned long *)malloc(num * sizeof(unsigned long));
	if (prime_array == NULL) {
		printf("can\'t malloc memory!!!\n");
		exit(1);
	}
	*prime_array = 2;
	*(prime_array + 1) = 3;
	unsigned int count = 2;
	unsigned long i;
	for (i = second_prime + first_prime; count < num; i = i + first_prime) {
		unsigned int j;
		for(j = 0; j < count; j++) {
			if ((i % *(prime_array + j)) == 0) {
				break;
			}
		}
		if (j == count) {
			*(prime_array + count++) = i;
		}
	}
	unsigned int index;
	for (index = 0; index < num; index++) {
		printf("第%d个质数:%ld\n",index + 1,*(prime_array + index));
	}
	free(prime_array);
}

int main() {
	printf("请输入求取质数个数:");
	unsigned int num = 10;
	scanf("%d", &num);
	prime_number(num);
	return 0;
}
