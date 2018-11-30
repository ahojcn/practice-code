#include "contacts.h"

int Login(void)
{
    int ret = 0;
    int cnt = 3;    // 登陆尝试次数
    FILE * fp = fopen(LOGIN_INFO_FILE, "r");
    if(fp == NULL)
    {
        printf("%s\n", strerror(errno));
        return -1;
    }
    char input_username[NAME_MAX_SIZE];
    char input_password[PWD_MAX_SIZE];
    char username[NAME_MAX_SIZE];
    char password[PWD_MAX_SIZE];
    
    fscanf(fp, "%s", username);
    fscanf(fp, "%s", password);
    
    while(cnt--)
    {
        printf("用户名>");
        scanf("%s", input_username);
        if(strcmp(input_username, username) == 0)
        {
            printf("密码>");
            scanf("%s", input_password);    // 需要改进！TODO：密码输入隐藏
            if(strcmp(input_password, password) == 0)
            {
                system("clear");
                printf("欢迎，%s。\n", username);
                sleep(2);
                ret = 1;    //登录成功
                cnt = 0;
            }
            else
            {
                printf("密码错误，请重新输入！\n");
            }
        }
        else
        {
            printf("用户名错误！\n");
            ret = -1;
        }
    }
    
    return ret;
}

void Menu(void)
{
    system("clear");
    printf("版本，v0.1。\n");
    printf("####################################\n");
    printf("####\t0. 退出程序\t\t####\n");
    printf("####\t1. 新建一个联系人\t####\n");
    printf("####\t2. 删除一个联系人\t####\n");
    printf("####\t3. 查找一个联系人\t####\n");
    printf("####\t4. 修改联系人信息\t####\n");
    printf("####\t5. 显示所有联系人\t####\n");
    printf("####################################\n");
}

// 新建一个联系人
char * AddNewPerson(void)
{
    Person p;
    p.Name = malloc(NAME_MAX_SIZE);
    p.Address = malloc(ADDRESS_MAX_SIZE);
    p.TelphoneNumber = malloc(TEL_MAX_SIZE);
    
    printf("新建联系人：\n");
    printf("姓名>");
    scanf("%s", p.Name);
    printf("性别(输入1为男性,2为女性)>");
    scanf("%d", &p.Sex);
    printf("年龄>");
    scanf("%hd", &p.Age);
    printf("手机号>");
    scanf("%s", p.TelphoneNumber);
    printf("家庭住址>");
    scanf("%s", p.Address);
    
    FILE * fp = fopen(CONTACTS_INFO_FILE, "a+");
    if(fp == NULL)
    {
        printf("%s\n", strerror(errno));
    }
    
    fprintf(fp, "%s|%d|%d|%s|%s\n", p.Name, p.Sex, p.Age, p.TelphoneNumber, p.Address);
    
    return p.Name;
}
