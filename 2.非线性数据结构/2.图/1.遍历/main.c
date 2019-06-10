#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define MAX_VERTAX_SIZE 20

typedef char VerElemType;
typedef char ElemType;

typedef struct Graph
{
    VerElemType VertaxMatrix[MAX_VERTAX_SIZE];
    int AdjacentMatrix[MAX_VERTAX_SIZE][MAX_VERTAX_SIZE];
    int VertaxNum;
    int EageNum;
} Graph;

//队列，在图的广度优先遍历中使用
typedef struct QueueNode
{
    ElemType data;
    struct QueueNode *next;
} QueueNode, *QueueNodePtr;
typedef struct Queue
{
    QueueNodePtr front;
    QueueNodePtr rear;
} Queue;

void menu()
{
    printf("********************\n");
    printf("***1.深度优先遍历***\n");
    printf("***2.广度优先遍历***\n");
    printf("*****0.退出程序*****\n");
    printf("********************\n");
}

int InitQueue(Queue *q) //初始化队列
{
    (*q).front = (QueueNodePtr)malloc(sizeof(struct QueueNode));
    (*q).rear = (*q).front;
    (*q).rear->next = NULL;
    return OK;
}
int EnterQueue(Queue *q, ElemType e) //进队
{
    QueueNodePtr n;
    n = (QueueNode *)malloc(sizeof(struct QueueNode));
    n->data = e;
    n->next = q->rear->next;
    q->rear->next = n;
    q->rear = n;
    return OK;
}
int DeleteQueue(Queue *q, ElemType *e) //出队
{
    QueueNodePtr p;
    if (q->front == q->rear)
    {
        printf("Empty\n");
        return ERROR;
    }
    p = q->front->next;
    *e = p->data;
    q->front->next = p->next;
    free(p);
    if (p == q->rear)
        q->rear = q->front;
    return OK;
}

int IsQueueEmpty(Queue q) //判断队列是否为空
{
    return q.front == q.rear ? OK : ERROR;
}

//定位某个顶点的下标
int LocateVertax(Graph G, VerElemType ver)
{
    int i;
    for (i = 0; i < G.VertaxNum; i++)
    {
        if (G.VertaxMatrix[i] == ver)
            return i;
    }
    return -1;
}

int CreateUndigraph(Graph *G) //创建无向图
{
    int i, j, k;
    VerElemType x, y;
    printf("创建图\n");
    printf("请输入顶点和弧的数目: ");
    scanf("%d %d%*c", &(*G).VertaxNum, &(G->EageNum));

    printf("请输入顶点元素的值：");
    for (i = 0; i < G->VertaxNum; i++)
    {
        scanf("%c%*c", &(G->VertaxMatrix[i]));
    }

    for (i = 0; i < G->VertaxNum; i++)

        for (j = 0; j < G->VertaxNum; j++)
            G->AdjacentMatrix[i][j] = 0;
    printf("请输入有关联边的两点: ");
    for (k = 0; k < G->EageNum; k++)
    {

        scanf("%c %c%*c", &x, &y);
        i = LocateVertax(*G, x);
        j = LocateVertax(*G, y);
        G->AdjacentMatrix[i][j] = G->AdjacentMatrix[j][i] = 1;
    }
    return OK;
}

//图的深度优先遍历
//返回v的第一个邻接顶点，若没有邻接顶点，返回-1
int FirstAdjacentVertax(Graph G, VerElemType v)
{
    int index_v = LocateVertax(G, v);
    int i;
    for (i = 0; i < G.VertaxNum; i++)
    {
        if (G.AdjacentMatrix[index_v][i] == 1)
            return i;
    }
    return -1;
}
//w是v的邻接点，返回v的除了w(从w开始)的下一个邻接顶点，没有则返回-1
int NextAdjacentVertax(Graph G, VerElemType v, VerElemType w)
{
    int index_v = LocateVertax(G, v);
    int index_w = LocateVertax(G, w);
    int i;
    for (i = index_w + 1; i < G.VertaxNum; i++)
    {
        if (G.AdjacentMatrix[index_v][i] == 1)
            return i;
    }
    return -1;
}
//			从v的第一邻接点开始深度优先遍历，
//			然后从v的第二邻接开始深度优先遍历。直到没有邻接点

int visitedArray[MAX_VERTAX_SIZE];
void visit(VerElemType c)
{
    printf("%c ", c);
}
VerElemType GetVertaxValue(Graph G, int position)
{
    return G.VertaxMatrix[position];
}
int DFS(Graph G, VerElemType v)
{ //Depth First Search
    VerElemType w;
    visit(v);
    visitedArray[LocateVertax(G, v)] = 1;

    for (w = GetVertaxValue(G, FirstAdjacentVertax(G, v));
         LocateVertax(G, w) != -1; w = GetVertaxValue(G, NextAdjacentVertax(G, v, w)))
    {
        if (visitedArray[LocateVertax(G, w)] != 1)
            DFS(G, w);
    }
    return OK;
}
int DFSTraverse(Graph G)
{
    int i;
    for (i = 0; i < G.VertaxNum; i++)
    {
        visitedArray[i] = 0;
    }
    for (i = 0; i < G.VertaxNum; i++)
    {
        if (visitedArray[i] == 0)
        {
            DFS(G, GetVertaxValue(G, i));
        }
    }
    return OK;
}
//将第一个顶点入队，将对中的元素出队，如果没有访问过，则调用visit访问，将其所有的邻接顶点入队
int BFSTraverse(Graph G)
{
    ElemType c;
    Queue q;
    InitQueue(&q);
    int i, j;
    for (i = 0; i < G.VertaxNum; i++)
        visitedArray[i] = 0;

    for (i = 0; i < G.VertaxNum; i++)
    {
        if (visitedArray[i] == 0)
        {
            EnterQueue(&q, G.VertaxMatrix[i]);
            visitedArray[i] = 1;
            while (IsQueueEmpty(q) != OK)
            {
                DeleteQueue(&q, &c); //进到队里的都是编辑为访问过，这样队里不会有重复的点进来
                visit(c);
                for (j = FirstAdjacentVertax(G, c); j != -1; j = NextAdjacentVertax(G, c, GetVertaxValue(G, j)))
                {
                    if (visitedArray[j] == 0)
                    {
                        EnterQueue(&q, GetVertaxValue(G, j));
                        visitedArray[j] = 1; //进到队里的都是编辑为访问过，这样队里不会有重复的点进来
                    }
                }
            }
        }
    }

    return 0;
}

int main()
{
    Graph G;
    CreateUndigraph(&G);
    int input;
    do
    {
        menu();
        scanf("%d", &input);
        switch (input)
        {
        case 1:
            printf("深度优先遍历为:\n");
            DFSTraverse(G);
            printf("\n");
            break;
        case 2:
            printf("广度优先遍历为:\n");
            BFSTraverse(G);
            printf("\n");
            break;
        case 0:
            printf("退出程序\n");
            break;
        default:
            printf("输入错误,请重新输入>");
        }

    } while (input);
    printf("\n");
    return 0;
}
