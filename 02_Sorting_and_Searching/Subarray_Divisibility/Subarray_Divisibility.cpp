#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

const int maxn = 2 * 1e5 + 5;
int n;
long long ans;
vector<int> vec, rem;
vector<pair<int, int> > p;


int main() {
    cin >> n;
    int remain = 0;
    for(int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        vec.push_back(tmp);
        remain += tmp;
        if(remain < 0) remain += (abs(remain) / n + 1) * n;
        remain %= n;
        p.push_back(make_pair(remain, i+1));
        rem.push_back(remain);
    }

    p.push_back(make_pair(0, 0));
    sort(p.begin(), p.end());

    for(int i = 0; i < n; i++) {
        int r = rem[i];
        auto it1 = lower_bound(p.begin(), p.end(), make_pair(r, 0));
        auto it2 = lower_bound(p.begin(), p.end(), make_pair(r, i+1));
        ans += it2 - it1;
    }

    cout << ans << endl;
    return 0;
}
