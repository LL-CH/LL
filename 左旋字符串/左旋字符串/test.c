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
		char tmp = str[0];  //取每个字符串的第一位
		for ( j = 0; j < len; j++)
		{
			str[j] = str[j + 1];  //将字符串中后一位的值赋给前一位
		}
		str[len - 1] = tmp;  //将字符串第一位的值赋给最后一位
	}
}


int main(){
	char str[] = "ABCDE";
	printf("旋转前:%s\n", str);
	int k=0;
	int len = strlen(str);
	printf("输入逆转数:");
	scanf("%d", &k);
	left_handed(str, k, len);
	printf("旋转后:%s\n", str);
	system("pause");
	return 0;
}