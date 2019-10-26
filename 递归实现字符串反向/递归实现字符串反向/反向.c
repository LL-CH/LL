#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
void reverse_string(char * string){
	if ('\0' != *(++string)){    //判断字符是否为'\0'
		reverse_string(string);
	}
	printf("%c", *(string - 1));   //输出'\0'前一个字符,即字符串的最后一个
}
int main(){	
	char arr[]= "18522354";
	
	reverse_string(arr);
	printf("\n" );
	system("pause");
}