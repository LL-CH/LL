#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main(){
	int i = 0;
	for (i = 0; i < 3; i++){
	char password[1024] = { 0 };
	printf("����������!\n");
	scanf("%s", password);
	if (strcmp(password,"111222" ) == 0){
		printf("��¼�ɹ�!\n");
		break;
	}
	else {
		printf("�������,����������\n");
	}
	}
	if (i == 3){
		printf("��¼ʧ��!\n");
	}
	system("pause");
}
