#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include <time.h>
//���������
#define MAX_ROW 9
#define MAX_COL 9

// �����������
#define MINE_COUNT 10

//����������ͼ
char mine_board[MAX_ROW][MAX_COL];
//��������ͼ
char show_board[MAX_ROW][MAX_COL];

void init(){
	//�������ͼ��ʾΪ'*'
	for (int row = 0; row < MAX_ROW; row++){
		for (int col = 0; col < MAX_COL; col++){
			show_board[row][col] = '*';
		}
	}
	//��������ʾΪ0,��ʾ����,��ʾΪ1������
	for (int row = 0; row < MAX_ROW; row++){
		for (int col = 0; col < MAX_COL; col++){
			mine_board[row][col] = '0';
		}
	}
	//����һ�����������Ϊ1��ʾ��
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

//��ӡ����ĵ�ͼ��ʽ
void printshow_map(char the_map[MAX_ROW][MAX_COL]){
	for (int row = 0; row < MAX_ROW; row++){
		for (int col = 0; col < MAX_COL; col++){
			printf(" %c ", the_map[row][col]);
		}
		printf("\n");
	}
}

//�ж���������λ����Χ����������ʾ�ڵ�ͼ��
void mine_count_map(char mine_board[MAX_ROW][MAX_COL],char show_board[MAX_ROW][MAX_COL],
					int row,int col){
	int count = 0;
	for (int r = row - 1; r <= row + 1; r++){
		for (int c = col - 1; c <= col + 1; c++){
			if (r == row && c == col){
				continue;
			}
			//�����߽�ʱ
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
	//������ͼ��ʼ��
	init();
	while (1){
		//��ӡ�����ͼ
		printshow_map(show_board);
		//�����������,���������ͼ
		printf("������Ҫ����λ�õ�����:");
		int row = 0;
		int col = 0;
		scanf("%d %d", &row, &col);
		//�ж��Ƿ񳬳�����
		if (row<0 || row>=MAX_ROW || col<0 || col>=MAX_COL){
			printf("�����������!����������:");
			continue;
		}
		//�ж��Ƿ񱻷�����
		if (show_board[row][col] != '*'){
			printf("��λ���ѱ�����!������ѡ��:");
			continue;
		}
		//�ж��Ƿ����
		if (mine_board[row][col] == '1'){
			printshow_map(mine_board);
			printf("��Ϸ����!\n");
			break;
		}
		//�ж���Ϸ�Ƿ�ʤ��
		++count;
		if (count ==( MAX_ROW*MAX_COL) - MINE_COUNT){
			printshow_map(mine_board);
			printf("��Ӯ��!");
			break;
		}

		//��ʾ��ҷ�����Χ����������ӡ�����ͼ
		mine_count_map(mine_board,show_board,row,col);
	}
		system("pause");

}