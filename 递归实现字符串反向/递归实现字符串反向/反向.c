#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
void reverse_string(char * string){
	if ('\0' != *(++string)){    //�ж��ַ��Ƿ�Ϊ'\0'
		reverse_string(string);
	}
	printf("%c", *(string - 1));   //���'\0'ǰһ���ַ�,���ַ��������һ��
}
int main(){	
	char arr[]= "18522354";
	
	reverse_string(arr);
	printf("\n" );
	system("pause");
}