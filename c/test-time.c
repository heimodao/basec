#include<stdio.h>
#include<time.h>

int main(void) {
	time_t now;
	time(&now);

	struct tm beg = *localtime(&now);

	// beg
	beg.tm_hour = 0;
	beg.tm_min = 0;
	beg.tm_sec = 0;
	beg.tm_mday = 1;
	//beg.tm_mon = 5;
	//beg.tm_year = 2018;

	double seconds = difftime(now,mktime(&beg));
	printf("%f seconds have passed since the beginning of the month\n",seconds);
	return 0;
}

