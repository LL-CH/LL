#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//�ַ�����ת
void reverse(char* left,char* right){
	while (left < right){
		char tmp = *right;
		*right = *left;
		*left = tmp;
		++left;
		--right;
	}
}
 
//�ַ�������
void Left_rotate(char* str, int k){
	int len = strlen(str);
	k %= len;
	reverse(str, str + k - 1);
	reverse(str + k, str + len - 1);
	reverse(str, str + len - 1);
}

int IsRotate(char* dest,const char* src){
	int len = strlen(dest);
	while (len--){
		Left_rotate(dest, 1);  //ÿ����һ�κ���src�Ƚ�,���Ƿ���ͬ
		if (!strcmp(dest, src)){ //����ͬ,strcmp=0,����1
			return 1;
		}
	}return 0;  //��ͬ����0
}

int main(){
	char dest[30];
	char src[30];
	scanf("%s", dest);
	scanf("%s", src);
	int result=IsRotate(dest, src);
	printf("%d\n", result);
	system("pause");
	return 0;
}