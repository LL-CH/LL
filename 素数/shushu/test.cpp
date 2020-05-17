//尾数为1的素数

#define  _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
int prime[10001];//存储素数的数组
int primesize = 0;//记录素数的个数
int mark[10001];//标记是否是素数

void init()
{
	for (int i = 2; i <= 10000; i++)
		mark[i] = false;//初始化，所有数目前均为素数
	for (int i = 2; i <= 10000; i++){
		if (false == mark[i]){
			prime[primesize++] = i;//记录素数
			for (int j = i*i; j <= 10000; j += i){
				//在这里，从 i*i 开始，因为 i*k (k<i) 也是k的素因数的倍数
				mark[j] = true;//置素数的倍数均为非素数
			}
		}
	}
} 

int main(){
	init();//求2-10000之间的所有素数，记录在全局变量prime中
	int n;
	while (scanf("%d", &n) != EOF)
	{
		bool isOutput = false;
		for (int i = 0; i < primesize; i++)
		{
			if (prime[i] < n && prime[i] % 10 == 1)
			{//1-n之间的素数，且个位为1
				if (false == isOutput)
				{
					isOutput = true;
					printf("%d", prime[i]);
				} else
					printf(" %d", prime[i]);
			}
		} 
		if(false == isOutput)
			printf("-1\n");
		else 
			printf("\n");
	} 

	return 0;
}