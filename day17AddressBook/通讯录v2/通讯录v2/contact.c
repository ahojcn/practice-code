
#include "contact.h"

void LogInfo(const char * leval, const char * msg)
{
    printf("#%s:%s\n", leval, msg);
}

void MenuUnlogin(void)
{
    LogInfo("INFO", "通讯录 V2.0");
    printf("########################\n");
    printf("#### 0.   退出      ####\n");
    printf("#### 1.   登陆      ####\n");
    printf("#### 2.   注册      ####\n");
    printf("########################\n");
    printf(">");
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
