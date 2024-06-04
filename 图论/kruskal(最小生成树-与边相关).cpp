/*
    kruskal思想：
    先对每一条边按权值从小到大排序，再选出最小的边

    如果这条边所连的点已经连过了，就不用连了，因为我们需要保证最小生成树是没有环的

    可以用并查集去维护，如果不在集合内部再去加

    算法复杂度即排序复杂度mlogm

    另外还要定义一个cnt，用来统计加的边数，如果cnt<n-1，则加边不完全，无法构成最小生成树
*/

#include<iostream>
#include<algorithm>

using namespace std;

const int M =200010; 
int n,m;
int p[M];
struct Edge{
    int a,b,w;
    bool operator <(const Edge &W)const{
        return w<W.w;
    }
}edges[M];


int find(int x){
    if(p[x]!=x)p[x] = find(p[x]);
    return p[x];
}

int main(){
    cin>>n>>m;
    for(int i = 0;i<n;i++){
        p[i] = i;
    }
    for(int i = 0;i<m;i++){
        int a,b,w;
        cin>>a>>b>>w;
        edges[i] = {a,b,w};
    }
    sort(edges,edges+m);
    int res = 0,cnt=0;
    for(int i = 0;i<m;i++){
        int a = edges[i].a,b = edges[i].b,w= edges[i].w;

        int x = find(a),y = find(b);
        if(x!=y){
            res+=w;
            p[x] = y;
            cnt++;
        }
    }
    if(cnt<n-1)cout<<"impossible"<<endl;
    else cout<<res<<endl;
}
