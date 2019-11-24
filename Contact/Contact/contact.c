#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "contact.h"

//1.初始化
void Init(pcontact pc){
	pc->size = 0;
	pc->data = (info*)malloc(sizeof(info*)*DEFAULT);
	pc->capacity = DEFAULT;
}

//2. 添加联系人信息

//检查空间
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

//添加联系人信息
void Add(pcontact pc){
	info curinfo;
	if (cheak_capacity(pc)==0){
		printf("通讯录已满!添加失败!\n");
		return;
	}
	else{
		printf("请输入姓名:\n");
		scanf("%s", curinfo.name);
		printf("请输入性别:\n");
		scanf("%s", curinfo.gender);
		printf("请输入年龄:\n");
		scanf("%d", &curinfo.age);
		printf("请输入电话:\n");
		scanf("%s", curinfo.tele);
		printf("请输入地址:\n");
		scanf("%s", curinfo.addr);
		pc->data[pc->size] = curinfo;
		pc->size++;
	}

}

//3. 删除指定联系人信息

//找到信息是否存在
int Find(pcontact pc, char* name){
	for (int i = 0; i < pc->size; i++){
		if (strcmp(pc->data[i].name, name) == 0)
		{
			return i;
		}
	}
	return 0;
}

// 删除指定联系人信息
void Delete(pcontact pc){
	char name[NAME_MAX];
	printf("输入要删除的名字!\n");
	scanf("%s", name);
	int pos = Find(pc, name);
	if (pos == 0){
		printf("此人不存在,删除失败!\n");
		return;
	}
	for (int i = pos; i < pc->size - 1; i++){
		pc->data[i] = pc->data[i - 1];
	}
	pc->size--;
	printf("删除成功!\n");
}
//4. 查找指定联系人信息
void Sear(pcontact pc){
	char name[NAME_MAX];
	printf("输入要查找的名字!\n");
	scanf("%s", name);
	int pos = Find(pc, name);
	if (pos == 0){
		printf("此人不存在,查找失败!\n");
		return;
	}
	printf("===============================\n");
	printf("姓名:%s\n", pc->data[pos].name);
	printf("性别:%s\n", pc->data[pos].gender);
	printf("年龄:%d\n",& pc->data[pos].age);
	printf("电话:%s\n", pc->data[pos].tele);
	printf("地址:%s\n", pc->data[pos].addr);
	printf("===============================\n");
}
//5. 修改指定联系人信息
void Modify(pcontact pc){
	char name[NAME_MAX];
	printf("输入要修改的名字!\n");
	scanf("%s", name);
	int pos = Find(pc, name);
	if (pos == 0){
		printf("此人不存在,修改失败!\n");
		return;
	}
	printf("请输入姓名:\n");
	scanf("%s", pc->data[pos].name);
	printf("请输入性别:\n");
	scanf("%s", pc->data[pos].gender);
	printf("请输入年龄:\n");
	scanf("%d", &pc->data[pos].age);
	printf("请输入电话:\n");
	scanf("%s", pc->data[pos].tele);
	printf("请输入地址:\n");
	scanf("%s", pc->data[pos].addr);
}
//6. 显示所有联系人信息
void Show(pcontact pc){
	for (int i = 0; i < pc->size; i++){
		printf("===========第%d个人============\n",i);
		printf("姓名:%s\n", pc->data[i].name);
		printf("性别:%s\n", pc->data[i].gender);
		printf("年龄:%d\n", &pc->data[i].age);
		printf("电话:%s\n", pc->data[i].tele);
		printf("地址:%s\n", pc->data[i].addr);
		printf("===============================\n");
	}
}
//7. 清空所有联系人
void Empty(pcontact pc){
	pc->size = 0;
}
//8. 以名字排序所有联系人
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
//9. 保存联系人到文件
void Save(pcontact pc){
	FILE* pf=fopen("contact.dat", "wb");
	if (pf == NULL){
		printf("保存失败!\n");
		return;
	}
	for (int i = 0; i < pc->size; i++){
		fwrite(pc->data + i, sizeof(info), 1, pf);
	}
	fclose(pf);
}
//10. 加载联系人
void Load(pcontact pc){
	FILE* pf = fopen("contact.dat", "rb");
	if (pf == NULL){
		printf("加载失败!!\n");
		return;
	}
	//读取文件内容
	info curinfo;
	while (fread(&curinfo, sizeof(info), 1, pf)){
		if (cheak_capacity(pc)){
			pc->data[pc->size] = curinfo;
			pc->size++;
		}
	}
	fclose(pf);
}

