#include<stdio.h>
#include<stdlib.h>

int cmp(const void* a, const void* b){
	return (*(int*)a - *(int*)b);//大于返回1 等于返回0 小于返回-1
}

int containsDuplicate(int* nums, int numsSize){
	if (numsSize == 0 || numsSize == 1) {
		return 0;
	}
	qsort(nums, numsSize, sizeof(int), cmp);
	for (int i = 1; i < numsSize; i++) {
		if (nums[i] == nums[i - 1]) {
			return 1;
		}
	}
	return 0;
}
int main(){
	int nums[] = { 1, 2, 3, 1 };
	int numsize = sizeof(nums) / nums[0];
	int i = containsDuplicate(nums, numsize);
	printf("%d\n", i);
	system("pause");
}