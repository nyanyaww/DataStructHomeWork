#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 20
#define TElemType char
//孩子表示法
typedef struct CSNode
{
    char data;
    struct CSNode *next, *nextBrother;
} CSNode, CSTree;

//孩子表示法存储普通树
void createTree(CSTree *t)
{
    // 初始化根节点
    // t = (CSTree *)malloc(sizeof(t));
    t->data = 'R';

    t->next = (CSTree *)malloc(sizeof(t->next));
    t->next->data = 'A';

    t->next->next = (CSTree *)malloc(sizeof(t));
    t->next->next->data = 'B';

    t->next->nextBrother = (CSTree *)malloc(sizeof(t));
    t->next->nextBrother->data = 'C';
}

void findChild(CSTree *t, char data)
{
    CSNode *temp = t;
    while (temp != NULL)
    {
        if (t->data != data)
        {
            temp = temp->next;
        }
    }
    return;
}

int main()
{
    CSTree *t = (CSTree *)malloc(sizeof(t));
    createTree(t);
    PreOrderTraverse(t);
}