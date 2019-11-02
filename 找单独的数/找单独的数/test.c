#include <stdio.h>
#include<stdlib.h>

int main(){
	int arr[] = { 2, 2, 3, 3, 5, 5, -1, 6, 6 };
	int num = 0;
	int len = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0; i < len; i++){ 
		num ^= arr[i];   //异或 相同为0相反为1 若数组中有两个一样的数,则num不变,若只有一个,则变为那个数
	}
	printf("%d\n", num);
	system("pause");
	return 0;
}