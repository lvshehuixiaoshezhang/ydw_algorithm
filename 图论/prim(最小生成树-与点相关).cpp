/*
算法：
S:当前已经在联通块中的所有点的集合
    1. dist[i] = inf dist[t]的含义是t到集合所有点中最小的边权值
    2. for n 次（迭代n次）
        3. t<-S外离S最近的点
        4. 将dist[t]加入最小生成树的权值res当中
        5. 利用t更新S外点到S的距离
        6. st[t] = true

n次迭代之后所有点都已加入到S中
联系：Dijkstra算法是更新到起始点的距离，Prim是更新到集合S的距离

细节：
1.第4条不能放到第5条后面，因为如果dist[t]有负权自环时候,dist[j] = min(dist[j],g[j][t])就会更新，由于最小生成树没有环，
所以这种更新是不合法的，故要提前将dist[t]加到res当中

2.如果遍历到的点不是第一个点且该点的大小是INF，就说明该点是孤立点，说明这个图无法生成最小树，返回

O(n^2)

*/


#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N = 510;
int g[N][N],dist[N];
int n,m;
bool st[N];
int res;
bool prim(){
   memset (dist,0x3f,sizeof dist);

   for(int i = 0;i<n;i++){

       int t = -1;
       for(int j = 1;j<=n;j++){
           if(!st[j] &&(t==-1 || dist[t]>dist[j])){
               t=j;
           }
       }
       if(i&&dist[t] == 0x3f3f3f3f)return false;

       st[t] = true;

       if(i)res+=dist[t];

       for(int j = 1;j<=n;j++){
           dist[j] = min(dist[j],g[j][t]);

       }


   }

   return true;


}

int main(){
    memset(g,0x3f,sizeof g);
    cin>>n>>m;
    int a,b,w;
    while(m--){
        cin>>a>>b>>w;
        g[b][a]=g[a][b] = min(g[a][b],w);//删除重边

    }
    bool t = prim();
    if(!t)cout<<"impossible"<<endl;
    else cout<<res<<endl;
}

