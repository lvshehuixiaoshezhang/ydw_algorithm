//单点增加，区间查询和
//区间增加，单点查询：区间增加变为差分操作，则单点查询则是统计该点的前缀和

/*
树状数组可以操作 + - * ^，这里都是可差分的

对于max(min)，维护的值只能越来越大(小)

*/
#include <iostream>
#include <algorithm>
#define N 200005
#define ll long long
using namespace std;

//注意：树状数组是从1开始的，从0开始会死循环
int n;//树状数组长度
ll a[N], b[N], c[N], h[N];

ll sum(int i, ll *ar) {
    ll ret = 0;
    while (i > 0) {
        ret += ar[i];
        i -= i&-i;
    }
    return ret;
}//查询

ll query(int l, int r, ll *ar) {
    return sum(r, ar) - sum(l-1, ar);
}

void update(int i, ll x, ll *ar) {
    while (i <= n) {
        ar[i] += x;
        i += i&-i;
    }
}//修改
