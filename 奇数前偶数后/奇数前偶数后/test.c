#include <stdio.h>
#include <stdlib.h>

int sort(int* str,int len){
	int temp = 0;
	int* start=str;//int start=0;
	int* end=str+len-1;//int end=len-1
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
			/*while (start < end && str[start] % 2 != 0){
				++start;
			}
			while (start < end && str[end] % 2 == 0){
				--end;
			}*/
			 temp = *start;
			*start = *end;
			*end = temp;
		}
	}
	return 0;
}

void sort2(int *str,int len){
	int start = 0;
	int end = len - 1;
	int temp = 0;
	while (start < end){
		while (start < end && str[start] % 2 != 0){   //%2==0;
		++start;
		}
		while (start < end && str[end] % 2 == 0){    //%2!=0;   ż����ǰ,�����ں�
		--end;
		}
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;
	}
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
	printf("\n");
	int str2[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int len2 = sizeof(str2) / sizeof(str2[0]);
	sort2(str2, len2);
	Print(str2, len2);
	system("pause");
	return 0;
}