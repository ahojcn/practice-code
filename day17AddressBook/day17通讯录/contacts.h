#ifndef contacts_h
#define contacts_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <errno.h>
#include <time.h>
#include <unistd.h>

#define NAME_SIZE 20
#define PASSWORD_SIZE 20
#define SEX_SIZE 5
#define TEL_SIZE 15
#define ADDRESS_SIZE 100

typedef struct user_info
{
    char * user_name;
    char * user_pwd;
}user_info;

typedef struct person
{
    char * person_name;
    char * person_sex;
    int person_age;
    char * person_telphone;
    char * person_address;
}person, *p_person, **pp_person;

void LogInfo(const char * leval, const char * msg);

void Login(void);


#endif /* contacts_h */
