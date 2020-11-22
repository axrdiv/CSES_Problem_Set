#include<iostream>
using namespace std;
const int mod = 1e9 + 7;

int n;
long long a, b, c;

long long modpow(long long a, long long b, int m) {
    if(b == 0) return 1 % m;
    long long u = modpow(a, b/2, m);
    u = (u * u) % m;
    if(b & 1) u = (u * a) % m;
    return u;
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a >> b >> c;
        cout << modpow(a, modpow(b, c, mod-1), mod) << endl;
    }

    return 0;
}
