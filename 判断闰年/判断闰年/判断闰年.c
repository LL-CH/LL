#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
void judge( int a){
	if ((a % 4 == 0 && a % 100 != 0) || (a % 400 == 0)){
			printf("是闰年!\n"); 
		}
		else {
			printf("不是闰年!\n");
		}
}

int main(){
	int y=0;
	printf("输入年份：\n");
	scanf("%d", &y);
	judge(y);

	system("pause");
}