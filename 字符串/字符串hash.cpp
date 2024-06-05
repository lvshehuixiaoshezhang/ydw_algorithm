#include <bits/stdc++.h>
using namespace std;
bool isprime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int findPrime(int n) {
    while (!isprime(n)) {
        n++;
    }
    return n;
}

int main()
{
  mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
      
     int mod = findPrime( rng() % 900000000 + 10000000);
     cout << mod << endl;

      
}
