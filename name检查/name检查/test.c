/*ʾ�� 1��

���룺name = "alex", typed = "aaleex"
�����true
���ͣ�'alex' �е� 'a' �� 'e' ��������
ʾ�� 2��

���룺name = "saeed", typed = "ssaaedd"
�����false
���ͣ�'e' һ����Ҫ���������Σ����� typed ������в���������*/

#include<stdio.h>
#include<stdlib.h>

int isLongPressedName(char * name, char * typed){
	int i = 0, j = 0;
	while (i<strlen(name) && j<strlen(typed)){
		if (name[i] == typed[j]){
			i++;
			j++;
		}
		else if (j>0 && typed[j] == typed[j - 1]){
			j++;
		}
		else
			return 0;
	}

	if (i != strlen(name)){
		return 0;
	}
	return 1;
}
int main(){
	char *name = "abcd";
	char *typed = "aabdd";
	int i = isLongPressedName(name, typed);
	printf("%d\n", i);
	system("pause");
}