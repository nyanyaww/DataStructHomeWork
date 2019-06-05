#include <stdio.h>
#include <stdlib.h>
#define TElemType int

//初始化队头和队尾指针开始时都为0
int front = 0, rear = 0;

typedef struct BiTNode
{
    TElemType data;                  //数据域
    struct BiTNode *lchild, *rchild; //左右孩子指针
} BiTNode, *BiTree;

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

    // (*T)->rchild->rchild->rchild = (BiTNode *)malloc(sizeof(BiTNode));
    // (*T)->rchild->rchild->rchild->data = 8;
    // (*T)->rchild->rchild->rchild->lchild = NULL;
    // (*T)->rchild->rchild->rchild->rchild = NULL;
}
//入队函数
void EnQueue(BiTree *a, BiTree node)
{
    a[rear++] = node;
}
//出队函数
BiTNode *DeQueue(BiTNode **a)
{
    return a[front++];
}
//输出函数
void displayNode(BiTree node)
{
    printf("%d ", node->data);
}

void SeqTraverse(BiTree *tree)
{
    int height = 0, len;
    BiTNode *p;
    BiTree a[20];
    EnQueue(a, tree);
    while (front < rear)
    {
        height++;
        len = rear - front;
        while (len--)
        {
            //队头结点出队
            p = DeQueue(a);
            // displayNode(p);
            //将队头结点的左右孩子依次入队
            if (p->lchild != NULL)
            {
                EnQueue(a, p->lchild);
            }
            if (p->rchild != NULL)
            {
                EnQueue(a, p->rchild);
            }
        }
    }
    printf("高度：%d\n", height);
}

int main()
{

    BiTree tree;
    CreateBiTree(&tree);
    SeqTraverse(tree);

    return 0;
}