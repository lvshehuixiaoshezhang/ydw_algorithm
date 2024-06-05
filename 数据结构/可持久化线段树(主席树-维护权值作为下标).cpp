/*
引入：
    假设我们有一个问题，我们需要查询某个区间的第k小值，我们该怎么做？
    首先权值作为下标，这一点很重要
    暴力做法，对于n个前缀，我们维护n个线段树，每一个线段树维护的是1-i的权值（即a[i]作为下标）
    那么查询l到r的第k大值，只需要在递归的时候对每个线段树节点执行t = root[r].s - root[l-1].s：
        表示该区间拥有的节点数量
    如果左节点的t小于k，那么第k大值肯定在左节点
    否则在右节点

    那么这个算法的复杂度是4*n*n

    如何优化呢？
    我们发现，每一个值插入的时候，只需要更改线段树上的某一条链，那我们只需要为更改的一条链单独开空间即可
    这样每次只需要修改 logn + 1个节点，而初始建树（空的，均为0，为了前缀方便使用）需要2*n - 1个节点
    所以节点总数为
    2n - 1 + n（logn+1） = nlogn + 3n;

    开链过程：
        双指针同步搜索root[i-1]和root[i];
        如果修改的是右节点，那么将root[i-1]的左节点赋值给root[i]，然后动态开点root[i]的右节点
        反之同理，那么就形成一个递归，往下算也是一样的
    查询过程：
        与暴力过程相同，但需要双指针同步搜索





*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define N 200005
#define lc(x) tr[x].l
#define rc(x) tr[x].r
struct node{
  int l,r,s; //s:节点值域中有多少个数
}tr[N*20];
int root[N],idx;
int n,m,a[N];
vector<int> b;

void build(int &x,int l,int r){
  x=++idx;
  if(l==r) return;
  int m=l+r>>1;
  build(lc(x),l,m);
  build(rc(x),m+1,r);
}


void insert(int x,int &y,int l,int r,int k){
  y=++idx; tr[y]=tr[x]; tr[y].s++;//先为root[i]赋值root[i-1]
  if(l==r) return;
  int m=l+r>>1;
  if(k<=m) insert(lc(x),lc(y),l,m,k);//如果插入的下标在左边，则为左边动态开点，并且同步搜索
  else insert(rc(x),rc(y),m+1,r,k);
}


int query(int x,int y,int l,int r,int k){
  if(l==r) return l;
  int m=l+r>>1;
  int s=tr[lc(y)].s-tr[lc(x)].s;
  if(k<=s) return query(lc(x),lc(y),l,m,k);
  else return query(rc(x),rc(y),m+1,r,k-s);//这里注意需要减去前缀
}


int main(){
  scanf("%d%d",&n,&m);
  for(int i=1; i<=n; i++){
    scanf("%d",&a[i]); b.push_back(a[i]);
  }
  sort(b.begin(),b.end());
  b.erase(unique(b.begin(),b.end()),b.end());
  int bn=b.size();

  build(root[0],1,bn);
  for(int i=1; i<=n; i++){
    int id=lower_bound(b.begin(),b.end(),a[i])-b.begin()+1;
    insert(root[i-1],root[i],1,bn,id);
  }
  while(m--){
    int l,r,k; scanf("%d%d%d",&l,&r,&k);
    int id=query(root[l-1],root[r],1,bn,k)-1;
    printf("%d\n",b[id]);
  }
  return 0;
}
