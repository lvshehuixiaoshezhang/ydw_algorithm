/*

快速幂+乘法逆元

*/



#include<iostream>
 #include<cstdio>
 #include<algorithm>
 #include<cstring>
 using namespace std;
 const int N=100005,mod=1e9+7;
 int fact[N],infact[N];
 int qmi(int a,int k,int p){
    int res=1;
    while(k){
        if(k&1) res=(long long)res*a%p;
        a=(long long)a*a%mod;
        k>>=1;
    }
    return res;
 }
 void init(){
    fact[0]=infact[0]=1;
    for(int i=1;i<N;i++){
        fact[i]=(long long)fact[i-1]*i%mod;
        infact[i]=(long long)infact[i-1]*qmi(i,mod-2,mod)%mod;
    }
 }
 int main(){
    int n;
    scanf("%d",&n);
    init();
    while(n--){
        int a,b;
        scanf("%d%d",&a,&b);
        printf("%d\n",(long long)fact[a]*infact[a-b]%mod*infact[b]%mod);
    }
    return 0;
 }