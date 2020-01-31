//给定一个赎金信 (ransom) 字符串和一个杂志(magazine)字符串，判断第一个字符串ransom能不能由第二个字符串magazines里面的字符构成。如果可以构成，返回 true ；否则返回 false。
//都为小写字母


#include <stdio.h>
#include <stdlib.h>

int canConstruct(char * ransomNote, char * magazine){
	int nums[123] = { 0 };
	while (*magazine != '\0')
	{
		nums[*magazine]++;
		magazine++;
	}

	while (*ransomNote != '\0')
	{
		nums[*ransomNote]--;
		ransomNote++;
	}
	for (int i = 0; i<123; i++)
	{
		if (nums[i]<0)
		{
			return 0;
		}
	}
	return 1;
}

int main(){
	char * ransomNote = "az";
	char * magazine = "amn";
	int i= canConstruct(  ransomNote,   magazine);
	printf("%d\n", i);
	system("pause");
}