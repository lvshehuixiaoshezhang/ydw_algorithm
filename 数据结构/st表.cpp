/*
对于线段树的优势：
    o1查询区间最大值
    利用倍增思想：f[i][j] = max(f[i][j - 1],f[i+2^(j-1)][j-1]);
n=6
区间长度倍增:1,2,4,8....
f[i, 0]: [1 1][2 2][3 3][4 4][5 5][6 6]
f[i, 1]: [1 2][2 3][3 4][4 5][5 6]
f[i, 2]: [1 4][2 5][3 6]
*/
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

int f[100005][22];

int main(){
  int n,m; scanf("%d%d",&n,&m);
  
  for(int i=1;i<=n;i++) scanf("%d",&f[i][0]);
  for(int j=1;j<=20;j++) //枚举区间长度
    for(int i=1;i+(1<<j)-1<=n;i++) //枚举起点
      f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1]);
  
  for(int i=1,l,r;i<=m;i++){
    scanf("%d%d",&l,&r);
    int k=log2(r-l+1); //区间长度的指数
    printf("%d\n",max(f[l][k],f[r-(1<<k)+1][k]));
  }
}