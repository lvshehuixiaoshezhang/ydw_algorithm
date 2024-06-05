
/*
从暴力做法来看，我们先枚举n，再枚举k，复杂度是o（nk），一定会超时
暴力时候我们发现了一些性质，例如最小值
我们有ij，且j<i
如果a[j]>a[i]，那么a[j]这个数在窗口内是用不了的
那我们就有一个想法，创造一个队列，让tail负责将满足条件的元素入队，让head负责把溢出窗口的元素出队
*/

#include<bits/stdc++.h>
using namespace std;
vector<int>a,q;
//我们定义，在h==t的时候，必定存在一个唯一值，在出队后就有h>t故而这样初始化
int hh  =0,tt = -1;
int main(){
   int n,m;
   cin>>n>>m;
   for(int i = 0;i<n;i++)cin>>a[i];
   for(int i = 0;i<n;i++){
       if(q[hh]<=i-m)hh++;
       while(hh<=tt && a[q[tt]]<=a[i])tt--;
       q[++tt] = i;
   }
   return 0;
}
