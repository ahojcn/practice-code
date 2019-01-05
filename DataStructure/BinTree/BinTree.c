//
// Created by hanoi_ahoj on 2019/1/2.
//

#include "BinTree.h"
#include <stdio.h>
#include <stdlib.h>


Status IsFull (const SqQueue *q) {
    return ((q->rear + 1) % MAXSIZE) == q->front ? FULL : NOTFULL;
}

Status IsEmpty(const SqQueue *q){
    return q->front == q->rear ? EMPTY : NOTEMPTY;
}

Status InitQueue(SqQueue *q){
    q->front = 0;
    q->rear = 0;
    return OK;
}

int QueueLength(const SqQueue *q){
    return (q->rear-q->front+MAXSIZE) % MAXSIZE;
}

Status EnQueue(SqQueue *q, const QElemType e){
    if (IsFull(q) == FULL){
        return ERROR;
    }
    else{
        q->data[q->rear] = e;
        q->rear = (q->rear + 1) % MAXSIZE;
        return OK;
    }
}

Status DeQueue(SqQueue *q, QElemType *e){
    if (IsEmpty(q) == EMPTY){
        return ERROR;
    }
    else{
        *e = q->data[q->front];
        q->front = (q->front + 1) % MAXSIZE;
        return OK;
    }
}

void CreateBinTreeByKeyBoard (BinTree *root)
{
    BinTreeElemType ch;
    scanf("%c", &ch);
    if (ch == '#')
    {
        *root = NULL;
    }
    else
    {
        *root = (BinTree) malloc(sizeof(BinTreeNode));
        if (!*root)
        {
            printf("OVERFLOW\n");
            exit(1001);
        }
        (*root)->val = ch;
        CreateBinTreeByKeyBoard(&(*root)->lchild);
        CreateBinTreeByKeyBoard(&(*root)->rchild);
    }
}

//void CreateBinTreeByArr(BinTree *root, BinTreeElemType *pre_order_arr)
//{
//    if (*pre_order_arr == '#')
//    {
//        *root = NULL;
//    }
//    else
//    {
//        *root = (BinTree) malloc(sizeof(BinTreeNode));
//        if (!*root)
//        {
//            printf("OVERFLOW\n");
//            exit(1001);
//        }
//        (*root)->val = *pre_order_arr;
//        CreateBinTreeByArr(&(*root)->lchild, pre_order_arr + 1);
//        CreateBinTreeByArr(&(*root)->rchild, pre_order_arr + 1);
//    }
//}

void PreOrderTraverse(BinTree root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%c", root->val);
    PreOrderTraverse(root->lchild);
    PreOrderTraverse(root->rchild);
}

//BinTree CreateTreeFromArr(BinTreeElemType *pre_order_arr, int size, int *used)
//{
//    if (size == 0)
//    {
//        BinTree root = NULL;
//        (*used) += 0;
//        return root;
//    }
//
//    char root_val = pre_order_arr[0];
//    if (root_val == '#')
//    {
//        BinTree root = NULL;
//        (*used) += 1;
//        return root;
//    }
//
//    // 根
//    BinTree root = (BinTree) malloc(sizeof(BinTreeNode));
//    root->val = root_val;
//    root->lchild = root->rchild = NULL;
//    (*used) += 1;
//
//    BinTree left_child = CreateTreeFromArr(pre_order_arr + 1, size - 1, used);
//    BinTree right_child = CreateTreeFromArr(pre_order_arr + 1 + (*used), size - 1 - (*used), used);
//
//    root->lchild = left_child;
//    root->rchild = right_child;
//    (*used) += 1;
//    return root;
//}

void InOrderTraverse(BinTree root)
{
    if (root == NULL)
    {
        return;
    }
    InOrderTraverse(root->lchild);
    printf("%c", root->val);
    InOrderTraverse(root->rchild);
}

void PostOrderTraverse(BinTree root)
{
    if (root == NULL)
    {
        return;
    }
    InOrderTraverse(root->lchild);
    InOrderTraverse(root->rchild);
    printf("%c", root->val);
}

void TreeNodeNum(BinTree root, int *num)
{
    if (root == NULL)
    {
        return;
    }

    (*num)++;
    TreeNodeNum(root->lchild, num);
    TreeNodeNum(root->rchild, num);
}

int TreeNodeNum2(BinTree root)
{
    if (root == NULL)
        return 0;

    return TreeNodeNum2(root->lchild) + TreeNodeNum2(root->rchild) + 1;
}

void TreeLeafNum1 (BinTree root, int *leaf_num)
{
    if (root == NULL)
        return;

    if (root->lchild == NULL && root->rchild == NULL)
    {
        (*leaf_num) ++;
        return;
    }

    TreeLeafNum1(root->lchild, leaf_num);
    TreeLeafNum1(root->rchild, leaf_num);
}

int TreeLeafNum2 (BinTree root)
{
    if (root == NULL)
        return 0;

    if (root->rchild == NULL && root->lchild == NULL)
        return 1;

    return TreeLeafNum2(root->lchild) + TreeLeafNum2(root->rchild);
}

int LevelKNodeNum (BinTree root, int k)
{
    if (root == NULL)
        return 0;

    if (k == 1)
        return 1;

    return LevelKNodeNum(root->lchild, k-1) + LevelKNodeNum(root->rchild, k-1);
}

BinTree TreeFindX (BinTree root, BinTreeElemType x)
{
    if (root == NULL)
        return NULL;

    if (root->val == x)
        return root;

    BinTree ret = TreeFindX(root->lchild, x);
    if (ret != NULL)
        return ret;

    return TreeFindX(root->rchild, x);
}

void LevelOrderTraversal (BinTree root)
{
    if (root == NULL)
        return;

    SqQueue qu;
    InitQueue(&qu);
    EnQueue(&qu, root);
    while (!IsEmpty(&qu))
    {
        BinTree e = NULL;
        DeQueue(&qu, &e);
        printf("%c ", e->val);

        if (e->lchild != NULL)
        {
            EnQueue(&qu, e->lchild);
        }
        if (e->rchild != NULL)
        {
            EnQueue(&qu, e->rchild);
        }
    }
}

bool IsCompleteTree (BinTree root)
{
    if (root == NULL)
        return true;

    SqQueue qu;
    InitQueue(&qu);
    EnQueue(&qu, root);
    while (1)
    {
        BinTree e = NULL;
        DeQueue(&qu, &e);
        if (e == NULL)
        {
            break;
        }

        EnQueue(&qu, e->lchild);
        EnQueue(&qu, e->rchild);
    }

    // 检查队列中是否还有非空节点
    while (!IsEmpty(&qu))
    {
        BinTree e = NULL;
        DeQueue(&qu,&e);
        if (e == NULL)
        {
            return false;
        }
    }
    return true;
}


