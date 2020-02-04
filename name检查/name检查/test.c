/*示例 1：

输入：name = "alex", typed = "aaleex"
输出：true
解释：'alex' 中的 'a' 和 'e' 被长按。
示例 2：

输入：name = "saeed", typed = "ssaaedd"
输出：false
解释：'e' 一定需要被键入两次，但在 typed 的输出中不是这样。*/

#include<stdio.h>
#include<stdlib.h>

int isLongPressedName(char * name, char * typed){
	int i = 0, j = 0;
	while (i<strlen(name) && j<strlen(typed)){
		if (name[i] == typed[j]){
			i++;
			j++;
		}
		else if (j>0 && typed[j] == typed[j - 1]){
			j++;
		}
		else
			return 0;
	}

	if (i != strlen(name)){
		return 0;
	}
	return 1;
}
int main(){
	char *name = "abcd";
	char *typed = "aabdd";
	int i = isLongPressedName(name, typed);
	printf("%d\n", i);
	system("pause");
}