#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct Node
{
    char data;       // 数据的类型
    int parentIndex; // 父节点的下标
} Node;

typedef struct Tree
{
    Node allNode[MAX_SIZE];
    int nodeNumbers; // 节点的数量
} Tree;

void createTree(Tree *t)
{
    t->allNode[t->nodeNumbers].data = 'R';
    t->allNode[t->nodeNumbers++].parentIndex = -1;

    t->allNode[t->nodeNumbers].data = 'A';
    t->allNode[t->nodeNumbers++].parentIndex = 0;

    t->allNode[t->nodeNumbers].data = 'B';
    t->allNode[t->nodeNumbers++].parentIndex = 0;

    t->allNode[t->nodeNumbers].data = 'C';
    t->allNode[t->nodeNumbers++].parentIndex = 0;

    t->allNode[t->nodeNumbers].data = 'D';
    t->allNode[t->nodeNumbers++].parentIndex = 1;

    t->allNode[t->nodeNumbers].data = 'E';
    t->allNode[t->nodeNumbers++].parentIndex = 1;

    t->allNode[t->nodeNumbers].data = 'F';
    t->allNode[t->nodeNumbers++].parentIndex = 3;

    t->allNode[t->nodeNumbers].data = 'G';
    t->allNode[t->nodeNumbers++].parentIndex = 6;
}

void findParent(Tree *t, char data)
{
    int i = 0;
    int parentIndex = -1;
    for (; i < t->nodeNumbers; i++)
    {
        if (data == t->allNode[i].data)
        {
            parentIndex = t->allNode[i].parentIndex;
            if (parentIndex != -1)
            {
                printf("%c的父节点是%c，父节点的下标为%d\n", data,
                       t->allNode[parentIndex].data, parentIndex);
            }
            else
            {
                printf("%c是根节点，没有父节点\n", data);
            }
            return;
        }
    }
    printf("这棵树没有节点%c\n", data);
}

int main()
{
    Tree *t = (Tree *)malloc(sizeof(Tree));
    createTree(t);
    findParent(t, 'R');
    findParent(t, 'A');
    findParent(t, 'B');
    findParent(t, 'C');
    findParent(t, 'D');
    findParent(t, 'E');
    findParent(t, 'F');
    findParent(t, 'M');
}