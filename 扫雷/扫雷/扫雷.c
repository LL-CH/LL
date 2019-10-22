#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include <time.h>
//定义格子数
#define MAX_ROW 9
#define MAX_COL 9

// 定义地雷数量
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

//打印表面的地图样式
void printshow_map(char the_map[MAX_ROW][MAX_COL]){
	for (int row = 0; row < MAX_ROW; row++){
		for (int col = 0; col < MAX_COL; col++){
			printf(" %c ", the_map[row][col]);
		}
		printf("\n");
	}
}

//判断所翻开的位置周围的雷数并表示在地图上
void mine_count_map(char mine_board[MAX_ROW][MAX_COL],char show_board[MAX_ROW][MAX_COL],
					int row,int col){
	int count = 0;
	for (int r = row - 1; r <= row + 1; r++){
		for (int c = col - 1; c <= col + 1; c++){
			if (r == row && c == col){
				continue;
			}
			//超出边界时
			if (row<0 || row>=MAX_ROW || col<0 || col>=MAX_COL){
				continue;
			}
			if (mine_board[r][c] == '1'){
				count++;
			}
		}
	}
	show_board[row][col] = '0'+ count;
}

int main(){
	int count =0;
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
		if (row<0 || row>=MAX_ROW || col<0 || col>=MAX_COL){
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
			printshow_map(mine_board);
			printf("游戏结束!\n");
			break;
		}
		//判断游戏是否胜利
		++count;
		if (count ==( MAX_ROW*MAX_COL) - MINE_COUNT){
			printshow_map(mine_board);
			printf("你赢了!");
			break;
		}

		//显示玩家翻牌周围的雷数并打印表面地图
		mine_count_map(mine_board,show_board,row,col);
	}
		system("pause");

}