#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include <time.h>

#define MAX_ROW 9
#define MAX_COL 9

#define MINE_COUNT 10

//定义雷区地图
char mine_board[MAX_ROW][MAX_COL];
//定义表面地图
char show_board[MAX_ROW][MAX_COL];

void init(){
	//将表面地图表示为'*'
	for (int row = 0; row < MAX_ROW; row++){
		for (int col = 0; col < MAX_COL; col++){
			show_board[row][col] = '*';
		}
	}
	//将雷区表示为0,表示无雷,表示为1则有雷
	for (int row = 0; row < MAX_ROW; row++){
		for (int col = 0; col < MAX_COL; col++){
			mine_board[row][col] = '0';
		}
	}
	//创建一组随机数定义为1表示雷
	srand((unsigned int )time(0));
	int count = 0;
	while (1){
		int row = rand() % MAX_ROW;
		int col = rand() % MAX_COL;
		if (mine_board[row][col] == '1'){
			continue;
		}
		mine_board[row][col] = '1';
		count++;
		if (count >= MINE_COUNT){
			break;
		}
	}
}

void printshow_map(char the_map[MAX_ROW][MAX_COL]){
	for (int row = 0; row < MAX_ROW; row++){
		for (int col = 0; col < MAX_COL; col++){
			printf("%c", the_map[row][col]);
		}
		printf("\n");
	}
}

int main(){
	//雷区地图初始化
	init();
	while (1){
		//打印表面地图
		printshow_map(show_board);
		//玩家输入坐标,翻开表面地图
		printf("请输入要翻开位置的坐标:");
		int row = 0;
		int col = 0;
		scanf("%d %d", &row, &col);
		//判断是否超出界限
		if (row<0 || row>MAX_ROW || col<0 || col>MAX_COL){
			printf("你的输入有误!请重新输入:");
			continue;
		}
		//判断是否被翻开过
		if (show_board[row][col] != '*'){
			printf("该位置已被翻开!请重新选择:");
			continue;
		}
		//判断是否踩雷
		if (mine_board[row][col] == '1'){
			printf("游戏结束!\n");
			printshow_map(mine_board);
			break;
		}
		//判断游戏是否胜利
		//显示玩家翻牌周围的雷数并打印表面地图
	}
		system("pause");

}