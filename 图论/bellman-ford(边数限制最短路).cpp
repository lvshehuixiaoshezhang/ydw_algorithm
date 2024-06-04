/*
    
2、什么是bellman - ford算法？
    Bellman - ford 算法是求含负权图的单源最短路径的一种算法，效率较低，代码难度较小。
    其原理为连续进行松弛，在每次松弛时把每条边都更新一下，若在 n-1 次松弛后还能更新
    ，则说明图中有负环，因此无法得出结果，否则就完成。

    (通俗的来讲就是：假设 1 号点到 n 号点是可达的，每一个点同时向指向的方向出发，
    更新相邻的点的最短距离，通过循环 n-1 次操作，若图中不存在负环，则 1 号点一定会到达 n 号点，
    若图中存在负环，则在 n-1 次松弛后一定还会更新)

3、bellman - ford算法的具体步骤
    for n次(k的边数限制就迭代k次)
    for 所有边 a,b,w (松弛操作)
    dist[b] = min(dist[b],back[a] + w)

注意：由于算法原因，我们需要一次只更新一层，那么第二层for可能会更新两次或以上
    backup[] 数组是上一次迭代后 dist[] 数组的备份，
    由于是每个点同时向外出发，因此需要对 dist[] 数组进行备份，
    若不进行备份会因此发生串联效应，影响到下一个点


该算法用什么东西存储边都可以，这次用结构体



*/

#include<iostream>
#include<cstring>
using namespace std;
int const N = 510,M = 10010;
int n,m,k;
struct Edge{
    int a,b,w;
}edges[M];

int dist[N],backup[N];

bool bellman_ford(){
    memset(dist,0x3f,sizeof(dist));
    dist[1]= 0;
    for(int i = 0;i<k;i++){
        memcpy(backup,dist,sizeof(dist));

        for(int j = 1;j<=m;j++){
            int a = edges[j].a,b = edges[j].b,w = edges[j].w;
            dist[b] = min(dist[b],backup[a]+w);
        }
    }

    if(dist[n]>0x3f3f3f3f/2)return false;
    else return true;//需要注意负权边不能仅用一个负数去作为返回值，只能用bool



}

int main(){
    cin>>n>>m>>k;
    int x,y,w;
    for(int i = 1;i<=m;i++){
        cin>>x>>y>>w;
        edges[i] = {x,y,w};
    }
    bool t =bellman_ford();
    if(!t)cout<<"impossible"<<endl;
    else cout<<dist[n]<<endl;
}
