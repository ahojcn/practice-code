
#include "List.h"

// 单链表的初始化
void InitList(LinkList *L)
{
    assert(L != NULL);
    *L = (LinkList)malloc(sizeof(Node));
    (*L)->next = NULL;
}

// 打印单链表的内容
void ShowList(LinkList L)
{
    assert(L != NULL);

    Node *p = L->next;
    if(p == NULL)
    {
        printf("NULL List");
    }
    while (p != NULL)
    {
        printf("%d,", p->data);
        p = p->next;
    }
    printf("\n");
}

// 头插法建立单链表
void CreateFromHead(LinkList L)
{
    assert(L != NULL);

    Node *s = NULL;
    for (int i = 0; i < TEST_SIZE; i++)
    {
        s = (LinkList)malloc(sizeof(Node));
        s->data = i + 1;
        s->next = L->next;
        L->next = s;
    }
}

// 尾插法建立单链表
void CreateFromTail(LinkList L)
{
    assert(L != NULL);

    Node *s = NULL;
    Node *p = L; // 工作指针
    for (int i = 0; i < TEST_SIZE; i++)
    {
        s = (LinkList)malloc(sizeof(Node));
        s->data = i + 1;
        p->next = s;
        p = p->next;
        s->next = NULL;
    }
}

// 在L中查找第i个节点，返回这个节点
LinkList GetNode(LinkList L, int i)
{
    assert(L != NULL);

    Node *p = NULL; // 工作指针
    int count = 1;
    if (i <= 0)
    {
        p = NULL;
    }
    else
    {
        p = L;
        while (p->next != NULL && count < i)
        {
            p = p->next;
            count++;
        }
        if (count != i)
        {
            p = NULL;
        }
    }
    return p;
}

// 在L中查找data为e的元素，返回这个节点
LinkList Locate(LinkList L, ElemType e)
{
    assert(L != NULL);

    Node *p = L; // 工作指针
    while (p != NULL)
    {
        if (p->data == e)
        {
            break;
        }
        else
        {
            p = p->next;
        }
    }
    return p;
}

// 返回链表长度
int ListLength(LinkList L)
{
    assert(L != NULL);

    Node *p = L;
    int count = 0;
    while (p->next != NULL)
    {
        p = p->next;
        count++;
    }
    return count;
}

// 在L的第i个位置上插入data为e的新结点
void InsertList(LinkList L, int i, ElemType e)
{
    assert(L != NULL);

    if (i < 0 || i > ListLength(L))
    {
        // printf("非法的插入位置i\n");
        return;
    }
    else
    {
        Node *p = L;
        int count = 0;
        // 找位置
        while (p != NULL && count < i)
        {
            p = p->next;
            count++;
        }
        // 插入
        Node *s = (LinkList)malloc(sizeof(Node));
        s->data = e;
        s->next = p->next;
        p->next = s;
        // printf("插入成功\n");
    }
}

// 删除L上第i个节点
void DeleteList(LinkList L, int i)
{
    assert(L != NULL);
    if (i < 0 || i > ListLength(L))
    {
        // printf("i error\n");
        return;
    }
    else
    {
        Node *p = L->next;
        Node *pre = L;
        int count = 0;
        // 找位置
        while (p != NULL && count < i)
        {
            pre = p;
            p = p->next;
            count++;
        }
        // 删除
        pre->next = p->next;
        free(p);
        // printf("OK\n");
    }
}

// 销毁整个链表
void DestoryList(LinkList *L)
{
    assert(L != NULL);

    LinkList p = (*L)->next;
    LinkList tmp = p;
    while (p != NULL)
    {
        p = p->next;
        free(tmp);
        tmp = p;
    }
    (*L)->next = NULL;
}