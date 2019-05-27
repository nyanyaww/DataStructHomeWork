# 二叉树的递归遍历

运行结果

```shell
    gcc main.c -o main
    ./main
    先序遍历:
    1 2 4 5 3 6 7
    中序遍历:
    4 2 5 1 6 3 7
    后序遍历:
    4 5 2 6 7 3 1
    rm main
```

算法的核心代码

```c
//先序遍历
void PreOrderTraverse(BiTree T)
{
    //终止条件
    if (T == NULL)
    {
        return;
    }
    //调用自己
    printf("%d ", T->data);       //调用操作结点数据的函数方法
    PreOrderTraverse(T->lchild); //访问该结点的左子树
    PreOrderTraverse(T->rchild); //访问该结点的右子树
}

// 中序遍历
void inOrderTraverse(BiTree T)
{
    //终止条件
    if (T == NULL)
    {
        return;
    }
    //调用自己
    inOrderTraverse(T->lchild); //访问该结点的左子树
    printf("%d ", T->data);    //调用操作结点数据的函数方法

    inOrderTraverse(T->rchild); //访问该结点的右子树
}
// 后序遍历
void postOrderTraverse(BiTree T)
{
    //终止条件
    if (T == NULL)
    {
        return;
    }
    //调用自己
    postOrderTraverse(T->lchild); //访问该结点的左子树
    postOrderTraverse(T->rchild); //访问该结点的右子树
    printf("%d ", T->data);        //调用操作结点数据的函数方法
}
```