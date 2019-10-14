#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include<time.h>
int menu(){
	printf("=======================================\n");
	printf("===========输入为1则开始游戏===========\n");
	printf("===========输入为0则结束游戏===========\n");
	printf("=======================================\n");
	printf("输入你的选择:\n");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}
void game(){
	int random_num = rand() % 100 + 1; //返回一个随机数组
	int input = 0;
	while (1){                     //可用死循环for(;;)
		printf("输入猜的数字:\n");
		scanf("%d", &input);
		if (input > random_num){
			printf("猜大了!\n");
		}
		else if (input < random_num) {
			printf("猜小了!\n");
		}
		else {
			printf("猜对了!\n");
			break;
		}

	}
}
int main()
{
	int input = 0;
	int t = time(0);
	srand(t);       //生成随机数序列
	while (1){
		int choice = menu();
		if (choice == 1){
			printf("============开始游戏===========\n");
			game();
		}
		else if (choice == 0){
			printf("============游戏结束============\n");
		}
		else {
			printf("你的输入有误!\n");
		}

	}
	system("pause");
}
