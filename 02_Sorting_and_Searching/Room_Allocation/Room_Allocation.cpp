#include<cstdio>
#include<queue>
#include<vector>
#include<algorithm>
#include<stack>
#include<tuple>
using namespace std;
const int maxn = 2 * 1e5 + 5;

int a[maxn], b[maxn], n, ans[maxn];
vector<tuple<int, int, int> > vec;
priority_queue<pair<int, int> > pque;
stack<int> nuse;

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) { 
        scanf("%d%d", &a[i], &b[i]);
        vec.push_back(make_tuple(a[i], b[i], i));
    }

    sort(a, a + n);
    sort(b, b + n);
    sort(vec.begin(), vec.end());

    int p1 = 0, p2 = 0;
    int t = 0, rooms = 0;

    while(p2 < n) {
        if(p1 < n && a[p1] <= b[p2]) {
            t++; p1++;
            rooms = max(rooms, t);
        }
        else { t--; p2++; }
    }

    printf("%d\n", rooms);

    for(int i = rooms; i > 0; i--) nuse.push(i);

    for(int i = 0; i < (int)vec.size(); i++) {
        int first, second, third;
        tie(first, second, third) = vec[i];
        if(!pque.empty() && first > -pque.top().first) {
            nuse.push(pque.top().second);
            pque.pop();
        }
        pque.push(make_pair(-second, nuse.top()));
        ans[third] = nuse.top();
        nuse.pop();
    }

    for(int i = 0; i < n; i++) printf("%d%c", ans[i], (i == n-1 ? '\n' : ' '));

    return 0;
}
