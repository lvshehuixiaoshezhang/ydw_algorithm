/*
中心到任意一点的距离最小

算法：
我们可以设置两个dp,但均表示从 该点 到其他点的最远距离：

d1[u]: u点向下走的最远距离
up[u]: u点向上走的最远距离

从这两个dp我们可以知道：
从u点到其他的最小距离为 d = max(d1[u],up[u]);
而我们需要最小化d，即中心点

1.从u点向下走的最远距离d1[u]:
    d2[u]为次大长度
    自底向上：
    d1[u] = d1[j] + w[i];
    d2[u] = d2[j] + w[i];//重点

    不难知道，我们可以递归到叶子节点处，存完值后再更新方程
    所以是先dfs，再更新

2.从u点向上走的最远距离up[u]:
    从1我们可以知道了向下走的最长距离，那么维护向上走的最长距离显然要自上而下

    对于u的子节点j来说，j的up[j]主要被两个值影响:
        一个是up[u]，另一个则是u的其他节点，即j的兄弟(所以我们要维护d2,因为害怕j在d1上)
    对于j：
        如果j在d1维护的路径上：
        up[j] = w[i] + max(up[u],d2[u]);

    否则:
        up[j] = w[i] + max(up[u],d1[u]);

*/
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int N=20010;
int n,a,b,c,ans=2e9;
struct edge{int v,w;};
vector<edge> e[N];
int d1[N],d2[N],path[N],up[N];

//与树的直径方法相同
void dfs_d(int x,int fa){
  for(auto ed : e[x]){
    int y=ed.v, z=ed.w;
    if(y==fa) continue;
    dfs_d(y, x);
    if(d1[y]+z>d1[x]) 
      d2[x]=d1[x],d1[x]=d1[y]+z,path[x]=y;//需要维护节点u的向下走的最大长度的节点y
    else if(d1[y]+z>d2[x]) d2[x]=d1[y]+z;
    // printf("回%d d1=%d d2=%d\n",x,d1[x],d2[x]);
  }
}

void dfs_up(int x,int fa){
  for(auto ed : e[x]){
    int y=ed.v, z=ed.w;
    if(y==fa) continue;
    if(y==path[x])up[y]=max(up[x],d2[x])+z;
    else up[y]=max(up[x],d1[x])+z;
    // printf("下%d up=%d\n",y,up[y]);
    dfs_up(y, x);
  }
}
int main(){
  cin>>n;
  for(int i=1; i<n; i++){
    cin>>a>>b>>c;
    e[a].push_back({b,c});
    e[b].push_back({a,c});
  }
  dfs_d(1, 0);
  dfs_up(1, 0);
  for(int i=1; i<=n; i++)
    ans=min(ans,max(d1[i],up[i]));
  cout << ans << endl;
  return 0;
}
