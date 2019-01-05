//
// Created by hanoi_ahoj on 2019/1/2.
//

#include <stdio.h>
#include "BinTree.h"

int main()
{
    BinTree T;
    char *pre_order_arr = "abc##de#g##f###";
    CreateBinTreeByKeyBoard(&T);
//    CreateBinTreeByArr(&T, pre_order_arr);

    printf("前序遍历：");
    PreOrderTraverse(T);
    printf("\n");

    printf("中序遍历：");
    InOrderTraverse(T);
    printf("\n");

    printf("后序遍历：");
    PostOrderTraverse(T);
    printf("\n");

    int tree_node_num = 0;
    TreeNodeNum(T, &tree_node_num);
    printf("tree_node_num:%d\n", tree_node_num);
    printf("tree_node_num:%d\n", TreeNodeNum2(T));

    int leaf_num = 0;
    TreeLeafNum1(T, &leaf_num);
    printf("leaf num1:%d\n", leaf_num);
    printf("leaf num2:%d\n", TreeLeafNum2(T));

    printf("level %d node num:%d\n", 3, LevelKNodeNum(T, 3));
    printf("level %d node num:%d\n", 3, LevelKNodeNum(T, 7));

    printf("find %c\n", TreeFindX(T, 'f')->val);

    printf("层序遍历：\n");
    LevelOrderTraversal(T);
    printf("\n");

    printf("IsCompleteTree : %d\n", IsCompleteTree(T));

    return 0;
}