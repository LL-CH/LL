#include <stdio.h>    
#include <stdlib.h>

int main()
{
	int murder;
	for (murder = 'A'; murder <= 'D'; murder++)
	{
		//有三个人说真话一个人说假话，而在if语句的，如果括号里为真结果为1，要是假结果为0。所以关系若成立，一定有一个说假话为0，其余为1,即结果等于3.
		if (((murder != 'A') + (murder == 'C') + (murder == 'D') + (murder != 'D')) == 3)      
		{
			printf("凶手是 %c\n", murder);    

		}
	}
	system("pause");
	return 0;
}
