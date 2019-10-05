#include <stdio.h>
#include <stdlib.h>
 int main()
{
	 int num=0;
	 for (num = 99; num < 1000; num++){
		 int a = num%10;
		 int b = num/10%10;
		 int c = num/100;
		 if (num == (a*a*a) + (b*b*b) + (c*c*c)){
			 printf("%d\n", num);
		 }
	 }
	

	system("pause");
}
