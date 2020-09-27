#include<cstdio>
#include<map>
#include<algorithm>
using namespace std;
const int maxn = 2 * 1e5 + 5;

int n, tmp, vec[maxn], ans;
map<int, int> mp;

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &tmp);
        auto up =mp.upper_bound(tmp);
        if(up != mp.end()) {
            up->second--;
            if(!up->second) mp.erase(up);
            ans--;
        }
        mp[tmp]++;
        ans++;
    }

    printf("%d\n", ans);

    return 0;
}
