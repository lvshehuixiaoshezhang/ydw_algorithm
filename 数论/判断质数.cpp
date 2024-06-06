//O(sqrt(n))



#include<iostream>
 using namespace std;
 bool is_prime(int n) {
    if (n < 2) return false;
    for (int i = 2; i < n / i; ++i) {
        if (n % i == 0) return false;
    }
    return true;
 }
 int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        if (is_prime(a)) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
 }