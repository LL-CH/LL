#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

char* Strcat(char* dest,const char* src){
	assert(dest && src); //�ַ�����Ϊ��
	char* ret = dest;
	while (*dest){//�ҵ�Ŀ��ռ��е�'\0'
		dest++;
	}
	while (*dest++ = *src++){  //��Ŀ��ռ��е�'\0'��λ�ý�Դ�ַ������Ƶ������λ��
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