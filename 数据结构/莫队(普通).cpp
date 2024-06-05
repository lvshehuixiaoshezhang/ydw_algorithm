/*
引入：
    该算法使用与对某一区间求f(ci)，ci为l和r出现的频率

    如果你有m个询问，需要你查询l到r的某一个权值出现的频率，我们可以怎么做？
    暴力做法：对于每一个查询lr，我们遍历每一个区间去查询，这样的复杂度是n^2

    莫队就是对这种暴力，用分块思想去优化
    即将暴力查询控制在根号n范围内


算法：
    我们有块长B
    离线操作，对于每一个区间我们按照l/B作为第一关键字从大到小排序
    我们发现，每一次查询与上一次查询只需要分类讨论两种情况：
    1.这次查询与上一次查询在同一个块：
        只需要在块内暴力执行“撤销”与“添加”操作即可，复杂度不会超过根号n
    2.不同块：
        跳到另一个块，而且不需要回到上一个块，最多遍历n次
    
    所以总复杂度是n*sqrt(n)

    优化：
    我们希望块与块过渡时候尽量近
    那么只需要奇数块让r升序，偶数块让r降序即可

注意：l到r属于1-n
*/

/*
本题让你求解
    对于一个查询位置l，r
        k
        sum((ci)^2)
        i=1

    其中k是值域，ci是频率，即该值出现的频率

    当一个数进来时候，对于答案的贡献减少c[i]*c[i]，随后c[i]++，然后再加新的c[i]*c[i];
    当一个数删除时候，对于答案的贡献减少c[i]*c[i]，随后c[i]--，然后再加新的c[i]*c[i];
*/
// 普通莫队 O(n*sqrt(n))
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

const int N=50005;
int n,m,k,B,a[N];
int sum,c[N],ans[N];
struct Q{
  int l,r,id;
  //按l所在块的编号l/B和r排序
  bool operator<(Q &b){
    if(l/B!=b.l/B) return l<b.l;
    if((l/B)&1) return r<b.r;
    return r>b.r;
  }
}q[N];

void add(int x){ //扩展一个数
  sum-=c[x]*c[x];
  c[x]++;
  sum+=c[x]*c[x];
}
void del(int x){ //删除一个数
  sum-=c[x]*c[x];
  c[x]--;
  sum+=c[x]*c[x];
}
int main(){
  scanf("%d%d%d",&n,&m,&k); 
  B=sqrt(n); //块的大小
  for(int i=1;i<=n;++i)scanf("%d",&a[i]);
  for(int i=1;i<=m;++i)
    scanf("%d%d",&q[i].l,&q[i].r),q[i].id=i;
  sort(q+1,q+1+m); //按l/B和r排序
  for(int i=1,l=1,r=0;i<=m;++i){
    while(l>q[i].l) add(a[--l]);//左扩展
    while(r<q[i].r) add(a[++r]);//右扩展
    while(l<q[i].l) del(a[l++]);//左删除
    while(r>q[i].r) del(a[r--]);//右删除
    ans[q[i].id]=sum;
  }
  for(int i=1;i<=m;++i)printf("%d\n",ans[i]);
}
