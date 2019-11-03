#include<stdio.h>
#include <stdlib.h>

//逆转整个字符串
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
	//整体逆转
	reverse_str(str, str + len - 1);
	//局部逆转
	while (*cur){
		char* start = cur;
		while (*cur != ' ' && *cur != '\0'){
			++cur;
		}
		//逆转当前单词
		reverse_str(start, cur - 1);
		//走到下一个单词
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