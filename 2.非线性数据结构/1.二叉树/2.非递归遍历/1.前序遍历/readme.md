# 前序非递归遍历

程序的输出

```powershell
PS C:\Users\lcs\Desktop\lcs_github\DataStructHomeWork\2.非线性数据结构\1.二叉树\2.非递归遍历\1.前序遍历> make all2
gcc main_version1.c -o main_v1
main_v1.exe
Active code page: 65001
先序遍历:
1 2 4 5 3 6 7
```

算法的步骤(这个是老师说的代码的实现)

```c
//先序遍历非递归算法
void PreOrderTraverse(BiTree Tree)
{
    BiTNode *a[20]; //定义一个顺序栈
    BiTNode *p;     //临时指针
    push(a, Tree);  //根结点进栈
    while (top != -1)
    {
        p = getTop(a); //取栈顶元素
        pop();         //弹栈
        while (p)
        {
            // 第一次使用的时候输出root的值
            displayElem(p);

            if (p->rchild)
            {
                // 2（1）如果有栈顶有右孩子，就入栈
                push(a, p->rchild);
            }
            // 判断有没有左孩子
            // 2（2）（b）如果没有左孩子的话就跳出这个
            // 此时display会输出右孩子的值
            while
            p = p->lchild;
            // 2（2）（a）有左孩子的话就调用display输出
        }
    }
}
```

程序的步骤(这个是分析时按照的步骤，这个也可以输出正确结果)

```c
//先序非递归
void preOrderNonRec(BiTNode *T)
{
    BiTNode *p = T;
    BiTNode *S[20];
    int top = -1;
    while (p || top != -1)
    {
        while (p)
        {
            // 这里是左孩子一直入栈。没有左孩子就出栈
            printf("%d ", p->data);
            S[++top] = p;
            p = p->lchild;
        }
        // 拿到右孩子。如果右孩子有的话就继续上面那个while
        // 没有的话就出栈
        if (top != -1)
        {
            p = S[top--];
            p = p->rchild;
        }
    }
}
```
