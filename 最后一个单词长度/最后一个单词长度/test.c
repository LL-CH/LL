#include<stdio.h>
#include<stdlib.h>

int lengthOfLastWord(char * s){
	int len = strlen(s);
	int count = 0;
	if (len>0 && s[len - 1] == ' '){  //去掉最后为空格时的部分
		len--;
	}
	for (int i = len - 1; i >= 0; i--)
	{
		if (s[i] != ' ')
			count++;
		else if (count>0)
			return count;
	}
	return count;
}

int main(){
	char *s = "a d ";
	int i = lengthOfLastWord(s);
	printf("%d\n", i);
	system("pause");
}