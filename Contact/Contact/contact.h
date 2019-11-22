#pragma once
#define NAME_MAX 200
#define GENDER_MAX 10
#define TELE_MAX 20
#define ADDR_MAX 100
#define MAX 200
#define DEFAULT 10

//定义联系人信息
typedef struct information{
	char name[NAME_MAX];
	char gender[GENDER_MAX];
	int age;
	char tele[TELE_MAX];
	char addr[ADDR_MAX];
}info;

//通讯录内容 静态存储
//typedef struct contact{
//	info data[MAX];
//	int size;
//}contact,*pcontact;

//动态存储
typedef struct contact{
	info* data;
	int size;
	int capacity;//空间大小
}contact, *pcontact;

//1.初始化
void Init(pcontact pc);
//2. 添加联系人信息
void Add(pcontact pc);
//3. 删除指定联系人信息
void Delete(pcontact pc);
//4. 查找指定联系人信息
void Sear(pcontact pc);
//5. 修改指定联系人信息
void Modify(pcontact pc);
//6. 显示所有联系人信息
void Show(pcontact pc);
//7. 清空所有联系人
void Empty(pcontact pc);
//8. 以名字排序所有联系人
void Sort(pcontact pc);
//9. 保存联系人到文件
void Save(pcontact pc);
//10. 加载联系人
void Load(pcontact pc);