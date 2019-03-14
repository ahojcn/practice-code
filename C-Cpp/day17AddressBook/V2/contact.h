
#ifndef contact_h
#define contact_h

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <errno.h>
#include <ctype.h>

typedef enum USIZE
{
    NAME_SIZE = 20,
    SEX_SIZE = 5,
    AGE_SIZE = 3,
    TEL_SIZE = 15,
    ADDR_SIZE = 100,
    PASSWORD_SIZE = 18,
    INIT_CONTACT_SIZE = 100,
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

// 功能主控函数
// 参数：当前登陆的用户
void MainCtrl(p_user pu);

// 登陆成功后的功能菜单
void MainMenu(p_user pu);

// 初始化通讯录
// 参数：当前登陆的用户
// 返回值：初始化好的通讯录指针。如果是首次登陆(不存在目前用户的通讯录文件)则创建新文件，否则加载已有文件
p_contact ContactInit(p_user pu);

// 根据用户名获取当前的通讯录文件名
char * GetFileName(p_user pu);

// 判断通讯录是否为满
// 满了返回1，否则返回0
int ContactIsFull(p_contact pct);

// 判断通讯录是否为空
// 是返回1，否则返回0
int ContactIsEmpty(p_contact pct);

// 增加一个联系人
// 参数：当前打开的通讯录
void AddPeople(p_contact pct);

// 输入联系人的信息
void GetPeopleInfo(p_people pp);

// 按姓名查找联系人
void SearchPeople(p_contact pct);

// 输出联系人信息
void DispPeopleInfo(p_people pp);

// 根据联系人姓名排序
void SortPeople(p_contact pct);

// 比较函数（回调函数）
int NameCmpFun(const void * n1, const void * n2);

// 显示所有联系人信息
void DispAllPeople(p_contact pct);

// 删除单个联系人
void DeletePeople(p_contact pct);

// 清空所有联系人
// 参数：传入当前打开的通讯录文件，当前用户(验证密码用)
void ClearAllPeople(p_contact pct, p_user pu);

// 扩容函数
// 扩容成功返回1 否则返回0
int IncContact(pp_contact ppct);

// 在程序退出的时候保存信息到文件
void SaveToFile(p_contact pct, p_user pu);


#endif /* contact_h */
