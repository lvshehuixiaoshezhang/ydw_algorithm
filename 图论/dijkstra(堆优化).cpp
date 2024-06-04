/*
    由于n过大，所以我们用邻接表去存储节点
    在原来的dijkstra算法里，将中间的n^2循环用堆优化，变成从n^2个点找到一个最小值，复杂度降为mlogm

步骤:
    创建一个优先队列，用于维护1-n的最短路径与节点
    从1开始遍历，每次取出最小路径，再利用这个节点去更新dist


注意：m在完全图中会退化成n^2logn^2，不如暴力
*/

#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
typedef pair<int,int>PII;
const int N = 200010;

int dist[N];
vector<vector<pair<int,int> > >h(N);
bool st[N];
int n,m;
int dijkstra(){
    memset(dist,0x3f,sizeof dist);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>heap;//小根堆
    dist[1]= 0;
    heap.push({0,1});//xdist权，y节点

    while(heap.size()){
        auto t = heap.top();
        heap.pop();
        int distance = t.first,val = t.second;
        if(st[val])continue;//如果这个节点被用过了，就退出
        for(int i = 0;i<h[val].size();i++){
            int j = h[val][i].first,wj = h[val][i].second;
            if(dist[j]>distance+wj){
                dist[j] = distance+wj;
                heap.push({dist[j],j});
            }
        }
        st[val] = true;//更新
    }
    if(dist[n] == 0x3f3f3f3f)return -1;
    else return dist[n];


}


int main(){
    cin>>n>>m;
    int x,y,c;
    for(int i = 0;i<m;i++){
        cin>>x>>y>>c;
        h[x].push_back({y,c});

    }
    int t = dijkstra();
    printf("%d\n",t);
}


