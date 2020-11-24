/*
 * The goal is to compute the summation
 * $$ \sum^n_{i=1} \lfloor \frac{n}{i} \rfloor \cdot i $$
 * in faster than $O(n)$ time.
 */
// https://usaco.guide/solutions/cses-1082
#include<iostream>
using namespace std;
const int mod = 1e9 + 7;
typedef long long ll;
ll n;

int main() {
    cin >> n;
    int ans = 0;
    for(ll i = 1, j; i <= n; i = j) {
        ll q = n/i; j = n/q+1;
        ll x = j - i, y = i + j - 1;
        if(x%2 == 0) x /= 2;
        else y /= 2;
        x %= mod, y %= mod;
        ans = (ans+q%mod*x%mod*y%mod)%mod;
    }
    cout << ans << endl;
    return 0;
}
