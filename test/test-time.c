#include<stdio.h>
#include<time.h>

int main(void) {
	time_t now;
	time(&now);
	printf("now:%ju\n", now);

	struct tm beg = *localtime(&now);
	printf("%04d-%02d-%02d\n",1900 + beg.tm_year,1 + beg.tm_mon,beg.tm_mday);
	printf("mktime:%ld\n", mktime(&beg));

	// beg
	beg.tm_hour = 0;
	beg.tm_min = 0;
	beg.tm_sec = 0;
	beg.tm_mday = 1;

	double seconds = difftime(now, mktime(&beg));

	printf("%.f seconds have passed since the beginning of the month\n",seconds);
	printf("\nProgram last compiled at %s on %s\n",__TIME__,__DATE__);

	time_t epoch = 0;
	printf("%ld seconds since the epoch began\n", (long) epoch);
	printf("%s",asctime(gmtime(&epoch)));
	return 0;
}

