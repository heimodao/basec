#include<stdio.h>
#include<math.h>

#include "base64.h"


int main() {
	int len;

	char org[] = "1358124684"; //MTM1ODEyNDY4NA==
	for (len = 0; org[len] != '\0'; len++);
	char result1[encrypt_len(len)];
	encrypt_base64(org,len, result1);
	printf("org:%s\tlen:%d\tencrypt:%s\n",org, encrypt_len(len), result1);

	char dec[] = "MTM1ODEyNDY4NA==";
	for (len = 0; dec[len] != '\0'; len++);
	char result2[decrypt_len(len)];
	decrypt_base64(dec, len, result2);
	printf("org:%s\tlen:%d\tdecrypt:%s\n",dec, decrypt_len(len), result2);
	return 0;
}

