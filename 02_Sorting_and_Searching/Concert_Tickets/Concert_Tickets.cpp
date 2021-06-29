#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
const int maxn = 2 * 1e5 + 5;

int n, m, un, t;
int h[maxn], uniq[maxn];
map<int, int> cnt;

int main() {
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++) scanf("%d", &h[i]);
    sort(h, h + n); 

    memcpy(uniq, h, sizeof(int) * n);
    un = unique(uniq, uniq + n) - uniq;

    for(int i = 0, j = 0; i < n && j < un; i++) {
        if(h[i] != uniq[j]) cnt[uniq[++j]] = 0;
        cnt[uniq[j]]++;
    }

    for(int i = 0; i < m; i++) {
        scanf("%d", &t);
        if(cnt.size()) {
            auto p = cnt.upper_bound(t);
            if(p-- != cnt.begin() && p->second) {
                printf("%d\n", p->first);
                if(--(p->second) == 0) { cnt.erase(p); }
            }
            else printf("-1\n");
        }
        else printf("-1\n");
    }

    return 0;
}
