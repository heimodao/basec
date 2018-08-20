// #define __STDC_LIB_EXT1__ 1 
#include<stdio.h>
#include<time.h>
#include<stdint.h>		// uintmax_t

int main(void) {
	time_t now;
	time(&now);
	printf("now:%ju\n", now);
	printf("current time is %s(%ju seconds since the Eporch)\n", asctime(gmtime(&now)), (uintmax_t)now);
	printf("local: %s\n", asctime(localtime(&now)));

#ifdef __STDC_LIB_EXT1__
	struct tm buf;
	char str[26];
	asctime_s(str, sizeof(str), gmtime_s(&now, &buf));
	printf("UTC: %s\n", str);
	asctime_s(str, sizeof(str), localtime_s(&now, &buf));
	printf("local: %s\n", str);
#endif

	struct tm beg = *localtime(&now);
	printf("%04d-%02d-%02d\n",1900 + beg.tm_year,1 + beg.tm_mon,beg.tm_mday);
	printf("1900.01.01 seconds:%ld\n",mktime(&beg));

	// difftime
	beg.tm_hour = 0;
	beg.tm_min = 0;
	beg.tm_sec = 0;
	beg.tm_mday = 1;
	double seconds = difftime(now,mktime(&beg));
	printf("%f seconds have passed since the beginning of the month\n",seconds);

	// clock
	clock_t t1 = clock();
	unsigned long int sum = 0;
	for (int i = 0; i < 1000000; i++) {
		sum += 2;
	}
	clock_t t2 = clock();
	double dur = 1000.0 * (t2 - t1) / CLOCKS_PER_SEC;
	printf("sum: %ld --> dur: %lf ms\n",sum, dur);

	printf("\nProgram last compiled at %s on %s\n",__TIME__,__DATE__);
	return 0;
}

