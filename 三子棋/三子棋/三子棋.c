#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

#define MAX_ROW 3
#define MAX_COL 3

char chess_board[MAX_ROW][MAX_COL];

//��ӡ����
void printboard(){
	printf("+---+---+---+\n");
	for (int row = 0; row < MAX_ROW; row++){
		printf("| %c | %c | %c |\n", chess_board[row][0], chess_board[row][1], chess_board[row][2]);
		printf("+---+---+---+\n");
	}
	}

void player(){
	printf("�������!\n");
	printf("����������:");
	while (1){
	int row=0, col=0;
	scanf("%d %d", &row, &col);
	//�����볬����Χʱ
	if (row<0 || row>=MAX_ROW || col < 0 || col >= MAX_COL){
		printf("�����������!����������:");
		continue;
	}
	//�����λ���Ѿ�������ʱ
	if (chess_board[row][col] != ' '){
		printf("��λ���Ѿ���������!����������:");
		continue;
	}
	chess_board[row][col] = 'x';
	break;
	}
}

void computer(){
	printf("��������!\n");
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
 //�����޿�λ����0
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

//���'x',���ʤ
//���'o'����ʤ
//���' 'δ��ʤ��
//���'h'����
int winner(){
	//�ж���
	for (int row = 0; row < MAX_ROW; row++){
		if (chess_board[row][0] == chess_board[row][1] && chess_board[row][0] == chess_board[row][2]){
			return chess_board[row][0];
		}
	}
	//�ж���
	for (int col= 0; col< MAX_COL; col++){
		if (chess_board[0][col] == chess_board[1][col] && chess_board[0][col] == chess_board[2][col]){
			return chess_board[0][col];
		}
	}
	//�ж϶Խ���
	if (chess_board[0][0] == chess_board[1][1] && chess_board[0][0] == chess_board[2][2]){
		return chess_board[0][0];
	}
	if (chess_board[0][2] == chess_board[1][1] && chess_board[0][2] == chess_board[2][0]){
		return chess_board[0][2];
	}
	//�жϺ���
	if (full() == 0){
		return 'h ';
	}
	return ' ';
}

int main(){
	//1.��ʼ������
	int row, col;
	for (row = 0; row < MAX_ROW; row++){
		for (col = 0; col < MAX_ROW; col++){
			chess_board[row][col] = ' ';
		}
	}

	char win=' ';
	while (1){
		//2.��ӡ����
		printboard(); 
		//3.�������(���������)
		player();
		//4.�ж�ʤ��
	 win = winner();
		if (win != ' '){
			break;
		}
		
		//5.��������(�������)
		computer();
		//6.�ж�ʤ��
	 win = winner();
		if (win != ' '){
			break;
		}
	}
	printboard();
	if (win == 'x'){
		printf("���ʤ!\n");
	}
	else if (win == 'o'){
		printf("����ʤ!\n");
	}
	else {
		printf("�˾ֺ���!\n");
	}

	system("pause");

}