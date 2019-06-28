#include <stdio.h>
#include <malloc.h>

typedef struct list
{
    int data;
    struct list *next;
} list;

void init(list **p)
{
    *p = (list *)malloc(sizeof(list));
    (*p)->next = NULL;
}


void insert(list **p, int data)
{
    list *new = (list *)malloc(sizeof(list));
    new->data = data;
    new->next = NULL;

    list *cur = *p;
    while (cur->next)
        cur = cur->next;
    cur->next = new;
}


void traverse(list *p)
{
    list *temp = p->next;
    while(temp)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
}


int main()
{
    list *testList = NULL;
    init(&testList);
    for (int i = 0; i < 100; i++)
    {
        insert(&testList, i);
    }
    traverse(testList);
    return 0;
}