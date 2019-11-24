#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "contact.h"

//1.��ʼ��
void Init(pcontact pc){
	pc->size = 0;
	pc->data = (info*)malloc(sizeof(info*)*DEFAULT);
	pc->capacity = DEFAULT;
}

//2. �����ϵ����Ϣ

//���ռ�
int cheak_capacity(pcontact pc){
	if (pc->size == pc->capacity){
		/*pc->data = (info*)realloc(pc->data, sizeof(info)* pc->capacity + 10);
		if (pc->data == NULL){
			return 0;*/
		info* tmp = (info*)malloc(sizeof(info)*(pc->capacity + 10));
		if (tmp==NULL){
			return 0;
		}
		memcpy(tmp, pc->data, sizeof(info)*pc->size);
		free(pc->data);
		pc->data = tmp;
		pc->capacity += 10;
	}
	return 1;
}

//�����ϵ����Ϣ
void Add(pcontact pc){
	info curinfo;
	if (cheak_capacity(pc)==0){
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
		pc->data[pc->size] = curinfo;
		pc->size++;
	}

}

//3. ɾ��ָ����ϵ����Ϣ

//�ҵ���Ϣ�Ƿ����
int Find(pcontact pc, char* name){
	for (int i = 0; i < pc->size; i++){
		if (strcmp(pc->data[i].name, name) == 0)
		{
			return i;
		}
	}
	return 0;
}

// ɾ��ָ����ϵ����Ϣ
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
		pc->data[i] = pc->data[i - 1];
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
	printf("����:%s\n", pc->data[pos].name);
	printf("�Ա�:%s\n", pc->data[pos].gender);
	printf("����:%d\n",& pc->data[pos].age);
	printf("�绰:%s\n", pc->data[pos].tele);
	printf("��ַ:%s\n", pc->data[pos].addr);
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
	scanf("%s", pc->data[pos].name);
	printf("�������Ա�:\n");
	scanf("%s", pc->data[pos].gender);
	printf("����������:\n");
	scanf("%d", &pc->data[pos].age);
	printf("������绰:\n");
	scanf("%s", pc->data[pos].tele);
	printf("�������ַ:\n");
	scanf("%s", pc->data[pos].addr);
}
//6. ��ʾ������ϵ����Ϣ
void Show(pcontact pc){
	for (int i = 0; i < pc->size; i++){
		printf("===========��%d����============\n",i);
		printf("����:%s\n", pc->data[i].name);
		printf("�Ա�:%s\n", pc->data[i].gender);
		printf("����:%d\n", &pc->data[i].age);
		printf("�绰:%s\n", pc->data[i].tele);
		printf("��ַ:%s\n", pc->data[i].addr);
		printf("===============================\n");
	}
}
//7. ���������ϵ��
void Empty(pcontact pc){
	pc->size = 0;
}
//8. ����������������ϵ��
void Sort(pcontact pc){
	for (int sz = pc->size; sz > 0; sz--){
		for (int i = 0; i < sz; i++){
			if (strcmp(pc->data[i-1].name, pc->data[i].name)>0){
				info tmp = pc->data[i - 1];
				pc->data[i - 1] = pc->data[i];
				pc->data[i] = tmp;
			}
		}
	}
}
//9. ������ϵ�˵��ļ�
void Save(pcontact pc){
	FILE* pf=fopen("contact.dat", "wb");
	if (pf == NULL){
		printf("����ʧ��!\n");
		return;
	}
	for (int i = 0; i < pc->size; i++){
		fwrite(pc->data + i, sizeof(info), 1, pf);
	}
	fclose(pf);
}
//10. ������ϵ��
void Load(pcontact pc){
	FILE* pf = fopen("contact.dat", "rb");
	if (pf == NULL){
		printf("����ʧ��!!\n");
		return;
	}
	//��ȡ�ļ�����
	info curinfo;
	while (fread(&curinfo, sizeof(info), 1, pf)){
		if (cheak_capacity(pc)){
			pc->data[pc->size] = curinfo;
			pc->size++;
		}
	}
	fclose(pf);
}

