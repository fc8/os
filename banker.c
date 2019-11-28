//银行家算法
#include "stdio.h"
#define N 3
#define M 5
typedef struct LNode *List;
struct LNode
{
    int Data[M];
    int Last;
};
struct LNode L;
//初始化
List MakeEmpty()
{
    List PtrL;
    PtrL = (List)malloc(sizeof(struct LNode));
    PtrL->Last = -1;
    return PtrL;
}
//查找
int Find(int X, List PtrL)
{
    int i = 0;
    while (i <= PtrL->Last && PtrL->Data[i] != X)
    {
        i++;
    }
    if (i > PtrL->Last)
    {
        return -1;
    }
    else
    {
        return i;
    }
}
//插入
void Insert(int X, int i, List PtrL)
{
    int j;
    if (PtrL->Last == M - 1)
    {
        printf("full");
        return;
    }
    if (i < 1 || i > PtrL->Last + 2)
    {
        printf("error");
        return;
    }
    for (j = PtrL->Last; j >= i - 1; j--)
    {
        PtrL->Data[j + 1] = PtrL->Data[j];
    }
    PtrL->Data[i - 1] = X;
    PtrL->Last++;
    return;
}
//删除
void Delete(int i, List PtrL)
{
    int j;
    if (i < 1 || i > PtrL->Last + 1)
    {
        printf("not find");
        return;
    }
    for (j = i; j <= PtrL->Last; j++)
    {
        PtrL->Data[j - 1] = PtrL->Data[j];
    }
    PtrL->Last--;
    return;
}
struct Resouce
{
    int p[N];
    int allocation[N];
    int need[N];
};
int main()
{
    List list = MakeEmpty(); //这是四个进程的名字
    int rs[M] = {};
    struct Resouce resouce[M] = {
        {{7, 5, 3}, {0, 1, 0}, {7, 4, 3}}, {{3, 2, 2}, {2, 0, 0}, {1, 2, 2}}, {{9, 0, 2}, {3, 0, 2}, {6, 0, 0}}, {{2, 2, 2}, {2, 1, 1}, {0, 1, 1}}, {{4, 3, 3}, {0, 0, 2}, {4, 3, 1}}}; //{
    //     {
    //         {3,2,2},{1,0,0},{2,2,2}
    //     },{
    //         {6,1,3},{6,1,2},{0,0,1}
    //     },{
    //         {3,1,4},{2,1,1},{1,0,3}
    //     },{
    //         {4,2,2},{0,0,2},{4,2,0}
    //     }
    // };
    int banker[N] = {3, 3, 2}; //这是总共的资源量
    int tempBanker[N] = {};
    int i, j, key = 1, safe = 1;
    //将进程变成一个队列
    for (i = 0; i < M; i++)
    {
        list->Data[i] = i;
        list->Last++;
        //printf("%d  %d\n",list->Data[i],list->Last);
    }

    // //计算剩下的资源
    // for(i=0;i<N;i++){
    //     for(j=0;j<M;j++){
    //         banker[i] = banker[i] - resouce[j].allocation[i];
    //     }
    //     //printf("%d\n",banker[i]);
    // }
    //开始求安全序列
    printf("输入要请求资源的进程号:");
    scanf("%d", &j);
    printf("输入要请求资源的数量:");
    scanf("%d %d %d", &tempBanker[0], &tempBanker[1], &tempBanker[2]);
    for (i = 0; i < N; i++)
    {
        if (resouce[list->Data[j]].need[i] - tempBanker[i] < 0)
        {
            printf("not safe");
            safe = 0;
            break;
        }
        resouce[list->Data[j]].need[i] = resouce[list->Data[j]].need[i] - tempBanker[i];
        banker[i] = banker[i] - tempBanker[i];
    }
    
    while (list->Last >= 0)
    {
        if (safe)
        {
            key = 1;
            for (i = 0; i < N; i++)
            {
                if (banker[i] < resouce[list->Data[j]].need[i])
                {
                    key = 0;
                    break;
                }
            }
            if (key)
            {
                printf("p%d:", list->Data[j] + 1);
                for (int n = 0; n < N; n++)
                {
                    //tempBanker[n] = banker[n] - resouce[j].need[n];
                    banker[n] = banker[n] - resouce[list->Data[j]].need[n];
                    printf("%4d", banker[n]);
                }
                printf("|");
                for (int n = 0; n < N; n++)
                {
                    printf("%4d", resouce[list->Data[list->Data[j]]].need[n]);
                }
                printf("|");
                for (int n = 0; n < N; n++)
                {
                    printf("%4d", resouce[list->Data[list->Data[j]]].allocation[n]);
                }
                printf("|");
                for (int n = 0; n < N; n++)
                {
                    banker[n] = resouce[list->Data[j]].p[n] + banker[n];
                    printf("%4d", banker[n]);
                }
                printf("\n");
                //printf("分配给%d进程A:%d,B:%d,C:%d\n",list->Data[j] + 1,resouce[list->Data[j]].need[0],resouce[list->Data[j]].need[1],resouce[list->Data[j]].need[2]);
                //计算现有资源量
                Delete(j + 1, list);
                j = 0;
            }
            else
            {
                j++;
            }
        }else{
            break;
        }
    }
}