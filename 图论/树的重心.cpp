/*
移除重心点后，剩余的连通块点的数量的最大值最大
    即对于各个连通块中点的数量t，有max(t);
算法：
    size:记录u的最大子树的节点数
    sum:记录以u为根的子树的节点数
    n-sum：u上面部分的节点数
    ans = max(size,n-sum);
    注：一样是自底向上的算法
*/

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int N=100010;
int n, a, b;
vector<int> e[N];
int siz[N], pos, ans=1e9;

void dfs(int x, int fa){
  siz[x]=1;
  int mx=0;
  for(auto y : e[x]){
    if(y == fa) continue;
    dfs(y, x);
    siz[x] += siz[y];
    mx=max(mx, siz[y]);//更新size
  }
  mx=max(mx, n-siz[x]);//删除 u 后的连通块点数量的最大值
  if(mx<ans) ans=mx,pos=x;//更新答案并且存点
}
int main(){
  scanf("%d", &n);
  for(int i=1;i<n;i++){
    scanf("%d%d",&a,&b);
    e[a].push_back(b);
    e[b].push_back(a);
  }
  dfs(1, 0);
  printf("%d %d\n",pos,ans);
  return 0;
}
