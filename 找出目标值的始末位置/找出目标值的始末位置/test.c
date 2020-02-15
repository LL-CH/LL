int* searchRange(int* nums, int numsSize, int target, int* returnSize){
	int *ret = (int *)malloc(sizeof(int)* 2);
	*returnSize = 2;
	ret[0] = -1;
	ret[1] = -1;
	if (numsSize <= 0){
		return ret;
	}
	int left = 0, right = numsSize - 1, mid = 0;
	while (left <= right) {
		mid = (left + right) / 2;
		if (nums[mid] == target) {
			int index = mid;
			while (index > 0 && nums[index] == nums[index - 1]){
				index--;
			}
			ret[0] = index;
			index = mid;
			while (index < numsSize - 1 && nums[index] == nums[index + 1]){
				index++;
			}
			ret[1] = index;
		}
		if (nums[mid] > target) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	return ret;
}