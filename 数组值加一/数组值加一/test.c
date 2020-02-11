#include <stdio.h>
#include <stdlib.h>

int* plusOne(int* digits, int digitsSize, int* returnSize) {
	int i = digitsSize - 1;
	for (i; i >= 0; i--){
		if (digits[i] < 9)
		{
			digits[i]++;
			*returnSize = digitsSize;
			for (int j = 0; j < digitsSize ; j++){
				printf("%d ", digits[j]);
			}
			return 0;
		}
		else
			digits[i] = 0;
	}
	int* new = (int*)malloc((digitsSize + 1) * sizeof (int));
	new[0] = 1;
	for (i = 1; i < (digitsSize + 1); i++)
		new[i] = 0;
	*returnSize = digitsSize + 1;
	for (int j = 0; j < digitsSize + 1; j++){
		printf("%d ", new[j]);
	}
	return 0;
}

int main(){
	int nums[] = { 9, 9, 9 };
	int numssize = sizeof(nums) / sizeof(nums[0]);
	int returnsize[] = { 0 };
	plusOne(nums, numssize, returnsize);

	system("pause");
	
}