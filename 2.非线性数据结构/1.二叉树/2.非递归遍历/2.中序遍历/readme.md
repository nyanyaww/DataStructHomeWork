# 二叉树的非递归中序遍历

```shell
gcc main.c -o main
./main
中序遍历:
4 2 5 1 6 3 7
rm main
```

具体的代码

```c
//中序非递归
void inOrderNonRec(BiTNode *T)
{
    BiTNode *p = T;
    BiTNode *S[20];
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
            p = S[top--];
            printf("%d ", p->data);
            p = p->rchild;
        }
    }
}
```

思想

```word
1. 根节点入栈
2. 判断栈顶是否有左孩子
  (a) 有   -> 入栈
  (b) 没有 -> 出栈（同时输出），判断当前节点有没有右孩子
    i. 有 -> 入栈，跳到步骤2
    ii. 没有，跳到步骤2（b）
```