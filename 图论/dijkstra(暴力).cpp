/*
朴素dijkstra算法

    首先，我们用一个dist[N]去存储1到n的最短路径，所以dist一开始需要是最大值

    还需要一个集合st，代表当前这个点没有被选过

    由于当前有n个点，所以我们需要迭代n次；
    然后用t=-1（一个不存在的数值即可）去选出没有被选过且距离最小的点；
    再用这个点去更新1到n的最小距；

时间复杂度是o（n^2）
*/

#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const int N = 510;
int g[N][N];//由于边数很多，所以用临接矩阵
int dist[N];
bool st[N];
int n,m;

int dijsktra(){
    memset(dist,0x3f,sizeof dist);
    dist[1]= 0;//起点与起点距离就是0；
    for(int i = 0;i<n;i++){
        int t = -1;
        for(int j = 1;j<=n;j++){
            if(!st[j] &&(t==-1 || dist[t]>dist[j])){
                t=j;
            }//选出一个1-n路径总权值最小的
        }
        st[t] = true;

        for(int j = 1;j<=n;j++){
            dist[j] = min(dist[j],dist[t]+g[t][j]);
        }
    }
    if(dist[n]==0x3f3f3f3f)return -1;
    else return dist[n];
}

int main(){
    memset(g,0x3f,sizeof g);//一个元素的值是0x3f3f3f3f，四个3f
    scanf("%d%d",&n,&m);
    int x,y,w;
    for(int i=0;i<m;i++){
        scanf("%d%d%d",&x,&y,&w);
        g[x][y] = min(g[x][y],w);

    }
    int t = dijsktra();
    printf("%d\n",t);
    return 0;

}


