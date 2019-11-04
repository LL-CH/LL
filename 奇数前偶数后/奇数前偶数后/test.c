#include <stdio.h>
#include <stdlib.h>

int sort(int* str,int len){
	int temp = 0;
	int* start=str;
	int* end=str+len-1;
	while (start < end){
		//从头开始找奇数,找到为奇数时就向下走
		if ((*start & 1) == 1){     
			start++;
		}
		//从最后开始找偶数,找到偶数就向前走
		else if ((*end & 1) == 0){
			end--;
		}
		//当start为偶数,end为奇数时交换两个数
		else{
			 temp = *start;
			*start = *end;
			*end = temp;
		}
	}
	return 0;
}

//输出数组元素
int Print(int* str,int len){
	for (int i = 0; i < len; i++){
		printf(" %d ", str[i]);
	}
	return 0;
}

int main(){
	int str[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int len = sizeof(str) / sizeof(str[0]);
	sort(str, len);
	Print(str, len);
	system("pause");
	return 0;
}