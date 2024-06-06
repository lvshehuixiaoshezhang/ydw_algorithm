/*
算法复杂度为logn，与gcd复杂度相同
不过该算法求得的是一个特解x0，y0

通解：
x = x0 + b/gcd(a,b)*k

y = y0 - a/gcd(a,b)*k

另外的，若ax+by = c,可以先求ax+by = gcd(a,b)
然后再乘上c/gcd(a,b)，如果gcd(a,b)不能整除c则无解
*/
#include<iostream>
 using namespace std;
 int exgcd(int a,int b,int &x,int &y){
    if(b==0){x=1,y=0;return a;}
    int d=exgcd(b,a%b,y,x);
    y-=a/b*x;
    return d;
 }

 int main(){
    int n;
    scanf("%d",&n);
    while(n--){
       int a,b,x,y;
        scanf("%d%d",&a,&b);
        exgcd(a,b,x,y);
        printf("%d %d\n",x,y);
    }
 }