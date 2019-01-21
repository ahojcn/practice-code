



#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// 我这里只是举个例子
#define MAXLENGTH 20    // 姓名等的长度
#define MAXNUM 60    // 最大长度限制

typedef struct Stu
{
    char *id;
    char *name;
    struct Stu *next;
} Student;

Student *CreateFromKeyBoard(int total);

void TestShowAll(const Student *p_head);

int main(int argc, char const *argv[])
{
    int total = 0;
    scanf("%d", &total);

    Student *stu = CreateFromKeyBoard(total);
    TestShowAll(stu);
    return 0;
}

Student *CreateFromKeyBoard(int total)
{
    assert(total >= 0 && total < MAXNUM);
    // 初始化一个头节点
    Student *p_head = (Student *)malloc(sizeof(Student));
    p_head->id = NULL;
    p_head->name = NULL;
    p_head->next = NULL;

    // 头插方式建立单链表
    while (total--)
    {
        Student *new_node = (Student *)malloc(sizeof(Student));
        new_node->id = (char *)malloc(sizeof(char) * MAXLENGTH);
        new_node->name = (char *)malloc(sizeof(char) * MAXLENGTH);
        scanf("%s", new_node->id);
        scanf("%s", new_node->name);

        new_node->next = p_head->next;
        p_head->next = new_node;
    }

    return p_head;
}

void TestShowAll(const Student *p_head)
{
    assert(p_head != NULL);
    const Student *p = p_head->next;
    while (p != NULL)
    {
        printf("%s | %s\n", p->id, p->name);
        p = p->next;
    }
}



