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
#define INIT_CONTACT 100

typedef struct user_info
{
    char * user_name;
    char * user_pwd;
}user_info;

typedef struct person
{
    char person_name[NAME_SIZE];
    char person_sex[SEX_SIZE];
    int person_age;
    char person_telphone[TEL_SIZE];
    char person_address[ADDRESS_SIZE];
}person, *p_person, **pp_person;

typedef struct contact
{
    int contact_total;
    int contact_now;
    person contact_people[0];   // 柔性数组
}contact, *p_contact, **pp_contact;

void LogInfo(const char * leval, const char * msg);

void Login(void);

void Menu(void);

p_contact InitContact(p_contact ct);

void EnterPersonInfo(p_person p);

void AddPerson(pp_contact ct);

void DeletePerson(p_contact ct);

void SortPerson(p_contact ct);

void SearchPerson(p_contact ct);

#endif /* contacts_h */
