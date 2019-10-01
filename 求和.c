#include <stdio.h>
#include <stdlib.h>
main()
{
float sum1= 0.0,sum2=0.0,sum;
	int num1, num2;
	
	for (num1 = 1.0; num1 <= 100.0; num1+=2.0){
		sum1 += 1.0/num1;
			
		}
		
	
	
	for (num2 = 2.0; num2<= 100.0; num2+=2.0){
		
		sum2 += 1.0 / num2;
		}
	sum = sum1 - sum2;
	
	printf("%f\n", sum);

	system("pause");
}
