#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int pivotIndex(int* nums, int numsSize) {
	int sum = 0;
	int num = 0;
	for (int i = 0; i < numsSize; i++){
		sum = sum + nums[i];
	}
	for (int i = 0; i < numsSize; i++){
		if (num * 2 == sum - nums[i]){
			return i;
		}
		num = num + nums[i];
	}
	return -1;
}

int main(){
	int nums[] = { 1, 7,3,6,5,6};
	int numsize = sizeof(nums)/sizeof(nums[0]);
	int i = pivotIndex(nums, numsize);
	printf("%d\n", i);

	system("pause");
}