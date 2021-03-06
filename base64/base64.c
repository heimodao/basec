#include<stdio.h>

#include<limits.h>

#include "base64.h"

static unsigned char init_char[64] = {
	'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z',
	'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',
	'0','1','2','3','4','5','6','7','8','9','+','/',
};

// 加密过程中剩余字节数只能为2或者4
static unsigned int encleft[4] = {0,3,0,15};
static unsigned int encright[4] = {0,240,0,192};


// 10亿长度的字符约为4G
unsigned int encrypt_len(unsigned int len) {
	len = ceil(len / 3.0);
	unsigned int max = floor(UINT_MAX) / 4;
	if (floor(UINT_MAX / 4.0) < len) {
		return UINT_MAX;
	}
	return len * 4 + 1;
}

unsigned int decrypt_len(unsigned int len) {
	return (len / 4) * 3;
}

void encrypt_base64(char org[], unsigned int len,char result[]) {
	unsigned int chindex,left,right;
	unsigned int leave_num = 0, count = 0;
	for (int i = 0; count + 3 < UINT_MAX && i < len; i++) {
		if (leave_num == 0) {
			chindex = org[i] >> 2;
		} else {
			left = (org[i - 1] & encleft[leave_num - 1]) << (6 - leave_num);
			right = (org[i] & encright[leave_num - 1]) >> (8 - (6 - leave_num));
			//printf("left:%d\tright:%d\tleave_num:%d\n",left,right,leave_num,org[i]);
			chindex = left | right;
		}
		result[count++] = init_char[chindex];
		if ((i + 1) % 3 == 0) {
			chindex = org[i] & 63;
			result[count++] = init_char[chindex];
		}
		leave_num = (8 * (i + 1)) % 6;
	}
	if (count + 3 < UINT_MAX && len % 3 != 0) {
		chindex = (org[len - 1] & encleft[leave_num - 1]) << (6 - leave_num);
		result[count++] = init_char[chindex];
		if (len % 3 == 1) {
			result[count++] = '=';
		}
		result[count++] = '=';
	}
	//printf("count:%d\n",count);
	result[count++] = '\0';
}


void decrypt_base64(char org[], unsigned int len, char result[]) {
	unsigned char ch[4];
	unsigned int additional = 2, count = 0, chindex;
	for (int i = 0; i + 3 < len; i += 4) {
		for (int j = 0; j < 4; j++) {
			if (org[i + j] >= 'A' && org[i + j] <= 'Z') {
				ch[j] = org[i + j] - 'A';
			} else if (org[i + j] >= 'a' && org[i + j] <= 'z') {
				ch[j] = org[i + j] - 'a' + 26;
			} else if (org[i + j] >= '0' && org[i + j] <= '9') {
				ch[j] = org[i + j] - '0' + 52;
			} else if (org[i + j] == '+') {
				ch[j] = 62;
			} else if (org[i + j] == '/') {
				ch[j] = 63;
			} else {
				ch[j] = 0;
			}
		}
		result[count++] = (ch[0] << 2) | (ch[1] >> 4);
		if (org[i + 2] != '=') {
			result[count++] = (ch[1] << 4) | (ch[2] >> 2);
			if (org[i + 3] != '=') {
				result[count++] = (ch[2] << 6) | ch[3];
			}
		} else {
			result[count++] = ch[1] << 4;
		}
	}
	result[count++] = '\n';
}

