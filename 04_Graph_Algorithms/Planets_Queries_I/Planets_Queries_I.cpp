#include<iostream>
using namespace std;
const int maxn = 2e5+5;
const int maxd = 31;

int n, q;
int dp[maxd][maxn];

int main() {
    cin >> n >> q;
    for(int i = 1; i <= n; i++)
        cin >> dp[0][i];

    for(int d = 1; d < maxd; d++) {
        for(int i = 1; i <= n; i++) {
            int nxt = dp[d-1][i];
            dp[d][i] = dp[d-1][nxt];
        }
    }

    for(int i = 0; i < q; i++) {
        int x;
        long long k;
        cin >> x >> k;
        int d = 0;
        while(k) {
            if(k&1) x = dp[d][x];
            k = k >> 1;
            d++;
        }
        cout << x << endl;
    }

    return 0;
}
