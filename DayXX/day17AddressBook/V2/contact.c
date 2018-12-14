
#include "contact.h"

void LogInfo(const char * leval, const char * msg)
{
    assert(leval);
    assert(msg);
    printf("#%s:%s\n", leval, msg);
}

int ContactIsFull(p_contact pct)
{
    assert(pct);
    return pct->con_now == pct->con_total ? 1 : 0;
}

int ContactIsEmpty(p_contact pct)
{
    assert(pct);
    return pct->con_now == 0 ? 1 : 0;
}

void MenuUnlogin(void)
{
    LogInfo("INFO", "通讯录 V2.0");
    printf("########################\n");
    printf("####   0.  退出     ####\n");
    printf("####   1.  登陆     ####\n");
    printf("####   2.  注册     ####\n");
    printf("########################\n");
    printf(">");
}

void MainMenu(p_user pu)
{
    assert(pu);
    char msg[30] = "当前用户";strcat(msg, pu->user_name);
    LogInfo("INFO", msg);
    printf("##############################\n");
    printf("####  0.  退出            ####\n");
    printf("####  1.  添加联系人      ####\n");
    printf("####  2.  查找联系人      ####\n");
    printf("####  3.  排序联系人      ####\n");
    printf("####  4.  删除联系人      ####\n");
    printf("####  5.  列出所有联系人  ####\n");
    printf("####  6.  清空所有联系人  ####\n");
    printf("##############################\n");
    printf(">");
}

char * GetFileName(p_user pu)
{
    assert(pu);
    char * contact_file_name = malloc(30);
    strcpy(contact_file_name, pu->user_name);
    strcat(contact_file_name, ".txt");
    return contact_file_name;
}

int UserLogin(void)
{
    user u;
    FILE * fp = NULL;
    printf("用户名>");
    scanf("%s", u.user_name);
    
    fp = fopen(u.user_name, "r");
    if(!fp)
    {
        char msg[30] = "用户";strcat(msg, u.user_name);strcat(msg, "不存在");
        LogInfo("ERROR", msg);
        fclose(fp);
    }
    else
    {
        char pwd[PASSWORD_SIZE];
        fscanf(fp, "%s", u.user_password);
        printf("密码>");
        scanf("%s", pwd);
        if(0 == strcmp(pwd, u.user_password))
        {
            char msg[30] = "欢迎";strcat(msg, u.user_name);
            LogInfo("INFO", msg);
            // GOTO: MainCtrl
            MainCtrl(&u); /* 登录成功，跳到主要功能控制函数，并传入登陆的用户信息 */
            exit(0);
        }
        else
        {
            LogInfo("ERROR", "密码错误");
        }
    }
    
    
    return 0;
}

int UserRegist(void)
{
    user u;
    FILE * fp = NULL;
    int flag = 1;
    while(flag)
    {
        printf("用户名>");
        scanf("%s", u.user_name);
        fp = fopen(u.user_name, "r");
        if(fp) // 如果打开文件成功，说明存在此用户
        {
            fclose(fp);
            char msg[30] = "用户名";strcat(msg, u.user_name);strcat(msg, "已被注册");
            LogInfo("ERROR", msg);
            flag = 1;
            continue;
        }
        flag = 0;
    }
    
    printf("密码>");
    scanf("%s", u.user_password);
    fp = fopen(u.user_name, "a+");
    if(!fp)
    {
        LogInfo("ERROR", "创建用户文件失败，请检查当前目录权限");
        return 0;
    }
    else
    {
        fprintf(fp, "%s", u.user_password);
        fclose(fp);
        LogInfo("INFO", "注册成功");
    }
    
    return 0;
}

void LoginCtrl(void)
{
    int select = 1;
    while(select)
    {
        MenuUnlogin();
        scanf("%d", &select);
        switch(select)
        {
            case 0: // exit
                LogInfo("INFO", "再见");
                exit(0);
            case 1: // login
                UserLogin();
                break;
            case 2: // registe
                UserRegist();
                break;
            default:
                LogInfo("INFO", "输入有误");
                break;
        }
    }
}


