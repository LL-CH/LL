//
//#include<stdio.h>
//#include<stdlib.h>
//int swap(int arr[], int sz)
//{
//	int left = 0;
//	int right = sz - 1;
//	int tmp = 0;
//	while (left<right)
//	{
//		while ((left<right) && (arr[left] % 2 == 1))
//		{
//			left++;
//		}
//		while ((left<right) && (arr[right] % 2 == 0))
//		{
//			right--;
//		}
//		if (left<right)    //所加(left<right)为确保每一次左右下标调整后都能满足结果成立的条件
//		{
//			tmp = arr[left];
//			arr[left] = arr[right];
//			arr[right] = tmp;
//		}
//	}
//	return 0;
//}
//int printf_arr(int arr[], int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}
//int main()
//{
//	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	swap(arr, sz);
//	printf_arr(arr, sz);
//	system("pause");
//	return 0;
//}
