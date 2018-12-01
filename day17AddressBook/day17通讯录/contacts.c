#include "contacts.h"

// Menu function
void Menu(void)
{
    printf("############################################\n");
    printf("## 1. Add                      2. Delete  ##\n");
    printf("## 3. Sort                     4. Search  ##\n");
    printf("## 5. List                     6. Clear   ##\n");
    printf("##                             0. Exit    ##\n");
    printf("############################################\n");
    printf("*Enter>");
}

// leval:INFO,WARNING,ERROR
void LogInfo(const char * leval, const char * msg)
{
    assert(leval);
    assert(msg);
    printf("*%s:%s\n", leval, msg);
}

// is full return 1, else return 0
int ContactIsFull(p_contact ct)
{
    assert(ct);
    return ct->contact_now == ct->contact_total ? 1 : 0;
}

// is empty return 1, else return 0
int ContactIsEmpty(p_contact ct)
{
    assert(ct);
    return ct->contact_now == 0 ? 1 : 0;
}

int ContactCmp(const void * s1, const void * s2)
{
    assert(s1);
    assert(s2);
    p_person p1 = (p_person)s1;
    p_person p2 = (p_person)s2;
    return strcmp(p1->person_name, p2->person_name);
}

void ShowPersonInfo(p_person p)
{
    assert(p);
    printf("姓名:");
    printf("%s\n", p->person_name);
    printf("性别:");
    printf("%s\n", p->person_sex);
    printf("年龄:");
    printf("%d\n", p->person_age);
    printf("手机号:");
    printf("%s\n", p->person_telphone);
    printf("家庭地址:");
    printf("%s\n", p->person_address);
}

// TODO:文件加密处理
void Login(void )
{
    user_info input;
    user_info admin;
    input.user_name = malloc(NAME_SIZE);
    input.user_pwd = malloc(PASSWORD_SIZE);
    admin.user_pwd = malloc(PASSWORD_SIZE);
    
    printf("用户名>");
    scanf("%s", input.user_name);
    FILE * fp = fopen(input.user_name, "r");
    while(!fp)
    {
        char msg[30] = "不存在的用户";
        strcat(msg, input.user_name);
        LogInfo("错误", msg);
        
        printf("用户名>");
        scanf("%s", input.user_name);
        fp = fopen(input.user_name, "r");
    }
    
    if(fp)
    {
        int cnt = 3;    // 尝试输入密码的最大次数
        while(cnt--)
        {
            printf("密码>");
            scanf("%s", input.user_pwd);    //TODO:密码输入隐藏
            fscanf(fp, "%s", admin.user_pwd);
            puts(admin.user_pwd);
            fclose(fp);
            if(strcmp(admin.user_pwd, input.user_pwd) == 0)
            {
                LogInfo("INFO", "登录成功");
                return;
            }
            else
            {
                LogInfo("INFO", "密码错误");
                continue;
            }
        }
        exit(1);    // 多次输入错误，直接退出程序
    }
}

p_contact InitContact(p_contact ct)
{
    assert(ct);
    ct = (p_contact)malloc(sizeof(contact) + INIT_CONTACT * sizeof(person));
    if(ct)
    {
        ct->contact_now = 0;
        ct->contact_total = INIT_CONTACT;
        LogInfo("INFO", "初始化成功");
        return ct;
    }
    else
    {
        LogInfo("ERROR", "初始化失败");
        return NULL;
    }
}

void EnterPersonInfo(p_person p)
{
    assert(p);
    printf("姓名>");
    scanf("%s", p->person_name);
    printf("性别>");
    scanf("%s", p->person_sex);
    printf("年龄>");
    scanf("%d", &p->person_age);
    printf("手机号>");
    scanf("%s", p->person_telphone);
    printf("家庭地址>");
    scanf("%s", p->person_address);
}

void AddPerson(pp_contact ct)
{
    assert(ct);
    if(ContactIsFull(*ct))
    {
        LogInfo("WARNING", "通讯录已满");
        return;
        // TODO: 扩容
    }
    person p;
    EnterPersonInfo(&p);
    memcpy(&(((*ct)->contact_people)[(*ct)->contact_now]), &p, sizeof(person));
    (*ct)->contact_now++;
    LogInfo("INFO", "添加联系人成功");
}

void DeletePerson(p_contact ct)
{
    assert(ct);
    
    if(ContactIsEmpty(ct))
    {
        LogInfo("WARNING", "通讯录为空");
        return;
    }
    else
    {
        char name[NAME_SIZE];
        printf("*联系人姓名>");
        scanf("%s", name);
        int flag = 0;   // 要找的联系人存在flag=1，否则flag=0
        int i=0;
        for(i=0; i<ct->contact_now; i++)
        {
            if(strcmp(ct->contact_people[i].person_name, name) == 0)
            {
                flag = 1;
                memcpy(&(ct->contact_people[i]), &(ct->contact_people[ct->contact_now-1]), sizeof(person));
                ct->contact_now--;
                LogInfo("INFO", "删除联系人成功");
                return;
            }
        }
        if(flag == 0)
        {
            LogInfo("INFO", "没有这个外星人");
        }
    }
}

void SortPerson(p_contact ct)
{
    assert(ct);
    qsort(ct->contact_people, ct->contact_now, sizeof(person), ContactCmp);
    LogInfo("INFO", "排序完成");
}

void SearchPerson(p_contact ct)
{
    assert(ct);
    
    char name[NAME_SIZE];
    printf("*联系人姓名>");
    scanf("%s", name);
    
    for(int i=0; i<ct->contact_now; i++)
    {
        if(strcmp(ct->contact_people[i].person_name, name) == 0)
        {
            ShowPersonInfo(&(ct->contact_people[i]));
        }
    }
    LogInfo("INFO", "查找完成");
}
