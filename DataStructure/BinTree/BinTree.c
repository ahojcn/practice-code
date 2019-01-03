//
// Created by hanoi_ahoj on 2019/1/2.
//

#include "BinTree.h"
#include <stdio.h>
#include <stdlib.h>

void CreateBinTree(BinTree *root)
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
        CreateBinTree(&(*root)->lchild);
        CreateBinTree(&(*root)->rchild);
    }
}

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
