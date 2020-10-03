#include<iostream>
#include<set>
#include<algorithm>
#include<vector>
using namespace std;
int n, k, ans;
multiset<int> mst;
int st, ed;
vector<pair<int, int> > vec;

int main() {
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> st >> ed;
        vec.push_back(make_pair(st, ed));
    }

    sort(vec.begin(), vec.end());

    for(int i = 0; i < n; i++) {
        while(!mst.empty() && *mst.begin() <= vec[i].first)
            mst.erase(*mst.begin());
        if((int)mst.size() < k)
            ans++, mst.insert(vec[i].second);
        else if (*mst.rbegin() > vec[i].second) {
            mst.erase(*mst.rbegin());
            mst.insert(vec[i].second);
        }
    }

    cout << ans << endl;

    return 0;
}
