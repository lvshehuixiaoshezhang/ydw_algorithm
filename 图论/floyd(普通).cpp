/*floyd算法思想是动态规划，即d[k,i,j] = d[k-1,i,k]+[k-1,k,j],k-1维可以优化掉

重边就保留最小边，自环就置为0，因为么有负权环,所以可以保证是最短距离

传递闭包可以更换为 d[i][j] |= d[i][k] && d[k][j];//这里可以用bitset去优化掉一个32常数量级

*/

#include<iostream>

using namespace std;

const int N = 210,INF = 1e9;
int dist[N][N];
int n,m,k;

void floyd(){
    for(int k = 1;k<=n;k++){
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=n;j++){
                dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);//传递闭包可以更换为 d[i][j] |= d[i][k] && d[k][j];
            }
        }
    }
}
int main(){
    scanf("%d%d%d",&n,&m,&k);
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            if(i==j)dist[i][j] = 0;
            else dist[i][j] = INF;
        }
    }
    int a,b,w;
    for(int i = 1;i<=m;i++){
        scanf("%d%d%d",&a,&b,&w);
        dist[a][b] = min(dist[a][b],w);
    }

    floyd();
    for(int i = 1;i<=k;i++){
        scanf("%d%d",&a,&b);
        if(dist[a][b]>INF/2)cout<<"impossible"<<endl;
        else cout<<dist[a][b]<<endl;
    }
}