// 初始化通讯录
// 参数：当前登陆的用户
// 返回值：初始化好的通讯录指针。如果是首次登陆(不存在目前用户的通讯录文件)则创建新文件，否则加载已有文件
p_contact ContactInit(p_user pu)
{
    assert(pu);
    p_contact pct = malloc(INIT_CONTACT_SIZE*sizeof(people) + sizeof(contact));
    if(!pct)
    {
        LogInfo("ERROR", "初始化通讯录失败，分配通讯录空间失败");
        return NULL;
    }
    
    char contact_file_name[30];
    strcpy(contact_file_name, GetFileName(pu));
    
    FILE * fp = fopen(contact_file_name, "r");
    if(!fp) // 如果没有文件
    {
        LogInfo("INFO", "正在创建当前用户的通讯录文件");
        fp = fopen(contact_file_name, "wb+");
        if(!fp) // 创建文件失败
        {
            LogInfo("ERROR", "创建文件失败");
            return NULL;
        }
        else // 创建文件成功
        {
            fclose(fp);
            LogInfo("INFO", "创建当前用户的通讯录文件成功");
            pct->con_total = INIT_CONTACT_SIZE;
            pct->con_now = 0;
        }
    }
    else // 存在文件
    {
        fp = fopen(contact_file_name, "rb+");
        fread(pct, sizeof(*pct), 1, fp);
        pct = malloc(sizeof(people) * pct->con_total + sizeof(contact));
        if(!pct)
        {
            LogInfo("ERROR", "分配空间失败");
            return NULL;
        }
        else
        {
            fread(pct->peoples, sizeof(people)*pct->con_now, 1, fp);
            fclose(fp);
            return pct;
        }
    }
    
    return pct;
}

int IncContact(pp_contact ppct)
{
    assert(ppct);
    
    int new_total = (*ppct)->con_total * 2;
    int new_size = new_total * sizeof(people) * 2 + sizeof(contact);
    
    p_contact pct = (p_contact)realloc(*ppct, new_size);
    if(!pct)
    {
        LogInfo("ERROR", "扩容失败");
        return 0;
    }
    pct->con_total = new_total;
    *ppct = pct;
    LogInfo("INFO", "扩容成功");
    return 1;;
}

void AddPeople(p_contact pct)
{
    assert(pct);
    
    if(ContactIsFull(pct))
    {
        LogInfo("INFO", "通讯录已满，正在扩容");
        IncContact(&pct);
    }
    GetPeopleInfo(&pct->peoples[pct->con_now]);
    char msg[30] = "已添加联系人";
    strcat(msg, pct->peoples[pct->con_now].peo_name);
    LogInfo("INFO", msg);
    pct->con_now ++;
}

void GetPeopleInfo(p_people pp)
{
    assert(pp);
    printf("姓名>");
    scanf("%s", pp->peo_name);
    printf("性别>");
    scanf("%s", pp->peo_sex);
    printf("年龄>");
    scanf("%s", pp->peo_age);
    printf("电话>");
    scanf("%s", pp->peo_tel);
    printf("住址>");
    scanf("%s", pp->peo_addr);
}

void SearchPeople(p_contact pct)
{
    assert(pct);
    char input_name[NAME_SIZE];
    printf("要查找的联系人姓名>");
    scanf("%s", input_name);
    for(int i=0; i<pct->con_now; i++)
    {
        if(0 == strcmp(input_name, pct->peoples[i].peo_name))
        {
            DispPeopleInfo(&pct->peoples[i]);
        }
    }
}

void DispPeopleInfo(p_people pp)
{
    assert(pp);
//    printf("|姓名\t\t|");
//    printf("性别\t\t|");
//    printf("年龄\t\t|");
//    printf("电话\t\t|");
//    printf("住址\t\t|\n");
    printf("|%s\t\t", pp->peo_name);
    printf("|%s\t\t", pp->peo_sex);
    printf("|%s\t\t", pp->peo_age);
    printf("|%s\t\t", pp->peo_tel);
    printf("|%s\t\t|\n", pp->peo_addr);
}

