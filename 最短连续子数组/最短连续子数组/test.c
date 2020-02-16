int findUnsortedSubarray(int* nums, int numsSize){

	if (numsSize <= 1) return 0;
	int start = -1, end = -1;
	for (int i = 0; i<numsSize - 1; i++){
		for (int j = i + 1; j<numsSize; j++){
			if (nums[j]<nums[i]) {
				start = i;
				break;
			}
		}
		if (start != -1)
			break;
	}
	if (start == -1)
		return 0;
	for (int i = numsSize - 1; i>0; i--){
		for (int j = i - 1; j >= 0; j--){
			if (nums[j]>nums[i]){
				end = i;
				break;
			}
		}
		if (end != -1) break;
	}
	return end - start + 1;
}