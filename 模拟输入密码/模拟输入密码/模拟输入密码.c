#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main(){
	int i = 0;
	for (i = 0; i < 3; i++){
	char password[1024] = { 0 };
	printf("ÇëÊäÈëÃÜÂë!\n");
	scanf("%s", password);
	if (strcmp(password,"111222" ) == 0){
		printf("µÇÂ¼³É¹¦!\n");
		break;
	}
	else {
		printf("ÃÜÂë´íÎó,ÇëÖØÐÂÊäÈë\n");
	}
	}
	if (i == 3){
		printf("µÇÂ¼Ê§°Ü!\n");
	}
	system("pause");
}
