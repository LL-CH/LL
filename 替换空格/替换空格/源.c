#include<stdio.h>
#include <stdlib.h>

#include<string.h>


void replaceSpace(char *str, int length) {            // ����ո�ĸ���           
 int space_num = 0;
 for(int i = 0; i < length; ++i)
 { 
	 if(str[i] == ' ')
		 space_num++;
 } 
 // �Ӻ���ǰ������Ų���ַ��������ո��滻Ϊ%20
 for(int i = length-1; i >= 0; --i)
 { 
	 if(str[i] == ' ')
	 { 
		 space_num--;
		 str[i+space_num*2] = '%';
		 str[i+space_num*2+1] = '2';
		 str[i+space_num*2+2] = '0'; 
	 }
	 else
	 { 
		 str[i + space_num*2] = str[i];
	 }
 }
}

int main(){
	char* str = "we are happy";
	int len = strlen(str);
	replaceSpace(str, len);
	printf("%s\n",str);

	system("pause");
}