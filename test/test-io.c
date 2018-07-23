#include<stdio.h>

/*
 * refrence: https://www.tutorialspoint.com/cprogramming/c_file_io.htm
*/
int main(void) {
	/* write
	FILE *fp;

	fp = fopen("iotest.txt", "w+");
	fprintf(fp, "This is testing for printf ...\n");
	fputs("This is testing for puts ...\n", fp);
	fclose(fp);
	*/

	// read
	FILE *fp;
	char buff[255];
	fp = fopen("iotest.txt", "r");
	fscanf(fp, "%s", buff);
	printf("1:%s\n", buff);
	
	fgets(buff, 255, (FILE*)fp);
	printf("2:%s\n", buff);

	fgets(buff, 255, (FILE*)fp);
	printf("3:%s\n", buff);
	fclose(fp);
}
