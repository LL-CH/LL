#include <stdio.h>
#include<stdlib.h>

int main(){
	int arr[] = { 2, 2, 3, 3, 5, 5, -1, 6, 6 };
	int num = 0;
	int len = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0; i < len; i++){ 
		num ^= arr[i];   //��� ��ͬΪ0�෴Ϊ1 ��������������һ������,��num����,��ֻ��һ��,���Ϊ�Ǹ���
	}
	printf("%d\n", num);
	system("pause");
	return 0;
}