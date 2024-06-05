/*
凸包：点集中由最小点集构成的最大凸边型
算法：分为下凸包和下凸包
按照x升序，y升序排序，可知第一个点和最后一个点必然在凸包点中
下凸包：正向遍历所有点，栈顶为top，将top-1指向top的点视为a向量
若新点在a向量右侧或者共线，则删除旧点（不可删除第一个点），新点无论如何都要加入栈

上凸包：从倒数第二个点开始遍历（最后一个点肯定已经加入栈中），原则是不可pop上凸包的点，在代码中体现，若新点在a向量右侧或者共线，删除旧点，新点无论如何都要加入栈

最后栈的结果是凸包环，即栈中的第一个元素等于最后一个元素

判断新点在向量位置的方法：
补充：对于x,y,z点，我们有两向量y-x，z-y，是这两个向量做叉乘
叉积：即对向量（x1,y1）(x2,y2)来说，ans = x1*y2-x2*y1
若ans>=0，则在右侧或者共线，需pop旧点
否则直接加入栈

复杂度：取决于排序，为nlogn



*/

#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

const int N=100010;
struct Point{double x,y;} p[N],s[N];
int n,top;

double cross(Point a,Point b,Point c){ //叉积
  return (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);
}
double dis(Point a,Point b){ //距离
  return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
bool cmp(Point a, Point b){ //比较
  return a.x!=b.x ? a.x<b.x : a.y<b.y;
}
double Andrew(){
  sort(p+1,p+n+1,cmp); //排序
  for(int i=1; i<=n; i++){ //下凸包
    while(top>1&&cross(s[top-1],s[top],p[i])<=0)top--;
    s[++top]=p[i];
  }
  int t=top;
  for(int i=n-1; i>=1; i--){ //上凸包
    while(top>t&&cross(s[top-1],s[top],p[i])<=0)top--;
    s[++top]=p[i];
  }
  double res=0; //周长
  for(int i=1; i<top; i++) res+=dis(s[i],s[i+1]);
  return res;
}
int main(){
  scanf("%d",&n);
  for(int i=1;i<=n;i++)scanf("%lf%lf",&p[i].x,&p[i].y);
  printf("%.2lf\n", Andrew());
  return 0;
}
