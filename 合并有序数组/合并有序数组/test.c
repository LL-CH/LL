#include <stdio.h>
#include <stdlib.h>

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
	int end1 = m - 1;
	int end2 = n - 1;
	int end = m + n - 1;
	while (end2 >= 0 && end1 >= 0){
		if (nums1[end1]<nums2[end2]){
			nums1[end] = nums2[end2];
			end--;
			end2--;
		}
		else{
			nums1[end] = nums1[end1];
			end1--;
			end--;
		}
	}
	while (end2 >= 0){
		nums1[end] = nums2[end2];
		end--;
		end2--;
	}
}

int main(){
	int num1[] = { 1, 3, 5, 7 ,0,0,0,0};
	int num2[] = { 2, 4, 6, 8 };
	int num1size = sizeof(num1)/sizeof(num1[0]);
	int num2size = sizeof(num2) / sizeof(num2[0]);
	int m = 4;
	int n = 4;
	merge(num1, num1size, m,num2, num2size, n);
	for (int i = 0; i < num1size; i++){
		printf("%d ", num1[i]);
	}
	system("pause");


}