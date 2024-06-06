#include <iostream>
using namespace std;

const int N = 1e9+10;

int phi(int n){ //试除法求欧拉函数
  int res = n;
  for(int i=2; i*i<=n; i++){
    if(n%i == 0){
      res = res/i*(i-1);
      while(n%i == 0) n /= i;
    }
  }
  if(n>1) res = res/n*(n-1);
  return res;
}
int main(){
  int n;
  cin >> n;
  cout << phi(n) << endl;
  return 0;
}