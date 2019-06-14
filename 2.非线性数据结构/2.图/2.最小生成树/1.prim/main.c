#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

#define MAX 100            // 矩阵最大容量
#define INF (~(0x1 << 31)) // 最大值(即0X7FFFFFFF)
#define isLetter(a) ((((a) >= 'a') && ((a) <= 'z')) || (((a) >= 'A') && ((a) <= 'Z')))
#define LENGTH(a) (sizeof(a) / sizeof(a[0]))

// 邻接矩阵
typedef struct _graph
{
    char vexs[MAX];       // 顶点集合
    int vexnum;           // 顶点数
    int edgnum;           // 边数
    int matrix[MAX][MAX]; // 邻接矩阵
} Graph, *PGraph;

/*
 * 返回ch在matrix矩阵中的位置
 */
static int get_position(Graph g, char ch)
{
    int i;
    for (i = 0; i < g.vexnum; i++)
        if (g.vexs[i] == ch)
            return i;
    return -1;
}
/*
 * 创建图(用已提供的矩阵)
 */
Graph *create_example_graph()
{
    char vexs[] = {'A', 'B', 'C', 'D', 'E'};
    int matrix[][5] = {
        /*A*/ /*B*/ /*C*/ /*D*/ /*E*/
        /*A*/ {0, 1, 6, 5, 7},
        /*B*/ {1, 0, 4, INF, 2},
        /*C*/ {6, 4, 0, 3, 5},
        /*D*/ {5, INF, 3, 0, 6},
        /*E*/ {7, 2, 5, 6, 0},
    };
    int vlen = LENGTH(vexs);
    int i, j;
    Graph *pG;

    // 输入"顶点数"和"边数"
    if ((pG = (Graph *)malloc(sizeof(Graph))) == NULL)
        return NULL;
    memset(pG, 0, sizeof(Graph));

    // 初始化"顶点数"
    pG->vexnum = vlen;
    // 初始化"顶点"
    for (i = 0; i < pG->vexnum; i++)
        pG->vexs[i] = vexs[i];

    // 初始化"边"
    for (i = 0; i < pG->vexnum; i++)
        for (j = 0; j < pG->vexnum; j++)
            pG->matrix[i][j] = matrix[i][j];

    // 统计边的数目
    for (i = 0; i < pG->vexnum; i++)
        for (j = 0; j < pG->vexnum; j++)
            if (i != j && pG->matrix[i][j] != INF)
                pG->edgnum++;
    pG->edgnum /= 2;

    return pG;
}

/*
 * prim最小生成树
 *
 * 参数说明：
 *       G -- 邻接矩阵图
 *   start -- 从图中的第start个元素开始，生成最小树
 */
void prim(Graph G, int start)
{
    int min, i, j, k, m, n, sum;
    int index = 0;    // prim最小树的索引，即prims数组的索引
    char prims[MAX];  // prim最小树的结果数组
    int weights[MAX]; // 顶点间边的权值

    // prim最小生成树中第一个数是"图中第start个顶点"，因为是从start开始的。
    prims[index++] = G.vexs[start];

    // 初始化"顶点的权值数组"，
    // 将每个顶点的权值初始化为"第start个顶点"到"该顶点"的权值。
    for (i = 0; i < G.vexnum; i++)
        weights[i] = G.matrix[start][i];
    // 将第start个顶点的权值初始化为0。
    // 可以理解为"第start个顶点到它自身的距离为0"。
    weights[start] = 0;

    for (i = 0; i < G.vexnum; i++)
    {
        // 由于从start开始的，因此不需要再对第start个顶点进行处理。
        if (start == i)
            continue;

        j = 0;
        k = 0;
        min = INF;
        // 在未被加入到最小生成树的顶点中，找出权值最小的顶点。
        while (j < G.vexnum)
        {
            // 若weights[j]=0，意味着"第j个节点已经被排序过"(或者说已经加入了最小生成树中)。
            if (weights[j] != 0 && weights[j] < min)
            {
                min = weights[j];
                k = j;
            }
            j++;
        }

        // 经过上面的处理后，在未被加入到最小生成树的顶点中，权值最小的顶点是第k个顶点。
        // 将第k个顶点加入到最小生成树的结果数组中
        prims[index++] = G.vexs[k];
        // 将"第k个顶点的权值"标记为0，意味着第k个顶点已经排序过了(或者说已经加入了最小树结果中)。
        weights[k] = 0;
        // 当第k个顶点被加入到最小生成树的结果数组中之后，更新其它顶点的权值。
        for (j = 0; j < G.vexnum; j++)
        {
            // 当第j个节点没有被处理，并且需要更新时才被更新。
            if (weights[j] != 0 && G.matrix[k][j] < weights[j])
                weights[j] = G.matrix[k][j];
        }
    }

    // 计算最小生成树的权值
    sum = 0;
    for (i = 1; i < index; i++)
    {
        min = INF;
        // 获取prims[i]在G中的位置
        n = get_position(G, prims[i]);
        // 在vexs[0...i]中，找出到j的权值最小的顶点。
        for (j = 0; j < i; j++)
        {
            m = get_position(G, prims[j]);
            if (G.matrix[m][n] < min)
                min = G.matrix[m][n];
        }
        sum += min;
    }
    // 打印最小生成树
    printf("PRIM(%c) = %d: ", G.vexs[start], sum);
    for (i = 0; i < index; i++)
        printf("%c ", prims[i]);
    printf("\n");
}

void main()
{
    Graph *pG;
    pG = create_example_graph();
    prim(*pG, 0); // prim算法生成最小生成树
}
