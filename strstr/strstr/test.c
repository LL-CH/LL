#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

char* Strstr(const char* str1, const char* str2){
	assert(str1 && str2); //×Ö·û´®²»Îª¿Õ
	const char* s1=str1;
	const char* s2 = str2;

	while (*s1 != '\0'){
		while (*s1 == *s2 && *s2 != '\0'){
			++s1;
			++s2;
		}
		if (*s2 == '\0'){
			return str1;
		}
		else
		{
			s2 = str2;
			++str1;
			s1 = str1;
		}
	}
	return 0;
	 
}

int main(){
	char* str1 = "aaaadef";
	char* str2 = "aade";
	char* ret1 = Strstr(str1, str2);
	printf("%s\n", ret1);
	char* ret2 = strstr(str1, str2);
	printf("%s\n", ret2);
	system("pause");
}