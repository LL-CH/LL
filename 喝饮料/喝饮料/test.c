#include <stdio.h>
#include <stdlib.h>

int main(){
	int n = 20;
	int num = n;//��������
	int bottle = n;//��ƿ����
	while (bottle > 1){
		num += bottle / 2;
		bottle = bottle / 2 + bottle % 2;
	}
	printf("%d\n", num);
	system("pause");
	return 0;
}