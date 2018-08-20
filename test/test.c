#include<stdio.h>
#include<stdlib.h>

int main(void) {
	FILE *fp = fopen("test.txt", "r");
	if (fp == NULL) {
		perror("File Opening Failed!");
		return EXIT_FAILURE;
	}
	int c;
	while ((c = fgetc(fp)) != EOF) {
		putchar(c);
	}

	if (ferror(fp)) {
		puts("IO error when reading");
	} else if (feof(fp)) {
		puts("End of file readed successfully");
	}

	fclose(fp);
}
