#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void find(int* arr, int sz){
	int num = 0;
	int ret1 = 0;
	int ret2 = 0;
	int index = 0;
	//求两个不同的数的异或结果
	for (int i = 0; i < sz; i++){
		 num ^= arr[i];   //异或 相同为0相反为1 若数组中有两个一样的数,则num不变,若只有一个,则变为那个数
	}
	//找到这个结果中1的位置
	for (int i = 0; i < 32; i++){
		if (((num >> i) & 1) == 1){
			index = i;
			break;
		}
	}
	//判断数组中此位置为1的数
	for (int i = 0; i < sz; i++){
		//此位置为1的进行异或
		if (((arr[i] >> index) & 1) == 1){
			ret1 ^= arr[i];
		}
		//不为1的进行异或
		else{
			ret2 ^= arr[i];
		}
	}
	//输出结果
	printf("%d %d\n", ret1, ret2);
}

int main(){
	int n;
	scanf("%d\n", &n);
	int* arr=(int*)malloc(sizeof(int)*n);
	for (int i = 0; i < n; i++){
		scanf("%d", &arr[i]);
	}
	find(arr, n);
	system("pause");
	return 0;
}