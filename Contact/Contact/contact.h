#pragma once
#define NAME_MAX 200
#define GENDER_MAX 10
#define TELE_MAX 20
#define ADDR_MAX 100
#define MAX 200
#define DEFAULT 10

//������ϵ����Ϣ
typedef struct information{
	char name[NAME_MAX];
	char gender[GENDER_MAX];
	int age;
	char tele[TELE_MAX];
	char addr[ADDR_MAX];
}info;

//ͨѶ¼���� ��̬�洢
//typedef struct contact{
//	info data[MAX];
//	int size;
//}contact,*pcontact;

//��̬�洢
typedef struct contact{
	info* data;
	int size;
	int capacity;//�ռ��С
}contact, *pcontact;

//1.��ʼ��
void Init(pcontact pc);
//2. �����ϵ����Ϣ
void Add(pcontact pc);
//3. ɾ��ָ����ϵ����Ϣ
void Delete(pcontact pc);
//4. ����ָ����ϵ����Ϣ
void Sear(pcontact pc);
//5. �޸�ָ����ϵ����Ϣ
void Modify(pcontact pc);
//6. ��ʾ������ϵ����Ϣ
void Show(pcontact pc);
//7. ���������ϵ��
void Empty(pcontact pc);
//8. ����������������ϵ��
void Sort(pcontact pc);
//9. ������ϵ�˵��ļ�
void Save(pcontact pc);
//10. ������ϵ��
void Load(pcontact pc);