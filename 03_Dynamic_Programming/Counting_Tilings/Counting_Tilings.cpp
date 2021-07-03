#include<iostream>
using namespace std;
const int maxm = 1000 + 5;
const int maxn = 10;
const int MOD = 1e9 + 7;
int n, m;
int dp[2][1<<maxn];

int main() {
    cin >> n >> m;

    int *crt = dp[0], *next = dp[1];
    crt[0] = 1;

    for(int i = m-1; i >= 0; i--) {
        for(int j = n-1; j >= 0; j--) {
            for(int used = 0; used < (1 << n); used++) {
                if(used & (1 << j)) {
                    next[used] = crt[used & ~(1<<j)];
                }
                else {
                    int res = 0;
                    if(j + 1 < n && !(used & (1 << (j+1))))
                        res += crt[used | 1 << (j + 1)];
                    if(i + 1 < m) {
                        res += crt[used | 1 << j];
                    }
                    next[used] = res % MOD;
                }
            }
            swap(crt, next);
        }
    }

    cout << crt[0] << endl;

    return 0;
}
