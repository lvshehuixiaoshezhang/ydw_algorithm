/*
树中任意两点距离的最大值

算法原理：
任取一点u，从u点往下搜，返回时收集边的权值

d1:记录从u往下走的最长路径长度；
d2:记录从u往下走的次长路径长度；

那么显然易见，我们设d[u]为悬挂在u点上的最长路径长度

则d[u] = d1+d2;

空间优化：可以不用开d[u]，实时更新即可
*/


#include<bits/stdc++.h>
using namespace std;

const int N=10010,M=20010;
int n,a,b,c,ans;
struct edge{int v,w;};
vector<edge> e[N];



int dfs(int x,int fa){
  int d1=0,d2=0; 
  for(auto ed : e[x]){
    int y=ed.v, z=ed.w;
    if(y==fa) continue;

    int d=dfs(y,x)+z;//记录每一个d[y]
    if(d>=d1) d2=d1,d1=d;//维护最大值
    else if(d>d2) d2=d;//维护次大值
    // printf("回%d d1=%d d2=%d\n",x,d1,d2);
  }
  ans=max(ans,d1+d2);
  // printf("离%d ans=%d\n",x,ans);
  return d1;
}

vector<int>d1(N),d2(N);//带数组版本
void dfs2(int x,int fa){
      d1[x] =0;
      d2[x] = 0;
      for(auto ed:e[x]){
        int y = ed.v,z = ed.w;
        if(y == fa)continue;
        
        dfs(y,x);
        int d = d1[y] + z;
        if(d>=d1[x]){
          d2[x] = d1[x];
          d1[x] = d;
        }
        else if(d>d2[x])d2[x] = d;

      }
      ans = max(ans,d1[x]+d2[x]);
}

int main(){
  cin>>n;
  for(int i=1; i<n; i++){
    cin>>a>>b>>c;
    e[a].push_back({b,c});
    e[b].push_back({a,c});
  }
  dfs(1,-1);
  cout << ans << endl;
  return 0;
}
