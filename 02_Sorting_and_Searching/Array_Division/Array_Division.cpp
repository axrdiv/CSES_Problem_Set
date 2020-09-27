#include<cstdio>
using namespace std;
const int maxn = 2 * 1e5 + 5;

int n, k;
int vec[maxn];

bool val(long long m) {
    long long t = m;
    int p = 0;

    for(int i = 0; i < n; i++) {
        if(m < vec[i]) return false;
        if(t + vec[i] > m) {
            p++;
            t = vec[i];
        }
        else t += vec[i];

        if(p > k) return false;
    }
    return true;
}

int main() {
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; i++) scanf("%d", &vec[i]);

    long long l = 0, r = 2 * 1e14 + 5;

    while(l < r) {
        long long mid = (l + r) / 2;
        if(val(mid)) r = mid;
        else l = mid + 1;
    }

    printf("%lld\n", l);

    return 0;
}
