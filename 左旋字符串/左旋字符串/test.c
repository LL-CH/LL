#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void left_handed(char* str,int k,int len){
	k %= len;
	int i = 0;
	for ( i = 0; i < k; i++)  
	{
		int j = 0;
		char tmp = str[0];  //ȡÿ���ַ����ĵ�һλ
		for ( j = 0; j < len; j++)
		{
			str[j] = str[j + 1];  //���ַ����к�һλ��ֵ����ǰһλ
		}
		str[len - 1] = tmp;  //���ַ�����һλ��ֵ�������һλ
	}
}


int main(){
	char str[] = "ABCDE";
	printf("��תǰ:%s\n", str);
	int k=0;
	int len = strlen(str);
	printf("������ת��:");
	scanf("%d", &k);
	left_handed(str, k, len);
	printf("��ת��:%s\n", str);
	system("pause");
	return 0;
}