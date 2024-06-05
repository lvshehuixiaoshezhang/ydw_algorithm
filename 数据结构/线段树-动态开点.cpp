/*
算法：
    在普通线段树中，我们利用2p和2p+1来标识左右儿子，可这样的结果是需要提前开4*n的空间

    我们把2p替换成ls，2p+1替换成rs，这样对于u节点来说，我们就可以不用提前开，而是实时开了

    动态开的节点tot其实只是一个唯一标识，在搜寻区间时候仍需要区间l，r辅助
    可以想象为对于一个4*n的线段树，但n很大，而对于这个线段树表来说
    我们只需要访问到哪就开到哪即可

    单次开点复杂度为logn
    修改次数为m，最坏情况的时候，查询区间需要开左右两个分支，所以复杂度为O（m*2logn）

*/

//线段树+动态开点 qlogn
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

#define N 300005*60
#define ls tr[u].l
#define rs tr[u].r
#define mid ((l+r)>>1)
int n,q,root,tot;
struct tree{
  int l,r;
}tr[N];
int sum[N],tag[N];
//sum:区间和
//tag:0:工作日 1:非工作日 -1:清空标记

void pushup(int u){ //上传
  sum[u]=sum[ls]+sum[rs];
}
void pushdown(int u,int l,int r){ //下传
  if(tag[u]==-1) return;
  if(!ls) ls=++tot; //动态开点
  if(!rs) rs=++tot;
  sum[ls]=tag[u]*(mid-l+1);
  sum[rs]=tag[u]*(r-mid);
  tag[ls]=tag[rs]=tag[u];
  tag[u]=-1;
}
void change(int &u,int l,int r,int x,int y,int k){ //区修
  if(!u) u=++tot; //动态开点
  if(x<=l&&r<=y){
    sum[u]=k*(r-l+1); tag[u]=k; return;
  }
  pushdown(u,l,r);
  if(x<=mid) change(ls,l,mid,x,y,k);
  if(y>mid) change(rs,mid+1,r,x,y,k);
  pushup(u);
}
int main(){
  memset(tag,-1,sizeof(tag));
  scanf("%d%d",&n,&q);
  for(int i=1,l,r,opt; i<=q; i++){
    scanf("%d%d%d",&l,&r,&opt);
    if(opt==1) change(root,1,n,l,r,1);
    else change(root,1,n,l,r,0);
    printf("%d\n",n-sum[root]);
  }
  return 0;
}
