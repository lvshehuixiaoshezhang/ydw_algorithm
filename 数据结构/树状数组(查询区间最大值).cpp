/*
该算法相对于线段树的优势：
    开的空间常数小，代码量小
劣势：
    修改与查询复杂度均为log^2(n)

*/
#include<bits/stdc++.h>

using namespace std;

int n,m;
vector<int>c;
vector<int>a;
int lowbit(int x){
    return x&-x;
}

int getmax(int l, int r) {
  int ans = 0;
  while (r >= l) {
    ans = max(ans, a[r]);
    --r;
    for (; r - lowbit(r) >= l; r -= lowbit(r)) {
      // 注意，循环条件不要写成 r - lowbit(r) + 1 >= l
      // 否则 l = 1 时，r 跳到 0 会死循环
      ans = max(ans, c[r]);
    }
  }
  return ans;
}

void update(int x, int v) {
  a[x] = v;
  for (int i = x; i <= n; i += lowbit(i)) {
    // 枚举受影响的区间
    c[i] = a[i];
    for (int j = 1; j < lowbit(i); j *= 2) {
      c[i] = max(c[i], c[i - j]);
    }
  }
}

//建树时候拆分成n个update即可，复杂度是nlog^2(n)

//on建树：
// Θ(n) 建树,预处理一个 sum前缀和数组，再计算 c 数组。
vector<int>sum;
void init() {
  for (int i = 1; i <= n; ++i) {
    c[i] = sum[i] - sum[i - lowbit(i)];
  }
}
