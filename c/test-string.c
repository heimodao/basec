#include<stdio.h>
#include<stdlib.h>

void insert(char *str,char ch) {
	int len;
	for (len = 0; str[len] != '\0';len++);
	*(str + len) = ch;
	*(str + len + 1) = '\0';
}

int main() {
	char str[11] = "0123456789";
	printf("%s\n",str);
	char *pstr = str;
	insert(pstr,'a');
	printf("%s\n",pstr);
	return 0;
}
