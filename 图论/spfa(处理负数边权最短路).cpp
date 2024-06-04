/*
思路：在贝尔曼福算法之上改编，只需要更新遍历过的点即可

第二：在队列中的点在更新后就没必要再次入队

该算法能保证最后队列为空，但如果有负权环就会陷入无限循环

*/

#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
typedef pair<int,int>PII;
int n,m;
const int N  = 100010;
int h[N],ne[N],e[N],w[N],idx;
bool st[N];
int dist[N];

void add(int a,int b,int z){
    w[idx] = z,e[idx] = b,ne[idx] = h[a],h[a] = idx++;
}

bool spfa(){
    queue<PII>q;
    memset(dist,0x3f,sizeof dist);
    dist[1] = 0;
    q.push({0,1});
    //st[1] = true;
    while(q.size()){
        auto t = q.front();
        q.pop();
        int distance = t.first,val = t.second;
        st[val] = false;
        for(int i=h[val];i!=-1;i = ne[i]){
            int j =e[i];
            if(dist[j]>dist[val]+w[i]){
                dist[j]= dist[val]+w[i];
                if(!st[j]){//如果j不在队列中,入队，因为在队列中有该点再入队也没有意义
                    st[j] = true;
                    q.push({dist[j],j});
                }
            }
        }
    }
    if(dist[n]==0x3f3f3f3f)return false;
    else return true;

}
int main(){
    memset(h,-1,sizeof h);
    cin>>n>>m;
    while(m--){
        int x,y,z;
        cin>>x>>y>>z;
        add(x,y,z);
    }
    bool t = spfa();
    if(!t)cout<<"impossible"<<endl;
    else cout<<dist[n]<<endl;

}

