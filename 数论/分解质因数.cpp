/*
根据算术基本定理，n = p1^k1*p2^k2*....pc^kc




*/
#include<iostream>
 using namespace std;
 void divide(int x) {
    for (int i = 2; i <= x / i; i++) {
        if (x % i == 0) {
            int s = 0;
            while (x % i == 0) x /= i, s++;
            cout << i << ' ' << s << endl;
        }
    }
    if (x > 1) cout << x << ' ' << 1 << endl;
    cout << endl;
 }
 int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        divide(x);
    }
    return 0;
 }