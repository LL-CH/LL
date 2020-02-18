int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
	*returnSize = (1 << numsSize);
	int** returnNums = (int**)malloc(sizeof(int*)*(1 << numsSize));
	*returnColumnSizes = (int*)malloc(sizeof(int)*(1 << numsSize));
	for (int i = 0; i<(1 << numsSize); i++){
		(*returnColumnSizes)[i] = 0;
		returnNums[i] = (int*)malloc(sizeof(int)*numsSize);
		int temp = i;
		int count = 0;
		int j = 0;
		while (temp){
			if (temp & 1){
				(*returnColumnSizes)[i]++;
				returnNums[i][count++] = nums[j];
			}
			j++;
			temp >>= 1;
		}
	}
	return returnNums;
}