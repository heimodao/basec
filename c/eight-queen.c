#include <stdio.h>

#define QUEENS       8 /*皇后数量*/

// pos[0] = 2 表示 x=0y=3
// line[0] & 11111111 表示棋盘 0无子可落子处 1为有子
void init_queen() {

}

void setpos(int x,int y,int pos[], int lines[]) {
}

void eight_queen() {
	// init
	int pos[QUEENS],lines[QUEENS];
	int key = 0 | 11111111;
	int i;
	for (i = 0; i < QUEENS; i++) {
		pos[i] = -1;
		lines[i] = 0;
	}
	int x,y;
	for (x = pos_x; x < QUEENS; x++) {
		for (y = pos_y; y < QUEENS; y++) {
			if (!can_setpos()) {
				break;
			}
			pos[x] = y;
			setpos(x,y,pos,lines);
		}
		Stack *stack = pop();
		x = (stack->pos_x) - 1;
		y = stack->pos_y;
		free(stack);
		stack = NULL;
	}
}

int main(void) {
	eight_queen(0,0)
	return 0;
}














