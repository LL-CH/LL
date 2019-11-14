#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int Strcmp(const char* str1, const char* str2){
	assert(str1 && str2); //字符串不为空
	int ret = 0;
	const char* s1 = str1;
	const char* s2 = str2;
		while (*s1 && *s2)
		{
			if (*s1 > *s2)
			{
				return 1;
			}
			else if (*s1 < *s2)
			{
				return -1;
			}
			else
			{
				++s1;
				++s2;
			}
		}
	
		// 字符串长度不同的情况
		if (*s1 == '\0' && *s2 == '\0')
		{
			return 0;
		}
		else if (*s1 == '\0')
		{
			return -1;
		}
		else
		{
			return 1;
		}
	
		return ret;
	}


int main(){
	const char* str1 = "helloa";
	const char* str2 = "hello";
	int ret1 = Strcmp(str1, str2);
	printf("%d\n", ret1);
	int ret2 = strcmp(str1, str2);
	printf("%d\n", ret2);
	system("pause");
	return 0;
}