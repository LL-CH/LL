#include <stdio.h>
#include <stdlib.h>
 main()
{
	 printf("³Ë·¨¿Ú¾÷±í£º\n");
	int n, m;
	for (n = 1; n <= 9; n++)
	{
		for (m = 1; m <= n; m++)
		{
			if (m > n)
				break;
			printf("%3d", n*m);
		}
		printf("\n");
		
	}system("pause");
}