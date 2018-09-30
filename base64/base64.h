#ifndef _H_BASE64

#define _H_BASE64

#include<math.h>

unsigned int encrypt_len(unsigned int len);

unsigned int decrypt_len(unsigned int len);

// 加密
void encrypt_base64(char org[], unsigned int len, char result[]);

// 解密
void decrypt_base64(char org[], unsigned int len, char result[]);



#endif
