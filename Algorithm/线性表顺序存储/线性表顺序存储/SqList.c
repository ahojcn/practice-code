
#include "SqList.h"

// 初始化操作，建立一个空的线性表L
Status InitList(SqList* L)
{
    assert(L != NULL);
    L->length = 0;
    return OK;
}

// 若线性表L为空，返回TRUE，否则返回FALSE
Status ListEmpty(SqList L)
{
    return (L.length == 0 ? TRUE : FALSE);
}

// 将线性表清空
Status ClearList(SqList* L)
{
    assert(L != NULL);
    L->length = 0;
    return OK;
}

// 将线性表 L 中的第 i 个位置的元素值返回给 e
Status GetElem(SqList L, int i, ElemType* e)
{
    assert(e != NULL);
    if(i<0 || i>L.length)
    {
        return ERROR;
    }
    else
    {
        *e = L.data[i-1];
        return OK;
    }
}

// 在线性表L中查找与e相等的元素
// 如果存在，返回这个元素的下标，否则返回-1
int LocateElem(SqList L, ElemType e)
{
    int ret = -1;
    for(int i=0; i<L.length; i++)
    {
        if(L.data[i] == e)
        {
            ret = i+1;
            break;
        }
    }
    return ret;
}

// 在线性表L的第i个位置插入元素e
Status ListInsert(SqList* L, int i, ElemType e)
{
    assert(L != NULL);
    if(i<0 || i>L->length || L->length == MAXSIZE)
    {
        return ERROR;
    }
    else
    {
        // mov
        int j = 0;
        for(j=L->length+1; j>=i; j--)
        {
            L->data[j] = L->data[j-1];
        }
        // insert
        L->data[i] = e;
        L->length++;
        return OK;
    }
}

// 删除线性表L中第i个位置上的元素，通过e返回
Status ListDelete(SqList* L, int i, ElemType* e)
{
    assert(L != NULL);
    assert(e != NULL);
    if(i<0 || i>L->length || L->length == MAXSIZE)
    {
        return ERROR;
    }
    else
    {
        *e = L->data[i];
        // mov to cover
        for(int j=i; j<=L->length; j++)
        {
            L->data[j] = L->data[j+1];
        }
        L->length--;
        return OK;
    }
}

int ListLength(SqList L)
{
    return L.length;
}

void ListShow(SqList L)
{
    for(int i=0; i<L.length; i++)
    {
        printf("%d,", L.data[i]);
    }
    printf("\n");
}
