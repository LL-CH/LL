#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include<time.h>
int menu(){
	printf("=======================================\n");
	printf("===========����Ϊ1��ʼ��Ϸ===========\n");
	printf("===========����Ϊ0�������Ϸ===========\n");
	printf("=======================================\n");
	printf("�������ѡ��:\n");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}
void game(){
	int random_num = rand() % 100 + 1; //����һ���������
	int input = 0;
	while (1){                     //������ѭ��for(;;)
		printf("����µ�����:\n");
		scanf("%d", &input);
		if (input > random_num){
			printf("�´���!\n");
		}
		else if (input < random_num) {
			printf("��С��!\n");
		}
		else {
			printf("�¶���!\n");
			break;
		}

	}
}
int main()
{
	int input = 0;
	int t = time(0);
	srand(t);       //�������������
	while (1){
		int choice = menu();
		if (choice == 1){
			printf("============��ʼ��Ϸ===========\n");
			game();
		}
		else if (choice == 0){
			printf("============��Ϸ����============\n");
		}
		else {
			printf("�����������!\n");
		}

	}
	system("pause");
}
