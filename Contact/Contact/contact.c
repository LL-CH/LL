#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "contact.h"

//1.��ʼ��
void Initi(pcontact pc){
	pc->size = 0;
}
//2. �����ϵ����Ϣ
void Add(pcontact pc){
	info curinfo;
	if (pc->size == MAX){
		printf("ͨѶ¼����!���ʧ��!\n");
		return;
	}
	else{
		printf("����������:\n");
		scanf("%s", curinfo.name);
		printf("�������Ա�:\n");
		scanf("%s", curinfo.gender);
		printf("����������:\n");
		scanf("%d", &curinfo.age);
		printf("������绰:\n");
		scanf("%s", curinfo.tele);
		printf("�������ַ:\n");
		scanf("%s", curinfo.addr);
		pc->date[pc->size] = curinfo;
		pc->size++;
	}

}
//3. ɾ��ָ����ϵ����Ϣ
void Delete(pcontact pc){

}
//4. ����ָ����ϵ����Ϣ
void Find(pcontact pc){

}
//5. �޸�ָ����ϵ����Ϣ
void Modify(pcontact pc){

}
//6. ��ʾ������ϵ����Ϣ
void Show(pcontact pc){

}
//7. ���������ϵ��
void Empty(pcontact pc){

}
//8. ����������������ϵ��
void Sort(pcontact pc){

}
//9. ������ϵ�˵��ļ�
void Save(pcontact pc){

}
//10. ������ϵ��
void Load(pcontact pc){

}

int main(){

	system("pause");
	return 0;
}