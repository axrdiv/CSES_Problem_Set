#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn = 100 + 5;
const int maxc = 1e6 + 5;
const int mod = 1e9 + 7;

int n, x;
int coins[maxn], dp[maxc];

int main() {
    scanf("%d%d", &n, &x);
    for(int i = 0; i < n; i++) scanf("%d", &coins[i]);

    sort(coins, coins + n);

    dp[0] = 1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= x; j++) {
            if(j - coins[i] >= 0)
                dp[j] += dp[j - coins[i]];
            dp[j] %= mod;
        }
    }

    printf("%d\n", dp[x]);

    return 0;
}
