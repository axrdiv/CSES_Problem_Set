#include<iostream>
using namespace std;
typedef long long ll;

const int mod = 1e9 + 7;
int n;
ll ans = 1;

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        ans = (ans << 1) % mod;
    }
    cout << ans << endl;

    return 0;
}
