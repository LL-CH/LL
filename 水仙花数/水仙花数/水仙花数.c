#include <stdio.h>
#include <stdlib.h>
 int main()
{
	 int num=0;
	 for (num = 99; num < 1000; num++){
		 int a = num%10;
		 int b = num/10%10;
		 int c = num/100;
		 if (num == (a*a*a) + (b*b*b) + (c*c*c)){ //��η����� power( num,n)
			 printf("%d\n", num);
		 }
	 }
	

	system("pause");
}
  //����������Ĵ�����
 int main(){
	 int sum = 0;
	 int tmp = num;
	 //ȥ���ֵ�λ��
	 while (tmp){
		 count++;
		 tmp /= 10;
	 }
	 for (num = 99; num < 1000; num++){
		 while (tmp){
			 sum = power(tmp % 10, count);
			 tmp /= 10;
		 }
	 }printf("%d", num);
 }