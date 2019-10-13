//递归函数实现strlen
#include <stdio.h>
#include <stdlib.h>
int Strlen (char* str){
	if (*str == '\0'){
		return 0;
	}
	return 1 + Strlen(str + 1);
}
int main(){
	char a[] = "abcdef";
	int len = Strlen(a);
	printf("字符串长度为:%d\n", len);
	system("pause");
}

//非递归实现strlen
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int Strlen(char* str){
	int len=0;
	while (*str){
		if (*str != '\0'){
			len++;
			str++;
		}
	}return len;
}
int main(){
	char a[] = "abcef";
	int len = Strlen(a);
	printf("字符串长度为:%d\n", len);
	system("pause");
}