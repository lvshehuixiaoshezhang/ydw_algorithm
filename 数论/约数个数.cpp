/*

个数 = (质因子p1个数+1)*(质因子p2个数+1)*...

*/


#include<iostream>
#include<unordered_map>
 using namespace std;
 const int mod = 1e9 + 7;
 int main() {
    int n, x;
    cin >> n;
    unordered_map<int, int> prime;
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
    for (unordered_map<int, int>::iterator i = prime.begin(); i != prime.end(); 
i++) {
        ans = ans * ((*i).second + 1) % mod;
    }
    cout << ans;
    return 0;
 }