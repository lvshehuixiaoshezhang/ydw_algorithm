/*
引入：
    如何查询l到r的f(ci)，并且能对p位置的数修改呢？

算法：
    我们可以为每一个查询分配一个时间戳，如下：
    操作 时间戳
    Q      0
    Q      0
    R
    Q      1
    R
    Q      2

    然后对查询按照l/B第一关键字，r/B第二关键字，time第三关键字进行排序
    
    在查询时候，我们先按照普通莫队进行指针转移
    然后把该查询的时间戳time记录下来，与修改数组（修改数组的时间戳即下标）现在的时间戳x进行比较
    while1
        对于修改位置在l，r的数
        如果time小于x，则说明我们要修改，那么先删掉原来的数，在加上修改的数
        
    
    while2
        对于修改位置在l，r的数
        如果time大于x，则说明我们要回溯，那么先删掉原来修改的数，在加上原来的数
    
    细节：  
        对于1，我们需要先++x，再修改，(执行Q前面所有的R)
        对于2，我们需要先修改，再--x,(执行Q后面的R)



注意：l到r属于1-n

*/

// 带修莫队 O(n^(5/3))
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

const int N=1000005;
int n,m,B,mq,mr,a[N];
int sum,cnt[N],ans[N];
struct Q{ //询问
  int l,r,id,tim;
  //按l/B、r/B和tim排序
  bool operator<(Q &b){
    if(l/B!=b.l/B)return l<b.l;
    if(r/B!=b.r/B)return r<b.r;
    return tim<b.tim;
  }
}q[N];
struct R{ //替换
  int p,c;
}R[N];

void add(int x){
  if(!cnt[x])sum++; //x第一次则累计
  cnt[x]++;         //x出现次数
}
void del(int x){
  cnt[x]--;
  if(!cnt[x]) sum--;
}
int main(){
  scanf("%d%d",&n,&m); B=pow(n,0.66);
  for(int i=1;i<=n;i++)scanf("%d",&a[i]);
  for(int i=1;i<=m;i++){ //操作
    char c[2]; int l,r;
    scanf("%s%d%d",c,&l,&r);
    if(c[0]=='Q')q[++mq]={l,r,mq,mr};
    else R[++mr]={l,r};
  }
  sort(q+1,q+1+mq);
  for(int i=1,l=1,r=0,x=0;i<=mq;i++){
    while(l>q[i].l)add(a[--l]); //左扩展
    while(r<q[i].r)add(a[++r]); //右扩展
    while(l<q[i].l)del(a[l++]); //左删除
    while(r>q[i].r)del(a[r--]); //右删除
    while(x<q[i].tim){ //时间戳变大，替换
      int p=R[++x].p;
      //位置p介于[l,r]，先删旧数，后加新数
      if(l<=p&&p<=r)del(a[p]),add(R[x].c);
      swap(a[p],R[x].c); //交换a,R的对应数
    }
    while(x>q[i].tim){ //时间戳变小，还原
      int p=R[x].p;
      if(l<=p&&p<=r)del(a[p]),add(R[x].c);
      swap(a[p],R[x--].c);
    }
    ans[q[i].id]=sum;
  }
  for(int i=1;i<=mq;i++)printf("%d\n",ans[i]);
}
