#include<stdio.h>

// input			output
// +12345			12345
// la33				0
// 测试用例
int str2int(char str[]) {
	//cstr = str.c_str()
	//if (cstr == NULL || *cstr == "\0")
	int index = 0;
	int sign = 0;// 0为正 1为负
	int i;
	for (i = 0; str[i] != '\0'; i++) {
		if (str[i] >= '0' && str[i] <= '9') {
			int num = (int)(str[i] - '0');
			index = index * 10 + num;
		} else {
			if (i == 0 && (str[i] == '+' || str[i] == '-')) {
				sign = (str[i] == '+') ? 0 : 1;
			} else {
				return 0;
			}

		}
	}
	return (sign == 0) ? index : -index;
}

/* 牛客网通过案例
int StrToInt(string cstr) {
        const char *str = cstr.c_str();
        int index = 0;
        int sign = 0;// 0为正 1为负
        int i;
        for (i = 0; *(str + i) != '\0'; i++) {
            if (*(str + i) >= '0' && *(str + i) <= '9') {
                int num = (int)(*(str + i) - '0');
                index = index * 10 + num;
            } else {
                if (i == 0 && (*(str + i) == '+' || *(str + i) == '-')) {
                    sign = (*(str + i) == '+') ? 0 : 1;
                } else {
                    return 0;
                }

            }
        }
        return (sign == 0) ? index : -index;
    }
*/

int main(void) {
	char *str[3] = {"+12345","la33","-12345"};
	int i;
	for (i = 0; i < 3; i++) {
		printf("%s\t%d\n", *(str + i), str2int(*(str + i)));
	}
	return 0;
}
