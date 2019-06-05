# 作业的简单说明

## 1. 层序遍历

```shell
./main
层序遍历：
1 2 3 4 5 6 7
rm main
```

代码的实现

```c
void SeqTraverse(BiTree *tree)
{
    BiTNode *p;
    BiTree a[20];
    EnQueue(a, tree);
    while (front < rear)
    {
        p = DeQueue(a);
        printf("%d ", node->data);
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
```

## 2. 双亲表示法

程序运行是要找某个节点的父节点

```c
Tree *t = (Tree *)malloc(sizeof(Tree));
createTree(t);
findParent(t, 'R');
findParent(t, 'A');
findParent(t, 'B');
findParent(t, 'C');
findParent(t, 'D');
findParent(t, 'E');
findParent(t, 'F');
```

运行截图

```shell
gcc main.c -o main
./main
R是根节点，没有父节点
A的父节点是R，父节点的下标为0
B的父节点是R，父节点的下标为0
C的父节点是R，父节点的下标为0
D的父节点是A，父节点的下标为1
E的父节点是A，父节点的下标为1
F的父节点是C，父节点的下标为3
rm main
```

数据结构的实现

```c
typedef struct Node
{
    char data;       // 数据
    int parentIndex; // 父节点的下标
} Node;

typedef struct Tree
{
    Node allNode[MAX_SIZE];
    int nodeNumbers; // 节点的数量
} Tree;
```

寻找父节点的时候就找data对应的下标，而在Node结构体里面定义了一个节点需要保存数据以及父节点的下标，所以不难。这种保存方法是基于数组的。

## 3. 孩子表示法

```shell
gcc main.c -o main
./main
找出节点 R 的所有孩子节点：A B C
rm main
```

这个程序其实我不是百分百明白，基本实现是明白的，但是写代码时候有点模糊，是看网上实现然后慢慢写的。所以就不写关键代码了。

## 4. 孩子兄弟表示法

```shell
./main
R的孩子节点为A B C
R没有兄弟节点
A没有孩子节点
A的兄弟节点为B C
```

数据结构的实现非常简单，一个节点会有0或者1个指向孩子节点的指针，会有任意数量的指向兄弟节点的指针。

如果需要找到某个节点的所有的孩子节点，只需要找到该节点的那个指向孩子节点的指针，然后再找这个孩子节点的所有的兄弟节点就可以了。兄弟节点就不赘述了。

```c
typedef struct CSTree
{
    char data;
    struct CSTree *firstChild, *nextBrother;
} CSTree;
```

这个寻找孩子节点和兄弟节点的函数我是用了递归的方法。递归的目的是遍历找到节点的位置。终止条件是该节点为NULL。假定我们需要寻找某个节点，先递归遍历出该节点的位置，之后的处理就如上文所述。

```c
void findNode(CSTree *p, char data)
{
    if (p == NULL)
    {
        return;
    }
    if (p->data == data)
    {
        // 找到该节点后
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
```

## 5. 树的深度

程序的输出

```shell
./main
高度：3
rm main
```

其实是在层序遍历的基础上面修改的，思路是层序遍历是利用队列实现的。

而我发现当前队列的长度就等于当前层的节点数，那么我们记录一下每一层的队列的长度`len`，当出队的次数等于我们记录的长度`len`的时候说明这一层就已经遍历完了，也就意味着我们的层数`height`需要+1了。

而队列的长度`len`就是`rear - front`。

```c
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
```
