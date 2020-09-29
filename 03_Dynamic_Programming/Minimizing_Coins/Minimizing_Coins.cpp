#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 100 + 5;
const int maxc = 1e6 + 5;
int n, x;
int coins[maxn];
int dp[maxc];
bool can[maxc];


int main() {
    scanf("%d%d", &n, &x);
    for(int i = 0; i < n; i++) scanf("%d", &coins[i]);

    sort(coins, coins + n);

    can[0] = 1;
    for(int i = 1; i <= x; i++) {
        dp[i] = maxc;
        for(int j = 0; j <= n && i - coins[j] >= 0; j++) {
            if(can[i - coins[j]]) {
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                can[i] = 1;
            }
        }
    }

    printf("%d\n", (can[x] ? dp[x] : -1));


    return 0;
}
