#include<cstdio>
using namespace std;

const int maxn = 1000 + 5;
const int mod = 1e9 + 7;
char line[maxn];
int n, dp[maxn];


int main() {
    scanf("%d", &n);

    dp[1] = 1;
    for(int i = 1; i <= n; i++) {
        scanf("%s", line);
        for(int j = 1; j <= n; j++) {
            if(line[j - 1] == '.')
                dp[j] = (dp[j] + dp[j - 1]) % mod;
            else
                dp[j] = 0;
        }
    }

    printf("%d\n", dp[n]);

    return 0;
}
