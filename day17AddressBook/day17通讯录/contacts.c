#include "contacts.h"

// leval:INFO,WARNING,ERROR
void LogInfo(const char * leval, const char * msg)
{
    printf("#%s:%s#\n", leval, msg);
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
        int flag = 0;   // 登录成功1    登陆失败0
        while(cnt--)
        {
            printf("密码>");
            scanf("%s", input.user_pwd);    //TODO:密码输入隐藏
            fscanf(fp, "%s", admin.user_pwd);
            fclose(fp);
            if(strcmp(admin.user_pwd, input.user_pwd) == 0)
            {
                LogInfo("提示", "登录成功");
                flag = 1;   // 登录成功
                break;
            }
            else
            {
                LogInfo("提示", "密码错误");
                continue;
            }
        }
        exit(1);    // 多次输入错误，直接退出程序
    }
}
