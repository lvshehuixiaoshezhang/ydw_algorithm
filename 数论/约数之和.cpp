
/*
每个约数就是质因子的组合乘积

不难得知公式就是
t = pi^j
a = sum(t)(j 从 0-ci)
结果 = a的连乘(i从0-m),m为质因子的种类
    

*/

#include<iostream>
#include<map>
using namespace std;
 const int mod = 1e9 + 7;
 int main() {
    int n, x;
    cin >> n;
    map<int, int> prime;
    while (n--) {
        cin >> x;
        for (int i = 2; i <= x / i; i++) {
            while (x % i == 0) {
               x /= i;
                prime[i]++;
            }
        }
        if (x > 1) prime[x]++;
    }
    long long ans = 1;
    for (map<int, int>::iterator i = prime.begin(); i != prime.end(); i++) {
        long long a = (*i).first, b = (*i).second;
        long long t = 1;
        while (b--) t = (t * a + 1) % mod;
        ans = ans * t % mod;
    }
    cout << ans;
    return 0;
 }