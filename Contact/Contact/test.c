#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "contact.h"

enum OPTION{
	EXIT,
	ADD,
	DEL,
	SEAR,
	MOD,
	SHOW,
	EMP,
	SORT,
	SAVE,
	LOAD
};

void menu(){
	printf("==========0:EXIT 1:ADD 2:DEL 3:SEAR 4:MOD==========\n");
	printf("=========5:SHOW 6:EMP 7:SORT 8:SAVE 9:LOAD =========\n");
}

void testcontact(){
	contact ct;
	int option;
	Init(&ct);

	do{
		menu();
		scanf("%d", &option);
		switch (option){
		case EXIT:
			break;
		case ADD:
			Add(&ct);
			break;
		case DEL:
			Delete(&ct);
			break;
		case SEAR:
			Sear(&ct);
			break;
		case MOD:
			Modify(&ct);
			break;
		case SHOW:
			Show(&ct);
			break;
		case EMP:
			Empty(&ct);
			break;
		case SORT:
			Sort(&ct);
			break;
		case SAVE:
			Save(&ct);
			break;
		case LOAD:
			Load(&ct);
			break;
		default:
			printf(" ‰»Î”–ŒÛ!\n");
		}
	} while (option);
}

int main(){
	testcontact();
	system("pause");
	return 0;
}