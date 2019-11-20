#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "contact.h"

//1.��ʼ��
void Init(pcontact pc){
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

int Find(pcontact pc, char* name){
	for (int i = 0; i < pc->size; i++){
		if (strcmp(pc->date[i].name , name)==0)
		{
			return i;
		}
	}
	return 0;
}

//3. ɾ��ָ����ϵ����Ϣ
void Delete(pcontact pc){
	char name[NAME_MAX];
	printf("����Ҫɾ��������!\n");
	scanf("%s", name);
	int pos = Find(pc, name);
	if (pos == 0){
		printf("���˲�����,ɾ��ʧ��!\n");
		return;
	}
	for (int i = pos; i < pc->size - 1; i++){
		pc->date[i] = pc->date[i - 1];
	}
	pc->size--;
	printf("ɾ���ɹ�!\n");
}
//4. ����ָ����ϵ����Ϣ
void Sear(pcontact pc){
	char name[NAME_MAX];
	printf("����Ҫ���ҵ�����!\n");
	scanf("%s", name);
	int pos = Find(pc, name);
	if (pos == 0){
		printf("���˲�����,����ʧ��!\n");
		return;
	}
	printf("===============================\n");
	printf("����:%s\n", pc->date[pos].name);
	printf("�Ա�:%s\n", pc->date[pos].gender);
	printf("����:%d\n",& pc->date[pos].age);
	printf("�绰:%s\n", pc->date[pos].tele);
	printf("��ַ:%s\n", pc->date[pos].addr);
	printf("===============================\n");
}
//5. �޸�ָ����ϵ����Ϣ
void Modify(pcontact pc){
	char name[NAME_MAX];
	printf("����Ҫ�޸ĵ�����!\n");
	scanf("%s", name);
	int pos = Find(pc, name);
	if (pos == 0){
		printf("���˲�����,�޸�ʧ��!\n");
		return;
	}
	printf("����������:\n");
	scanf("%s", pc->date[pos].name);
	printf("�������Ա�:\n");
	scanf("%s", pc->date[pos].gender);
	printf("����������:\n");
	scanf("%d", &pc->date[pos].age);
	printf("������绰:\n");
	scanf("%s", pc->date[pos].tele);
	printf("�������ַ:\n");
	scanf("%s", pc->date[pos].addr);
}
//6. ��ʾ������ϵ����Ϣ
void Show(pcontact pc){
	for (int i = 0; i < pc->size; i++){
		printf("===========��%d����============\n",i);
		printf("����:%s\n", pc->date[i].name);
		printf("�Ա�:%s\n", pc->date[i].gender);
		printf("����:%d\n", &pc->date[i].age);
		printf("�绰:%s\n", pc->date[i].tele);
		printf("��ַ:%s\n", pc->date[i].addr);
		printf("===============================\n");
	}
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

