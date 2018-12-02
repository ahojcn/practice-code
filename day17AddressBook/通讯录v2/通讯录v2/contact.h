
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

// 登陆
// 返回登陆的用户信息
p_user Login(void);

// 初始化(加载)通讯录
// 参数：当前登陆的用户信息
// 返回值：加载好的通讯录。如果是用户第一次登陆，创建一个通讯录，否则加载对应用户的通讯录文件并返回。
p_contact InitContact(p_user p);

// 通讯录扩容函数
// 参数：当前登录的用户信息，通讯录
// 返回扩容好的通讯录
p_contact IncContact(p_user p, pp_contact ppct);


#endif /* contact_h */
