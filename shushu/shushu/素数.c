
#include <stdio.h>
#include <stdlib.h>
int main(){
	printf("���100��200֮���������\n");

	int n,m ;
	
	for (n = 100; n <= 200;n++)
	{
		for (m = 2; m < n;m++)
		if (n%m == 0)
			break;
		if (m>=n)
		printf("%d\n", n);
	}
	
	system("pause");
 }
