#include<stdio.h>
#include <stdlib.h>

//��ת�����ַ���
void reverse_str(char* start,char* end){
	while (start < end){
		char temp = *start;
		*start = *end;
		*end = temp;
		++start;
		--end;
	}
}

int Strlen(char* str){
	int count = 0;
	while (*str++){
		++count;
	}
	return count;
}

void reverse(char* str){
	char* cur = str;
	int len = Strlen(str);
	//������ת
	reverse_str(str, str + len - 1);
	//�ֲ���ת
	while (*cur){
		char* start = cur;
		while (*cur != ' ' && *cur != '\0'){
			++cur;
		}
		//��ת��ǰ����
		reverse_str(start, cur - 1);
		//�ߵ���һ������
		while (*cur == ' '){
			++cur;
		}
	}
}

int main(){
	char str[] = "student a am i";
	printf("%s\n",str);
 	reverse(str);
	printf("%s\n",str);
	system("pause");
	return 0;
}