#include <stdio.h>
#include <stdlib.h>

int sort(int* str,int len){
	int temp = 0;
	int* start=str;
	int* end=str+len-1;
	while (start < end){
		//��ͷ��ʼ������,�ҵ�Ϊ����ʱ��������
		if ((*start & 1) == 1){     
			start++;
		}
		//�����ʼ��ż��,�ҵ�ż������ǰ��
		else if ((*end & 1) == 0){
			end--;
		}
		//��startΪż��,endΪ����ʱ����������
		else{
			 temp = *start;
			*start = *end;
			*end = temp;
		}
	}
	return 0;
}

//�������Ԫ��
int Print(int* str,int len){
	for (int i = 0; i < len; i++){
		printf(" %d ", str[i]);
	}
	return 0;
}

int main(){
	int str[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int len = sizeof(str) / sizeof(str[0]);
	sort(str, len);
	Print(str, len);
	system("pause");
	return 0;
}