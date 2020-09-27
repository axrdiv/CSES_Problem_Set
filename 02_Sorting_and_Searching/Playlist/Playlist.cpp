#include<cstdio>
#include<set>
#include<algorithm>
using namespace std;
const int maxn = 2 * 1e5 + 5;
int n, vec[maxn];
set<int> s;
int ans;

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &vec[i]);

    int l = 0, r = 0;
    while(r < n) {
        if(s.count(vec[r])) {
            s.erase(vec[l]);
            l++;
        }
        else {
            s.insert(vec[r]);
            r++;
            ans = max(ans, (int)s.size());
        }
    }
    printf("%d\n", ans);


    return 0;
}
