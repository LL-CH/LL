#include<stdio.h>
#include<stdlib.h>

int lengthOfLastWord(char * s){
	int len = strlen(s);
	int count = 0;
	if (len>0 && s[len - 1] == ' '){  //ȥ�����Ϊ�ո�ʱ�Ĳ���
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