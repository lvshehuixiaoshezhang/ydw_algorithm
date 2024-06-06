#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;
const int N = 100000010;
int vis[N];  //划掉合数
int prim[N]; //记录质数
int cnt; //质数个数

void Eratosthenes(int n){ //埃氏筛法
  for(LL i=2; i<=n; ++i){
    if(!vis[i]){
      prim[++cnt] = i;
      for(LL j=i*i; j<=n; j+=i)
        vis[j] = 1;
    }
  }
}
int main(){
  int n, q, k;
  scanf("%d %d", &n, &q);
  Eratosthenes(n);
  while(q--){
    scanf("%d", &k);
    printf("%d\n", prim[k]);
  }
  return 0;
}