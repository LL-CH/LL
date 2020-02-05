#include<stdio.h>
#include<stdlib.h>

int* sortedSquares(int* A, int ASize, int* returnSize) {
	int i = 0;
	int j = ASize - 1;
	int k = ASize - 1;
	int *B = (int *)malloc(sizeof(int)*ASize);
	while (i <= j)
	{
		if (abs(A[i])>abs(A[j]))
		{
			B[k] = A[i] * A[i];
			k--;
			i++;
		}
		else
		{
			B[k] = A[j] * A[j];
			k--;
			j--;
		}
	}
	*returnSize = ASize;
	return B;
	free(B);
}

