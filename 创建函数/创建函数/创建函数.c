#include<stdio.h>
#include<stdlib.h>
//��ʼ������
void init(int arr[], int size)      //init(int* a,int size)
{
	int i = 0;
	for (i = 0; i < size; i++)
	{
		arr[i] = i;
		printf("%2d", arr[i]);
	}
	
}
//�������
void empty(int arr[], int size)
{
	int i = 0;
	for (i = 0; i < size; i++)        //memset (arr,0,size * sizeof(int));
	{
		arr[i] = 0;
		printf("%2d", arr[i]);
	}
	
}
//��������
void reverse(int arr[], int size)
{
	int i = 0;
	int left = 0;
	int right = size - 1;
	for (i = 0; i < size; i++)
	{
		while (left < right)
		{
			int tmp = arr[left];
			arr[left] = arr[right];   //*(arr+(left))=*(arr+(right))
			arr[right] = tmp;
			left++;
			right--;
		}
		printf("%2d", arr[i]);
	}
}
int main(){
	int arr[10];
	int size = sizeof(arr) / sizeof(arr[0]);
	printf("��ʼ������:\n");
	init(arr, size);
	printf("\n");
	printf("��������:\n");
	reverse(arr, size);
	printf("\n");
	printf("�������:\n");
	empty(arr, size);
	printf("\n");
	system("pause");
}