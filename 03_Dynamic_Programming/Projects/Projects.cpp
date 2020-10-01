#include<cstdio>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn = 2 * 1e5 + 5;
int n, a[maxn], b[maxn], p[maxn];
map<int, int> mp;

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d%d%d", &a[i], &b[i], &p[i]);
        b[i]++;
        mp[a[i]], mp[b[i]];
    }

    int coords = 0;
    for(auto &v : mp) v.second = coords++;

    vector<vector<pair<int, int> > > projects(coords);

    for(int i = 0; i < n; i++)
        projects[mp[b[i]]].push_back(make_pair(mp[a[i]], p[i]));

    vector<long long> dp(coords, 0);
    for(int i = 0; i < coords; i++) {
        if(i) dp[i] = dp[i-1];

        for(auto t : projects[i])
            dp[i] = max(dp[i], dp[t.first] + t.second);
    }

    printf("%lld\n", dp[coords-1]);
    return 0;
}
