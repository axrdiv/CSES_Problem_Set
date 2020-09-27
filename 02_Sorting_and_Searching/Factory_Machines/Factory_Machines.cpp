#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 2 * 1e5 + 5;

int n, t, m = 1e9 + 10;
int vec[maxn];

bool val(long long time) {
    long long tot = 0;
    for(int i = 0; i < n; i++) {
        tot += time / vec[i];
        if(tot >= t) return true;
    }
    return false;
}

int main() {
    scanf("%d%d", &n, &t);

    for(int i = 0; i < n; i++) scanf("%d", &vec[i]);
    for(int i = 0; i < n; i++) m = min(m, vec[i]);

    long long l = 0, r = (long long)t * m;

    while(l < r) {
        long long mid = (l + r) / 2;
        if(val(mid)) r = mid;
        else l = mid + 1;
    }

    printf("%lld\n", l);

    return 0;
}
