#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

char* Strcpy(char* dest, const char* src){
	assert(dest != NULL); //字符串不为空
	char* ret = dest;
	while (*dest++ = *src++){  //从源字符串复制到目标空间中
		;
	}
	return ret;
}

int main(){
	char dest[20] = "abcde";
	const char* src = "hello";
	char* ret1 = Strcpy(dest, src);
	printf("%s\n", ret1);
	char* ret2 = strcpy(dest, src);
	printf("%s\n", ret2);
	system("pause");
}