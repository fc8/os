//银行家算法
#include "stdio.h"
#define N 3
#define M 4
struct Resouce{
    int p[N];
    int allocation[N];
    int need[N];
};
int main(){
    struct Resouce resouce[M] = {
        {
            {3,2,2},{1,0,0},{2,2,2}
        },{
            {6,1,3},{6,1,2},{0,0,1}
        },{
            {3,1,4},{2,1,1},{1,0,3}
        },{
            {4,2,2},{0,0,2},{4,2,0}
        }
    };
    int banker[3] = {9,3,6};
    int i,j;
    //计算剩下的资源
    for(i=0;i<N;i++){
        for(j=0;j<M;j++){
            banker[i] = banker[i] - resouce[j].allocation[i];
        }
        printf("%d\n",banker[i]);
    }
    
}