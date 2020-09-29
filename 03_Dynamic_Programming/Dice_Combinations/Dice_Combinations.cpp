#include<cstdio>
using namespace std;

const int maxn = 1e6 + 5;
const int mod = 1e9 + 7;
int n, dp[maxn];

int main() {
    scanf("%d", &n);
    dp[0] = 1;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= 6 && i - j >= 0; j++)
            dp[i] = (dp[i] + dp[i-j]) % mod;

    printf("%d\n", dp[n]);

    return 0;
}
