#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void* Memmove(void* dst, const void* src, size_t num)
{
	assert(src && dst);

	char* d = (char*)dst;
	char* s = (char*)src;
	if (s < d && dst < s + num) //后重叠时从后往前拷贝
	{
		for (int i = num - 1; i >= 0; --i)
		{
			d[i] = s[i];
		}
	}
	else  // 前重叠和不重叠时从前往后考
	{
		for (int i = 0; i < num; ++i)
		{
			d[i] = s[i];
		}
	}

	return dst;
}

int main(){
		int a2[10] = { 1, 2, 3, 4, 5 };
		int a1[10] = { 0 };
		Memmove(a1, a2, 2 * sizeof(int));
		for (int i = 0; i < 10; ++i)
		{
			printf("%d ", a1[i]);
		}
		printf("\n");
	system("pause");
	return 0;
}