#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 100 + 5;
const int maxc = 1e6 + 5;
const int mod = 1e9 + 7;

int n, x;
int dp[maxc], coins[maxn];

int main() {
    scanf("%d%d", &n, &x);
    for(int i = 0; i < n; i++) scanf("%d", &coins[i]);

    sort(coins, coins + n);

    dp[0] = 1;
    for(int i = 1; i <= x; i++) {
        for(int j = 0; j < n && i - coins[j] >= 0; j++) {
            if(dp[i - coins[j]])
                dp[i] = (dp[i] + dp[i - coins[j]]) % mod;
        }
    }

    printf("%d\n", dp[x]);

    return 0;
}
