#include <stdio.h>
#include <stdlib.h>


//����һ���ַ�������֤���Ƿ��ǻ��Ĵ���ֻ������ĸ�������ַ������Ժ�����ĸ�Ĵ�Сд��
//�����ַ�������Ϊ��Ч�Ļ��Ĵ���
/*bool isPalindrome(char * s){
int i=0,j=strlen(s)-1;
while(j>i){
    if(s[i]<65 && s[i]>57 || s[i]<48 || s[i]<97 && s[i]>90){
        i++;
        continue;
    }
    while(s[j]<65&&s[j]>57||s[j]<48||s[j]<97&&s[j]>90)
        j--;
    if(s[i]>=65 && s[i]<=90)
        s[i]+=32;
    if(s[j]>=65 && s[j]<=90)
        s[j]+=32;
    if(s[i++]!=s[j--])
        return false;
}
return true;
}*/

int isPalindrome(int x){
	int num = x;
	long res = 0;//��ֵ���
	while (x > 0){
		res = res * 10 + x % 10;
		x = x / 10;
	}
	if (res == num){
		return 1;
	}
	else
		return 0;
}

int main(){
	int x = 123;
	int res = isPalindrome(x);
	printf("%d\n", res);
	system("pause");
}