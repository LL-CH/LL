#include <stdio.h>
#include <stdlib.h>
 int main()
{
	int count = 0;
	int num = 0;
	for (num = 1; num < 100; num++){
		if (num % 10 == 9){
			count++;
		}
		if(num /10==9)
		{
			count++;	
		}
	}

	//��ȡ������m,n��9�ĸ���
	//int m, n;
	//int count = 0;
	//int num = 0;
	//for (num = 1; num < 100; num++){
	//	int tmp = num;
	//	while (tmp){
	//		if (tmp % 10 == 9)
	//			count++;
	//		//�Ѹ�λ�ƶ�����λ
	//		tmp /= 10;
	//	}
	//}


	printf("%d\n", count);
	system("pause");
}

