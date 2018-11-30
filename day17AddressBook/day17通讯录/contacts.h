#ifndef contacts_h
#define contacts_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <errno.h>
#include <time.h>
#include <unistd.h>

#define NAME_MAX_SIZE 20
#define PWD_MAX_SIZE 20
#define TEL_MAX_SIZE 15
#define ADDRESS_MAX_SIZE 100

#define LOGIN_INFO_FILE "log.in"
#define CONTACTS_INFO_FILE "info.txt"

typedef enum Sex
{
    MAN = 1,
    WOMAN
}Sex;

typedef struct Person
{
    char * Name;
    Sex Sex;
    short Age;
    char * TelphoneNumber;
    char * Address;
}Person;

// 显示菜单
void Menu(void);

// 核对登陆信息，登陆成功返回1，登录失败返回-1。
int Login(void);

// 新建一个联系人，返回联系人的姓名
char * AddNewPerson(void);



#endif /* contacts_h */
