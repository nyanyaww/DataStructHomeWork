#include <stdio.h>
#include <stdlib.h>

typedef struct CSTree
{
    char data;
    struct CSTree *firstChild, *nextBrother;
} CSTree;

void createTree(CSTree *t)
{
    // 初始化根节点
    // t = (CSTree *)malloc(sizeof(t));
    t->data = 'R';
    t->firstChild = NULL;

    t->firstChild = (CSTree *)malloc(sizeof(CSTree));
    t->firstChild->data = 'A';
    t->firstChild->firstChild = NULL;

    t->firstChild->nextBrother = (CSTree *)malloc(sizeof(CSTree));
    t->firstChild->nextBrother->data = 'B';

    t->firstChild->nextBrother->nextBrother = (CSTree *)malloc(sizeof(CSTree));
    t->firstChild->nextBrother->nextBrother->data = 'C';
}

void findNode(CSTree *p, char data)
{
    if (p == NULL)
    {
        return;
    }
    if (p->data == data)
    {
        if (p->firstChild != NULL)
        {
            printf("%c的孩子节点为%c ", p->data, p->firstChild->data);
            CSTree *temp = p->firstChild->nextBrother;
            while (temp)
            {
                printf("%c ", temp->data);
                temp = temp->nextBrother;
            }
        }
        else
        {
            printf("%c没有孩子节点", data);
        }
        printf("\n");
        if (p->nextBrother != NULL)
        {
            printf("%c的兄弟节点为", data);
            CSTree *temp = p->nextBrother;
            while (temp)
            {
                printf("%c ", temp->data);
                temp = temp->nextBrother;
            }
        }
        else
        {
            printf("%c没有兄弟节点", data);
        }
        printf("\n");
    }
    findNode(p->firstChild, data);
    findNode(p->nextBrother, data);
}

int main()
{
    CSTree *t = (CSTree *)malloc(sizeof(t));
    createTree(t);
    findNode(t, 'R');
    findNode(t, 'A');
}