#include<cstdio>
#include<set>
#include<map>
using namespace std;

int x, n, tmp;
map<int, int> lig, lgn;

int main() {
    scanf("%d%d", &x, &n);

    lig[x] = x;
    lgn[x] = 1;

    for(int i = 0; i < n; i++) {
        scanf("%d", &tmp);
        auto up = lig.upper_bound(tmp);
        int l = up->second;
        up->second = up->first - tmp;
        int t = lig[tmp] = l - up->second;

        lgn[l]--;
        if(!lgn[l]) lgn.erase(l);

        lgn[l-t]++;
        lgn[t]++;

        printf("%d%c", *lgn.rbegin(), (i == n-1 ? '\n' : ' '));
    }

    return 0;
}
