#include<iostream>
#include<set>
#include<vector>
using namespace std;
int n, k, tmp;
multiset<int> up, low;
vector<int> vec;

void insert(int val) {
    int mid = *low.rbegin();
    if(mid < val) {
        up.insert(val);
        if(up.size() > k/2) {
            low.insert(*up.begin());
            up.erase(up.find(*up.begin()));
        }
    }
    else {
        low.insert(val);
        if(low.size() > (k+1)/2) {
            up.insert(*low.rbegin());
            low.erase(low.find(*low.rbegin()));
        }
    }
}

void erase(int val) {
    if(up.find(val) != up.end()) up.erase(up.find(val));
    else low.erase(low.find(val));
    if(low.empty()) {
        low.insert(*up.begin());
        up.erase(up.find(*up.begin()));
    }
}

int main() {
    cin >> n >> k;
    for(int i = 0; i < n; i++) { cin >> tmp; vec.push_back(tmp); }

    low.insert(vec[0]); for(int i = 1; i < k; i++) insert(vec[i]);
    cout << *low.rbegin() << " ";
    for(int i = 0; i < n-k; i++) {
        if(k == 1) {
            insert(vec[i+k]);
            erase(vec[i]);
        }
        else {
            erase(vec[i]);
            insert(vec[i+k]);
        }
        cout << *low.rbegin();
        cout << (i == n-k-1 ? "\n" : " ");
    }

    return 0;
}
