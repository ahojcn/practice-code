//
// Created by hanoi_ahoj on 2019/1/2.
//

#include <stdio.h>
#include "BinTree.h"

int main()
{
    BinTree T;
    CreateBinTree(&T);
    printf("前序遍历：");
    PreOrderTraverse(T);
    printf("\n");

    printf("中序遍历：");
    InOrderTraverse(T);
    printf("\n");

    printf("后序遍历：");
    PostOrderTraverse(T);
    printf("\n");

    return 0;
}