#include <stdio.h>


#define QUEENS       8 /*皇后数量*/
#define IS_OUTPUT    1 /*(IS_OUTPUT=0 or 1)，Output用于选择是否输出具体解,为1输出，为0不输出*/


int A[QUEENS], B[QUEENS * 3 + 1], C[QUEENS * 3 + 1], k[QUEENS + 1][QUEENS + 1];
int inc, *a = &A[QUEENS], *b = &B[QUEENS], *c = &C[QUEENS];

void lay(int i) {
	int j = 0, t, u;
	while (++j <= QUEENS) {
		if (a[j] + b[j - i] + c[j + i] == 0) {
			k[i][j] = a[j] = b[j - i] = c[j + i] = 1;
			if (i < QUEENS) {
				lay(i + 1);
			} else {
				++inc;
				if (IS_OUTPUT) {
					for (printf("(%d)\n", inc), u = QUEENS + 1; --u; printf("\n")) {
						for (t = QUEENS + 1; --t; ) {
							k[t][u] ? printf("Q ") : printf("+ ");
						}
					}
					printf("\n\n\n");
				}
			}
			a[j] = b[j - i] = c[j + i] = k[i][j] = 0;
		}
	}
}

// 方法一(维基百科)
// https://zh.wikipedia.org/wiki/%E5%85%AB%E7%9A%87%E5%90%8E%E9%97%AE%E9%A2%98
int main(void) {
	lay(1);
	printf("%d皇后共计%d个解\n", QUEENS, inc);
	return 0;
}


