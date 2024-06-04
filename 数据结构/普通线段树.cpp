/*
x,y是需要查询的区间
结构体内部：
l，r：用于标记节点p所维护的闭区间l，r
d：l-r的区间和
b：lazy标记
*/

/*
递归思路：
从节点p开始搜索，若lr在x与y内就返回
否则将lr区间劈开，递归下去
*/

/*
单点修改可以将懒标记删掉，因为懒标记是针对区间修改的

*/
#include<bits/stdc++.h>

using namespace std;

const int maxn=100010;

int a[maxn];

struct tree{
    int l,r;
    long long d,b;
}t[4*maxn];

void build(int p,int l,int r){
    t[p].l=l;t[p].r=r;
    if(l==r){
        t[p].d=a[l];
        return;
    }
    int mid=l+r>>1;
    build(p*2,l,mid);
    build(p*2+1,mid+1,r);
    t[p].d=t[p*2].d+t[p*2+1].d;
} 

void lazy(int p){
    if(t[p].b){
        t[p*2].d+=t[p].b*(t[p*2].r-t[p*2].l+1);
        t[p*2+1].d+=t[p].b*(t[p*2+1].r-t[p*2+1].l+1);
        t[p*2].b+=t[p].b;
        t[p*2+1].b+=t[p].b;
        t[p].b=0;
    }
}

void change(int p,int x,int y,int z){
    if(x<=t[p].l && y>=t[p].r){
        t[p].d+=(long long)z*(t[p].r-t[p].l+1);
        t[p].b+=z;
        return;
    }
    lazy(p);
    int mid=t[p].l+t[p].r>>1;
    if(x<=mid) change(p*2,x,y,z);
    if(y>mid) change(p*2+1,x,y,z);
    t[p].d=t[p*2].d+t[p*2+1].d;   
}

long long ask(int p,int x,int y){
    if(x<=t[p].l && y>=t[p].r) return t[p].d;
    lazy(p);
    int mid=t[p].l+t[p].r>>1;
    long long ans=0;
    if(x<=mid) ans+=ask(p*2,x,y);
    if(y>mid) ans+=ask(p*2+1,x,y);
    return ans;
}

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    scanf("%d",&a[i]);
    build(1,1,n);
    for(int i=1;i<=m;i++)
    {
        int q,x,y,z;
        scanf("%d",&q);
        if(q==1){
            scanf("%d%d%d",&x,&y,&z);
            change(1,x,y,z);
        }
        else {
            scanf("%d%d",&x,&y);
            cout<<ask(1,x,y)<<endl;
        }
    }
    return 0;
}
