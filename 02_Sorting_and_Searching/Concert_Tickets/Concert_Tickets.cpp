#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn = 2 * 1e5 + 5;

int n, m, un;
int h[maxn], uniq[maxn], cnt[maxn];
int t, p;

int main() {
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++) scanf("%d", &h[i]);
    sort(h, h + n); 

    memcpy(uniq, h, sizeof(int) * n);
    un = unique(uniq, uniq + n) - uniq;

    for(int i = 0, j = 0; i < n && j < un; i++) {
        if(h[i] != uniq[j]) j++;
        cnt[j]++;
    }

    for(int i = 0; i < m; i++) {
        scanf("%d", &t);
        p = upper_bound(uniq, uniq + un, t) - uniq;
        p--;
        while(p >= 0 && !cnt[p]) p--;
        if(p >= 0 && cnt[p]) {
            cnt[p]--;
            printf("%d\n", uniq[p]);
        }
        else {
            printf("-1\n");
        }
    }

    return 0;
}
