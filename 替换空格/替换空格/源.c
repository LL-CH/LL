#include<stdio.h>
#include <stdlib.h>
#include<string.h>

//char* replaceSpace(char *str, int length) {            // 计算空格的个数           
// int space_num = 0;
// for(int i = 0; i < length; ++i)
// { 
//	 if(str[i] == ' ')
//		 space_num++;
// } 
// // 从后往前，依次挪动字符，遇到空格替换为%20
// for(int i = length-1; i >= 0; --i)
// { 
//	 if(str[i] == ' ')
//	 { 
//		 space_num--;
//		 str[i+space_num*2] = '%';
//		 str[i+space_num*2+1] = '2';
//		 str[i+space_num*2+2] = '0'; 
//	 }
//	 else
//	 { 
//		 str[i + space_num*2] = str[i];
//	 }
// }
// return str;
//}

char* replaceSpace1(char* s){
	int cnt = 0;
	//求空格的个数
	for (int i = 0; s[i]; i++)
	if (s[i] == ' ')
		cnt++;

	int len = strlen(s) + 2 * cnt + 1;

	char *res = (char *)malloc(sizeof(char)*len);
	res[--len] = '\0';
	for (int i = strlen(s) - 1; i >= 0; --i){
		if (s[i] == ' '){
			res[--len] = '0';
			res[--len] = '2';
			res[--len] = '%';
		}
		else
			res[--len] = s[i];
	}
	return res;
}

char* replaceSpace2(char* s){
	char* c = s;
	char *s1 = (char*)malloc(10000 * sizeof(char));
	int index = 0;
	while (*c) {
		if (*c == ' ') {
			s1[index++] = '%';
			s1[index++] = '2';
			s1[index++] = '0';
		}
		else {
			s1[index++] = *c;
		}
		c++;
	}
	s1[index] = NULL;
	return s1;
}


int main(){
	char* str = "we are happy";
	int len = strlen(str);
	printf("%s\n", replaceSpace2(str));

	system("pause");
	return 0;
}