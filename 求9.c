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

	//获取区间吗m,n内9的个数
	//int m, n;
	//int count = 0;
	//int num = 0;
	//for (num = 1; num < 100; num++){
	//	int tmp = num;
	//	while (tmp){
	//		if (tmp % 10 == 9)
	//			count++;
	//		//把高位移动到个位
	//		tmp /= 10;
	//	}
	//}


	printf("%d\n", count);
	system("pause");
}

