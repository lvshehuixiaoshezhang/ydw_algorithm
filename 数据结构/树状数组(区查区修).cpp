

/*
区查区修
对差分数组两次求和，发现可以用两颗树状数组维护值，推一下就知道了
*/

#include<bits/stdc++.h>
using namespace std;
int n;
void update(int x,int k,int* c1,int* c2)
{
    int t=x;
    while(x<=n)
    {
        c1[x]+=k;
        c2[x]+=k*(t-1);
        x+=x&-x;
    }
}
int query(int x,int* c1,int* c2)
{
    int ans=0,t=x;
    while(x>=1){

        ans+=c1[x]*t-c2[x];
        x-=x&-x;
    }
    return ans;
}
int main(){
    // update(l,x);
    // update(r+1,-x);
    // printf("%d\n",query(r)-query(l-1));
    return 0;
}