#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define TElemType int
int top = -1; //top变量时刻表示栈顶元素所在位置
//构造结点的结构体
typedef struct BiTNode
{
    TElemType data;                  //数据域
    struct BiTNode *lchild, *rchild; //左右孩子指针
} BiTNode, *BiTree;
//初始化树的函数
void CreateBiTree(BiTree *T)
{
    *T = (BiTNode *)malloc(sizeof(BiTNode));
    (*T)->data = 1;
    (*T)->lchild = (BiTNode *)malloc(sizeof(BiTNode));
    (*T)->rchild = (BiTNode *)malloc(sizeof(BiTNode));
    (*T)->lchild->data = 2;
    (*T)->lchild->lchild = (BiTNode *)malloc(sizeof(BiTNode));
    (*T)->lchild->rchild = (BiTNode *)malloc(sizeof(BiTNode));
    (*T)->lchild->rchild->data = 5;
    (*T)->lchild->rchild->lchild = NULL;
    (*T)->lchild->rchild->rchild = NULL;
    (*T)->rchild->data = 3;
    (*T)->rchild->lchild = (BiTNode *)malloc(sizeof(BiTNode));
    (*T)->rchild->lchild->data = 6;
    (*T)->rchild->lchild->lchild = NULL;
    (*T)->rchild->lchild->rchild = NULL;
    (*T)->rchild->rchild = (BiTNode *)malloc(sizeof(BiTNode));
    (*T)->rchild->rchild->data = 7;
    (*T)->rchild->rchild->lchild = NULL;
    (*T)->rchild->rchild->rchild = NULL;
    (*T)->lchild->lchild->data = 4;
    (*T)->lchild->lchild->lchild = NULL;
    (*T)->lchild->lchild->rchild = NULL;
}
//前序遍历使用的进栈函数
void push(BiTNode **a, BiTNode *elem)
{
    a[++top] = elem;
}
//弹栈函数
void pop()
{
    if (top == -1)
    {
        return;
    }
    top--;
}
//模拟操作结点元素的函数，输出结点本身的数值
void displayElem(BiTNode *elem)
{
    printf("%d ", elem->data);
}
//拿到栈顶元素
BiTNode *getTop(BiTNode **a)
{
    return a[top];
}

//后序非递归
void postOrderNonRec(BiTNode *T)
{
    BiTNode *p = T;
    BiTNode *S[20];
    BiTNode *r = NULL;
    int top = -1;
    while (p || top != -1)
    {
        if (p)
        {
            S[++top] = p;
            p = p->lchild;
        }
        else
        {
            p = S[top];
            if (p->rchild && p->rchild != r)
            {
                p = p->rchild;
                S[++top] = p;
                p = p->lchild;
            }
            else
            {
                p = S[top--];
                printf("%d ", p->data);
                r = p;
                p = NULL;
            }
        }
    }
}
int main()
{
    BiTree Tree;
    CreateBiTree(&Tree);
    printf("后序遍历: \n");
    postOrderNonRec(Tree);
    printf("\n");
}