// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>

// #define TElemType int
// //构造结点的结构体
// typedef struct BiTNode
// {
//     TElemType data;                  //数据域
//     struct BiTNode *lchild, *rchild; //左右孩子指针
// } BiTNode, *BiTree;                  //BiTee = BiTNode *
// //初始化树的函数
// void CreateBiTree(BiTree *T)
// {
//     //BiTNode ** T
//     *T = (BiTNode *)malloc(sizeof(BiTNode));
//     (*T)->data = 1;
//     (*T)->lchild = (BiTNode *)malloc(sizeof(BiTNode));
//     (*T)->rchild = (BiTNode *)malloc(sizeof(BiTNode));

//     (*T)->lchild->data = 2;
//     (*T)->lchild->lchild = (BiTNode *)malloc(sizeof(BiTNode));
//     (*T)->lchild->rchild = (BiTNode *)malloc(sizeof(BiTNode));
//     (*T)->lchild->rchild->data = 5;
//     (*T)->lchild->rchild->lchild = NULL;
//     (*T)->lchild->rchild->rchild = NULL;
//     (*T)->rchild->data = 3;
//     (*T)->rchild->lchild = (BiTNode *)malloc(sizeof(BiTNode));
//     (*T)->rchild->lchild->data = 6;
//     (*T)->rchild->lchild->lchild = NULL;
//     (*T)->rchild->lchild->rchild = NULL;
//     (*T)->rchild->rchild = (BiTNode *)malloc(sizeof(BiTNode));
//     (*T)->rchild->rchild->data = 7;
//     (*T)->rchild->rchild->lchild = NULL;
//     (*T)->rchild->rchild->rchild = NULL;
//     (*T)->lchild->lchild->data = 4;
//     (*T)->lchild->lchild->lchild = NULL;
//     (*T)->lchild->lchild->rchild = NULL;
// }
// void preOrderTravse(BiTree T)
// {
//     ;
// }
// int main()
// {
//     BiTree Tree;         //新建跟节点
//     CreateBiTree(&Tree); //创建二叉树，传地址，可以直接改变Tree的内容

//     printf("先序遍历: \n");
//     preOrderTraverse(Tree);
//     printf("\n");
// }
