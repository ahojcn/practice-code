//
// Created by hanoi_ahoj on 2019/1/2.
//

#ifndef BINTREE_BINTREE_H
#define BINTREE_BINTREE_H

typedef char BinTreeElemType;

typedef struct BinTreeNode
{
    struct BinTreeNode *lchild;
    struct BinTreeNode *rchild;
    BinTreeElemType val;
} BinTreeNode, *BinTree;

// 利用扩展二叉树建立一个二叉树
void CreateBinTree(BinTree *root);

// 前序遍历二叉树
void PreOrderTraverse(BinTree root);

// 中序遍历二叉树
void InOrderTraverse(BinTree root);

// 后序遍历二叉树
void PostOrderTraverse(BinTree root);

#endif //BINTREE_BINTREE_H
