#include <stdio.h>
#include <stdlib.h>
main()
{
float sum1= 0.0,sum2=0.0,sum;
	int num;
	//计算奇数项
	for (num = 1.0; num < 100.0; num+=2.0){
		sum1 += 1.0/num;
			
		}
	//计算偶数项
	for (num = 2.0; num<= 100.0; num+=2.0){
		
		sum2 += 1.0 / num;
		}
	sum = sum1 - sum2;

	//一次循环
	//int a = 1;
	//for (num = 1.0; num < =100.0; num ++){
	//	sum1 += 1.0 / num*a;
	//	a = -a;
	//}
	printf("%f\n", sum);

	system("pause");
}
