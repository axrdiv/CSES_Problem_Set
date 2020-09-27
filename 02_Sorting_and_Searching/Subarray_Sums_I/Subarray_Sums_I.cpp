#include<cstdio>
using namespace std;
const int maxn = 2 * 1e5 + 5;

int n, x;
int vec[maxn], sum;
long long ans;

int main() {
    scanf("%d%d", &n, &x);
    for(int i = 0; i < n; i++) scanf("%d", &vec[i]);

    int l = 0, r = 0;
    while(l < n) {
        if(r < n && sum < x) {
            sum += vec[r];
            r++;
            continue;
        }
        if(sum == x) ans++;
        sum -= vec[l];
        l++;
    }
    printf("%lld\n", ans);

    return 0;
}
