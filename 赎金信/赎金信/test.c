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