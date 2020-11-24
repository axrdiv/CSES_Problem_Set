#include<iostream>
using namespace std;
const int mod = 1e9 + 7;
const int maxx = 1e6 + 5;
typedef long long ll;
int n;
int a, b;
int dp[maxx];

int modpow(int a, int b, int m) {
    if(b == 0) return 1 % m;
    ll u = modpow(a, b/2, m);
    u = (u * u) % m;
    if(b & 1) u = (u * a) % m;
    return u;
}

int inv(int x) {
    return modpow(x, mod-2, mod);
}

int main() {
    dp[0] = 1;
    for(int i = 1; i < maxx; i++) {
        dp[i] = (long long)dp[i-1] * i % mod;
    }


    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a >> b;
        cout << ((ll)dp[a]*inv(dp[b])%mod*inv(dp[a-b])%mod) << endl;
    }

    return 0;
}
