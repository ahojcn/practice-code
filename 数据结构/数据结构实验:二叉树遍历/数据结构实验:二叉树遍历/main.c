//    二叉树的实现（C语言）
//    链表，递归实现
//    编译环境：visual studio 2017
//    操作系统：win8.1

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef char Elementtype;    //    定义数据类型，可根据需要自行定制
typedef struct TreeNode * Node;    //    Node相当于struct treeNode *
//    定义数节点结构
typedef struct TreeNode {
    Elementtype Element;
    Node left;    //    树节点的左子节点
    Node right;    //    树节点的右子节点
}TREE,*PTREE;

//    函数声明
void CreatTree(PTREE *);    //    树的先序创建函数
void PreOrderTree(PTREE );    //    树的前序遍历函数
void InOrderTree(PTREE );    //    树的中序遍历
void PostOrderTree(PTREE );    //    树的后序遍历
void LeafOfTree(PTREE );    //    打印树的叶子节点函数
int  Get_Leaf_Num(PTREE );    //    获取树叶子节点个数
int Get_Height(PTREE );    //    获取树的高度


//    主函数
int main() {
    
    PTREE Root;
    printf("请先序输入二叉树的节点数据： ");
    CreatTree(&Root);
    printf("\n前序遍历结果为：");
    PreOrderTree(Root);
    printf("\n中序遍历结果为：");
    InOrderTree(Root);
    printf("\n后序遍历结果为：");
    PostOrderTree(Root);
    printf("\n打印叶子节点为：");
    LeafOfTree(Root);
    printf("\n叶子节点个数为：%d", Get_Leaf_Num(Root));
    printf("\n二叉树的高度为：%d", Get_Height(Root));
    printf("\n");
    
    return 0;
}

//    定义树先序创建函数
void CreatTree(PTREE *Root) {
    char val=0;    //    用于下面存放数据
    val=getchar();    //    输入数据值
    //    如果输入'*'，则指向为空
    if (val == ' ')
        (*Root) = NULL;
    //    如果输入非'*'，则给数据域赋值
    else {
        (*Root) = (PTREE)malloc(sizeof(TREE));    //    申请内存空间
        if ((*Root) == NULL) {
            printf("创建节点失败，无法分配可用内存...");
            exit(-1);
        }
        else {
            (*Root)->Element = val;    //    给节点数据域赋值
            CreatTree(&(*Root)->left);
            CreatTree(&(*Root)->right);
        }
    }
    
}
//    树的前序遍历函数定义
void PreOrderTree(PTREE Root) {
    
    if (Root == NULL)
        return;
    else {
        putchar(Root->Element);
        PreOrderTree(Root->left);
        PreOrderTree(Root->right);
        
    }
}
//    树的中序遍历函数定义
void InOrderTree(PTREE Root) {
    
    if (Root == NULL)
        return;
    else {
        InOrderTree(Root->left);
        putchar(Root->Element);
        InOrderTree(Root->right);
        
    }
}

//    树的后序遍历函数定义
void PostOrderTree(PTREE Root) {
    
    if (Root==NULL)
        return ;
    else{
        PostOrderTree(Root->left);
        PostOrderTree(Root->right);
        putchar( Root->Element);
    }
}



//    打印树的叶子节点函数定义
void LeafOfTree(PTREE Tree) {
    if (Tree == NULL)
        return ;
    
    else {
        if (Tree->left == NULL&&Tree->right == NULL)
            putchar(Tree->Element);
        else {
            LeafOfTree(Tree->left);
            LeafOfTree(Tree->right);
        }
    }
    
}

//    获取树的叶子节点个数函数定义
int Get_Leaf_Num(PTREE Tree) {
    if (Tree == NULL)
        return 0;
    if (Tree->left == NULL&&Tree->right == NULL)
        return 1;
    //递归整个树的叶子节点个数 = 左子树叶子节点的个数 + 右子树叶子节点的个数
    return Get_Leaf_Num(Tree->left) + Get_Leaf_Num(Tree->right);
}
//    获取树高的函数定义
int Get_Height(PTREE Tree) {
    int Height = 0;
    if (Tree == NULL)
        return 0;
    
    //树的高度 = max(左子树的高度，右子树的高度) + 1
    else
    {
        int L_Height = Get_Height(Tree->left);
        int R_Height = Get_Height(Tree->right);
        Height = L_Height >= R_Height ? L_Height + 1 : R_Height + 1;
    }
    return Height;
}
