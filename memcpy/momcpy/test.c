
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void* Memcpy(void* dst, const void* src,int  num){
	assert(dst && src); //�ַ�����Ϊ��
	void* ret = dst;
  //��Դ�ַ������Ƶ�Ŀ��ռ�
			char* str_dst = (char*)dst;
			char* str_src = (char*)src;
			for (int i = 0; i < num; ++i)
			{
				str_dst[i] = str_src[i]; // *(str_src+i)
			}

			return dst;
}

int main(){
	char dst[20] = "abcde";
	const char* src = "he";
	char* ret1 = Memcpy(dst, src, 2);
	printf("%s\n", ret1);
	system("pause");
}