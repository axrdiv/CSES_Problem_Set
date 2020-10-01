#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 500 + 5;
const int mod = 1e9 + 7;
const int mid = maxn * maxn / 2;

int n;
int dp[2][maxn * maxn];

int main() {
    scanf("%d", &n);

    // init
    dp[1][mid + 1] = 1;

    for(int i = 2; i <= n; i++) {
        memset(dp[i&1], 0, sizeof(int) * maxn * maxn);
        for(int j = 0; j < maxn * maxn; j++) {
            if(dp[(i-1)&1][j]) {
                dp[i&1][j - i] += dp[(i-1)&1][j];
                dp[i&1][j - i] %= mod;
                dp[i&1][j + i] += dp[(i-1)&1][j];
                dp[i&1][j + i] %= mod;
            }
        }
    }

    printf("%d\n", dp[n&1][mid]);

    return 0;
}
