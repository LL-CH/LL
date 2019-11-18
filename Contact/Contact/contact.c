#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "contact.h"

//1.初始化
void Initi(pcontact pc){
	pc->size = 0;
}
//2. 添加联系人信息
void Add(pcontact pc){
	info curinfo;
	if (pc->size == MAX){
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
		pc->date[pc->size] = curinfo;
		pc->size++;
	}

}
//3. 删除指定联系人信息
void Delete(pcontact pc){

}
//4. 查找指定联系人信息
void Find(pcontact pc){

}
//5. 修改指定联系人信息
void Modify(pcontact pc){

}
//6. 显示所有联系人信息
void Show(pcontact pc){

}
//7. 清空所有联系人
void Empty(pcontact pc){

}
//8. 以名字排序所有联系人
void Sort(pcontact pc){

}
//9. 保存联系人到文件
void Save(pcontact pc){

}
//10. 加载联系人
void Load(pcontact pc){

}

int main(){

	system("pause");
	return 0;
}