#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

char* Strcat(char* dest,const char* src){
	assert(dest && src); //字符串不为空
	char* ret = dest;
	while (*dest){//找到目标空间中的'\0'
		dest++;
	}
	while (*dest++ = *src++){  //从目标空间中的'\0'的位置将源字符串复制到后面的位置
		;
	}
	return ret;
}

int main(){
	char dest[20] = "abcde";
	const char* src = "hello";
	char* ret1=Strcat(dest,src);
	printf("%s\n", ret1);
	char* ret2 = strcat(dest, src);
	printf("%s\n", ret2);
	system("pause");
}