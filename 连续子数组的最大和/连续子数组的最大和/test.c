#include <stdio.h>
#include <stdlib.h>

int maxSubArray(int* nums, int numsSize){
	int max = nums[0];
	int n = 0;
	for (int i = 0; i<numsSize; i++){
		n += nums[i];
		//ǰ��ĺͼ��������ʱ���������,�Ͱ�����max
		if (n>max){
			max = n;
		}
		//ǰ��ĺͼ��������ʱС��0��,�Ͱ�n��0,���¿�ʼ
		if (n<0){
			n = 0;
		}
	}
	return max;
}

int main(){
	int nums[] = { 2, -1, -3, 3, -5, 4, 1 };
	int numsize = sizeof(nums) / sizeof(int);

	printf("%d\n", maxSubArray(nums, numsize));
	system("pause");
	return 0;
}