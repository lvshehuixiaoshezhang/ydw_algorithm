/*
引入：
    你有一个长为n的数组，支持如下操作：
        1.在某个历史版本上修改某一个位置上的值
        2.访问某个历史版本上的某一位置值
    每次进行1操作，即生成一个版本，而0为初始数组


    算法：与权值线段树不同的是，这个需要维护val，直接动态开点即可

    权值线段树：查询某一个值的位置
    线段树：查询某一个点的位置
*/

//线段树+动态开点 nlogn
#include <iostream>
using namespace std;

#define N 1000005
#define mid ((l+r)>>1)
int n,m,a[N];
int root[N],tot; //根节点,节点个数
int ls[N*25],rs[N*25],val[N*25];

void build(int &u,int l,int r){ //建树
  u=++tot; //动态开点
  if(l==r){val[u]=a[l]; return;}
  build(ls[u],l,mid);
  build(rs[u],mid+1,r);
}
void change(int &u,int v,int l,int r,int p,int x){ //点修，p是修改的位置
  u=++tot; //动态开点
  ls[u]=ls[v]; rs[u]=rs[v];
  if(l==r){val[u]=x; return;} //双指针同步搜索
  if(p<=mid) change(ls[u],ls[v],l,mid,p,x);
  else change(rs[u],rs[v],mid+1,r,p,x);
}
int query(int u,int l,int r,int p){ //点查
  if(l==r) return val[u];
  if(p<=mid) return query(ls[u],l,mid,p);
  else return query(rs[u],mid+1,r,p);
}
int main(){
  scanf("%d%d",&n,&m);
  for(int i=1;i<=n;i++) scanf("%d",a+i);
  build(root[0],1,n);
  for(int i=1;i<=m;i++){
    int ver,op,p,x; scanf("%d%d",&ver,&op);
    if(op==1){
      scanf("%d%d",&p,&x);
      change(root[i],root[ver],1,n,p,x);      
    }
    else{
      scanf("%d",&p);
      printf("%d\n",query(root[ver],1,n,p));
      root[i]=root[ver];
    }
  }
}