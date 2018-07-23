#include<stdio.h>
#include<time.h>

int main(void) {
	time_t now;
	time(&now);

	struct tm beg = *localtime(&now);

	/*
	// beg
	beg.tm_hour = 0;
	beg.tm_min = 0;
	beg.tm_sec = 0;
	beg.tm_mday = 1;
	//beg.tm_mon = 5;
	//beg.tm_year = 2018;

	double seconds = difftime(now,mktime(&beg));
	*/
	printf("%04d-%02d-%02d",1900 + beg.tm_year,1 + beg.tm_mon,beg.tm_mday);
	printf("step1::%ld\n",mktime(&beg));
	//printf("%f seconds have passed since the beginning of the month\n",seconds);
	printf("\nProgram last compiled at %s on %s\n",__TIME__,__DATE__);
	return 0;
}

