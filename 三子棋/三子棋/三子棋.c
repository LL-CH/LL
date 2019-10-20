#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

#define MAX_ROW 3
#define MAX_COL 3

char chess_board[MAX_ROW][MAX_COL];

//打印棋盘
void printboard(){
	printf("+---+---+---+\n");
	for (int row = 0; row < MAX_ROW; row++){
		printf("| %c | %c | %c |\n", chess_board[row][0], chess_board[row][1], chess_board[row][2]);
		printf("+---+---+---+\n");
	}
	}

void player(){
	printf("玩家下棋!\n");
	printf("请输入坐标:");
	while (1){
	int row=0, col=0;
	scanf("%d %d", &row, &col);
	//当输入超出范围时
	if (row<0 || row>=MAX_ROW || col < 0 || col >= MAX_COL){
		printf("你的输入有误!请重新输入:");
		continue;
	}
	//当这个位置已经有棋子时
	if (chess_board[row][col] != ' '){
		printf("该位置已经有棋子了!请重新输入:");
		continue;
	}
	chess_board[row][col] = 'x';
	break;
	}
}

void computer(){
	printf("电脑下棋!\n");
	while (1){
		int row = rand() % MAX_ROW;
		int col = rand() % MAX_COL;
		if (chess_board[row][col] != ' '){
			continue;
		}
		chess_board[row][col] = 'o';
		break;
	}
}
 //棋盘无空位返回0
int full(){
	for (int row = 0; row < MAX_ROW; row++){
		for (int col = 0; col < MAX_ROW; col++){
			if (chess_board[row][col] != ' '){
				return 0;
			}
		}
	}
	return 0;
}

//输出'x',玩家胜
//输出'o'电脑胜
//输出' '未分胜负
//输出'h'和棋
int winner(){
	//判断行
	for (int row = 0; row < MAX_ROW; row++){
		if (chess_board[row][0] == chess_board[row][1] && chess_board[row][0] == chess_board[row][2]){
			return chess_board[row][0];
		}
	}
	//判断列
	for (int col= 0; col< MAX_COL; col++){
		if (chess_board[0][col] == chess_board[1][col] && chess_board[0][col] == chess_board[2][col]){
			return chess_board[0][col];
		}
	}
	//判断对角线
	if (chess_board[0][0] == chess_board[1][1] && chess_board[0][0] == chess_board[2][2]){
		return chess_board[0][0];
	}
	if (chess_board[0][2] == chess_board[1][1] && chess_board[0][2] == chess_board[2][0]){
		return chess_board[0][2];
	}
	//判断和棋
	if (full() == 0){
		return 'h ';
	}
	return ' ';
}

int main(){
	//1.初始化棋盘
	int row, col;
	for (row = 0; row < MAX_ROW; row++){
		for (col = 0; col < MAX_ROW; col++){
			chess_board[row][col] = ' ';
		}
	}

	char win=' ';
	while (1){
		//2.打印棋盘
		printboard(); 
		//3.玩家落子(用坐标代替)
		player();
		//4.判断胜负
	 win = winner();
		if (win != ' '){
			break;
		}
		
		//5.电脑落子(随机落子)
		computer();
		//6.判断胜负
	 win = winner();
		if (win != ' '){
			break;
		}
	}
	printboard();
	if (win == 'x'){
		printf("玩家胜!\n");
	}
	else if (win == 'o'){
		printf("电脑胜!\n");
	}
	else {
		printf("此局和棋!\n");
	}

	system("pause");

}