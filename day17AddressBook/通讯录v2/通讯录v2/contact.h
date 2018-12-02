
#ifndef contact_h
#define contact_h

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <errno.h>

typedef enum USIZE
{
    NAME_SIZE = 20,
    SEX_SIZE = 5,
    AGE_SIZE = 3,
    TEL_SIZE = 15,
    ADDR_SIZE = 100,
    PASSWORD_SIZE = 18,
    INIT_CONTACT_SIZE = 2,
}usize;

typedef struct User
{
    char user_name[NAME_SIZE];
    char user_password[PASSWORD_SIZE];
}user, *p_user, **pp_user;

typedef struct People
{
    char peo_name[NAME_SIZE];
    char peo_sex[SEX_SIZE];
    char peo_age[AGE_SIZE];
    char peo_tel[TEL_SIZE];
    char peo_addr[ADDR_SIZE];
}people, *p_people, **pp_people;

typedef struct Contact
{
    int con_total;
    int con_now;
    people peoples[0];
}contact, *p_contact, **pp_contact;

// 日志
// leval:INFO,WARNING,ERROR
void LogInfo(const char * leval, const char * msg);

// 未登录的菜单
// 登陆，注册
void MenuUnlogin(void);

// 登陆
// 登陆成功则进入功能菜单，否则返回0
int UserLogin(void);

// 注册
// 注册成功返回1，否则返回0
int UserRegist(void);

// 登陆控制
void LoginCtrl(void);





#endif /* contact_h */