int NameCmpFun(const void * n1, const void * n2)
{
    assert(n1);
    assert(n2);
    p_people p1 = (p_people)n1;
    p_people p2 = (p_people)n2;
    return strcmp(p1->peo_name, p2->peo_name);
}

void SortPeople(p_contact pct)
{
    assert(pct);
    LogInfo("INFO", "正在按姓名排序所有联系人");
    qsort(&pct->peoples, pct->con_now, sizeof(people), NameCmpFun);
    LogInfo("INFO", "排序完成");
}

void DispAllPeople(p_contact pct)
{
    assert(pct);
    printf("|姓名\t\t|");
    printf("性别\t\t|");
    printf("年龄\t\t|");
    printf("电话\t\t|");
    printf("住址\t\t|\n");
    for(int i=0; i<pct->con_now; i++)
    {
        DispPeopleInfo(&pct->peoples[i]);
    }
}

void DeletePeople(p_contact pct)
{
    assert(pct);
    
    if(ContactIsEmpty(pct))
    {
        LogInfo("INFO", "通讯录为空");
        return;
    }
    /*  TODO:优化！删除首先是要查找，可以利用上面的查找函数！(修改下查找函数的返回值)  */
    char input_name[NAME_SIZE];
    printf("要查找的联系人姓名>");
    scanf("%s", input_name);
    for(int i=0; i<pct->con_now; i++)
    {
        if(0 == strcmp(input_name, pct->peoples[i].peo_name))
        {
            memcpy(&pct->peoples[i], &pct->peoples[pct->con_now - 1], sizeof(people));
            pct->con_now--;
            LogInfo("INFO", "删除成功");
        }
    }
}

char * StrToLower(char * str)
{
    assert(str);
    char * ret = str;
    while(*str)
    {
        *str = tolower(*str);
        str++;
    }
    return ret;
}

void ClearAllPeople(p_contact pct, p_user pu)
{
    assert(pct);
    assert(pu);
    
    LogInfo("WARNING", "确定?");
//    fflush(stdin);  // 调试中，输入6回车后到这里就会接收到回车
//    int YorN = 0;
//    scanf("%c*", &YorN);
//    YorN = getchar();
    printf("(yes/no)>");
    char yesORno[5] = {0};
    scanf("%s", yesORno);
    StrToLower(yesORno);
//    puts(yesORno);
    if(0 == strcmp(yesORno, "yes"))
    {
        char pwd[PASSWORD_SIZE];
        printf("密码>");
        scanf("%s", pwd);
        if(0 == strcmp(pwd, pu->user_password))   // 密码校验成功，清空所有联系人
        {
            pct->con_now = 0;
            LogInfo("INFO", "清空成功");
        }
        else
        {
            LogInfo("ERROR", "密码错误");
            return;
        }
    }
    else
    {
        return;
    }
}

void SaveToFile(p_contact pct, p_user pu)
{
    assert(pct);
    assert(pu);
    
    char * filename = GetFileName(pu);
    
    FILE * fp = fopen(filename, "rb");
    if(!fp)
    {
        LogInfo("ERROR", "保存文件过程中，打开文件失败");
        return;
    }
    fwrite(pct, sizeof(contact) + pct->con_now * sizeof(people), 1, fp);
    LogInfo("INFO", "文件保存成功");
    fclose(fp);
}

void MainCtrl(p_user pu)
{
    assert(pu);
    int select = 1;
    p_contact pct = NULL;
    // Init contact
    pct = ContactInit(pu);
    
    while(select)
    {
        MainMenu(pu);
        scanf("%d", &select);
        switch(select)
        {
            case 0:
                SaveToFile(pct, pu);
                LogInfo("INFO", "再见");
                return; // 在登陆函数中退出
                break;
            case 1:// add
                AddPeople(pct);
                break;
            case 2:// search
                SearchPeople(pct);
                break;
            case 3:// sort
                SortPeople(pct);
                break;
            case 4:// delete
                DeletePeople(pct);
                break;
            case 5:// show all
                DispAllPeople(pct);
                break;
            case 6:// clear all
                ClearAllPeople(pct, pu);
                break;
            default:
                LogInfo("WARNING", "输入有误");
                break;
        }/* switch */
    }/* while */
}


