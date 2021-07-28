#include<iostream>
#include<set>
#include<vector>
using namespace std;
int n, k, tmp;
multiset<int> up, low;
vector<int> vec;
long long slow, sup;

void insert(int val) {
    int mid = *low.rbegin();
    if(mid < val) {
        up.insert(val);
        sup += val;
        if(up.size() > k/2) {
            slow += *up.begin();
            sup -= *up.begin();

            low.insert(*up.begin());
            up.erase(up.find(*up.begin()));
        }
    }
    else {
        low.insert(val);
        slow += val;
        if(low.size() > (k+1)/2) {
            sup += *low.rbegin();
            slow -= *low.rbegin();
            up.insert(*low.rbegin());
            low.erase(low.find(*low.rbegin()));
        }
    }
}

void erase(int val) {
    if(up.find(val) != up.end()) {
        sup -= val;
        up.erase(up.find(val));
    }
    else {
        slow -= val;
        low.erase(low.find(val));
    }
    if(low.empty()) {
        slow += *up.begin();
        sup -= *up.begin();

        low.insert(*up.begin());
        up.erase(up.find(*up.begin()));
    }
}

int main() {
    cin >> n >> k;
    for(int i = 0; i < n; i++) { cin >> tmp; vec.push_back(tmp); }

    low.insert(vec[0]); slow += vec[0];
    for(int i = 1; i < k; i++) insert(vec[i]);

    cout << sup - slow + *low.rbegin() - (k & 1? 0 : *low.rbegin());
    for(int i = 0; i < n-k; i++) {
        if(k == 1) {
            insert(vec[i+k]);
            erase(vec[i]);
        }
        else {
            erase(vec[i]);
            insert(vec[i+k]);
        }
        cout << " " << sup - slow + *low.rbegin() - (k & 1? 0: *low.rbegin());
    }
    cout << endl;

    return 0;
}
