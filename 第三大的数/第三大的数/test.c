int cmp(const void *a, const void *b) {
	return (*(int *)b) < (*(int *)a);
}

int thirdMax(int* nums, int numsSize){
	int count = 0;
	qsort(nums, numsSize, sizeof(int), cmp);
	for (int i = 0; i<numsSize - 1; i++)
	{
		if (nums[i + 1] != nums[i])
		{
			nums[++count] = nums[i + 1];
		}
	}
	if (count>1)
	{
		return nums[count - 2];
	}
	else
	{
		return nums[count];
	}
}