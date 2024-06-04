/*
可以记录邮箱无环图的拓扑序

算法：
    纳入每一个度为0的点进入队列
    删队列的点并且将与该点连接的边删除(度--)
    若发现度为0，则加入队列


*/
#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5+10;
int n, m;
vector<vector<int>> G(MAXN);
int in[MAXN];  // 存储每个结点的入度

bool toposort() {
  vector<int> L;
  queue<int> q;

  while (!q.empty()) {
    int u = q.front();
    q.pop();
    L.push_back(u);
    for (auto v : G[u]) {
      if (--in[v] == 0) {
        q.push(v);
      }
    }
  }
  if (L.size() == n) {
    for (auto i : L) cout << i << ' ';
    return true;
  } else {
    return false;
  }
}

int main(){
    cin>>n>>m;
  
    for(int i = 0;i<m;i++){
        int x,y;
        cin>>x>>y;
        G[x].push_back(y);
        G[y].push_back(x);
        in[x]++;
        in[y]++;
    }
}