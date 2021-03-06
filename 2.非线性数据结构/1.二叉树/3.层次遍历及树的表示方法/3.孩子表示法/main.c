#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 20
#define TElemType char

typedef struct CTNode
{
    int child; //链表中每个结点存储的不是数据本身，而是数据在数组中存储的位置下标
    struct CTNode *next;
} ChildPtr;

typedef struct
{
    TElemType data; //结点的数据类型
    ChildPtr *head; //孩子链表的头指针
} CTBox;

typedef struct
{
    CTBox nodes[MAX_SIZE]; //存储结点的数组
    int n, r;              //结点数量和树根的位置
} CTree;

//孩子表示法存储普通树
CTree initTree(CTree tree)
{
   
    tree.nodes[0].data = 'R';
    tree.nodes[0].head = (ChildPtr *)malloc(sizeof(ChildPtr));
    tree.nodes[0].head->next = NULL;

    ChildPtr *p = tree.nodes[0].head;
    for (int j = 0; j < 3; j++)
    {
        ChildPtr *newEle = (ChildPtr *)malloc(sizeof(ChildPtr));
        newEle->next = NULL;
        newEle->child = j + 1;
        p->next = newEle;
        p = p->next;
    }

    tree.nodes[1].data = 'A';
    tree.nodes[1].head = (ChildPtr *)malloc(sizeof(ChildPtr));
    tree.nodes[1].head->next = NULL;

    tree.nodes[2].data = 'B';
    tree.nodes[2].head = (ChildPtr *)malloc(sizeof(ChildPtr));
    tree.nodes[2].head->next = NULL;

    tree.nodes[3].data = 'C';
    tree.nodes[3].head = (ChildPtr *)malloc(sizeof(ChildPtr));
    tree.nodes[3].head->next = NULL;

    tree.n = 4;

    return tree;
}

void findKids(CTree tree, char a)
{
    int hasKids = 0;
    for (int i = 0; i < tree.n; i++)
    {
        if (tree.nodes[i].data == a)
        {
            ChildPtr *p = tree.nodes[i].head->next;
            while (p)
            {
                hasKids = 1;
                printf("%c ", tree.nodes[p->child].data);
                p = p->next;
            }
            break;
        }
    }
    if (hasKids == 0)
    {
        printf("此节点为叶子节点");
    }
}

int main()
{
    CTree tree;
    tree = initTree(tree);
    printf("找出节点 R 的所有孩子节点：");
    findKids(tree, 'R');
    printf("\n");
    return 0;
}