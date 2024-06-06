/*

公式证明较为简单，可以自信搜索
*/

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;
LL n, a[11], b[11];

LL exgcd(LL a,LL b,LL &x,LL &y){
  if(b==0){x=1, y=0; return a;}
  LL d, x1, y1;
  d = exgcd(b, a%b, x1, y1);
  x = y1, y = x1-a/b*y1;
  return d;
}
LL CRT(LL m[], LL r[]){
  LL M = 1, ans = 0;
  for(int i=1;i<=n;i++) M*=m[i];
  for(int i=1; i<=n; i++){
    LL c = M/m[i], x, y;
    exgcd(c, m[i], x, y);
    ans = (ans+r[i]*c*x%M)%M;
  }
  return (ans%M + M)%M;
}
int main(){
  scanf("%lld", &n);
  for(int i = 1; i <= n; ++i)
    scanf("%lld%lld", a+i, b+i);
  printf("%lld\n", CRT(a,b));
  return 0;
}