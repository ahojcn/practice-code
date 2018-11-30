/*
 2.实现一个通讯录；
 通讯录可以用来存储1000个人的信息，每个人的信息包括：
 姓名、性别、年龄、电话、住址
 
 提供方法：
 1.添加联系人信息
 2.删除指定联系人信息
 3.查找指定联系人信息
 4.修改指定联系人信息
 5.显示所有联系人信息
 6.清空所有联系人
 7.以名字排序所有联系人
 8.保存联系人到文件
 9.加载联系人
 */
#include "contacts.h"

#define CREATE_FILE_INFO "create.html"

int main(int argc, const char * argv[])
{
    FILE * fout = fopen(CREATE_FILE_INFO, "a+");
    if(fout == NULL)
    {
        printf("%s\n", strerror(errno));
    }
    Person p;
    p.Name = malloc(NAME_MAX_SIZE);
    p.Address = malloc(ADDRESS_MAX_SIZE);
    p.TelphoneNumber = malloc(TEL_MAX_SIZE);
    
    strcpy(p.Name, "刘你好");
    p.Sex = 1;
    strcpy(p.TelphoneNumber, "15229720759");
    strcpy(p.Address, "陕西省西安市临潼区");
    for(int i=0; i<20; i++)
    {
        p.Age = rand()%20+1;
        fprintf(fout, "%s|%d|%d|%s|%s\n", p.Name, p.Sex, p.Age, p.TelphoneNumber, p.Address);
    }
    
    
    
//    if(Login() == -1)
//    {
//        exit(1);    // 登陆失败退出
//    }
//
//    int input = -1;
//    while(input != 0)
//    {
//        Menu();
//        scanf("%d", &input);
//        switch(input)
//        {
//            case 0:
//                printf("Bye!\n");
//                exit(0);    // 正常退出
//                break;
//            case 1: // 新建一个联系人
//                printf("添加联系人：%s成功！\n", AddNewPerson());
//                sleep(2);
//                break;
//
//            default:
//                break;
//        }
//    }
    
    return 0;
}
