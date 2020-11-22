#include<iostream>
using namespace std;
const long long mod = 1e9 + 7;

long long a, b;
int n;

long long modpow(int a, int b) {
    if(b == 0) return 1 % mod;
    long long u = modpow(a, b/2);
    u = (u * u) % mod;
    if(b&1) u = (u * a) % mod;
    return u;
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a >> b;
        cout << modpow(a, b) << endl;
    }

    return 0;
}
