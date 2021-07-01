#include<iostream>
#include<vector>
#include<set>
using namespace std;
int n, tmp;
vector<int> vec;

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> tmp;
        vec.push_back(tmp);
    }

    set<int> targ; targ.insert(-vec[0]);

    for(int i = 1; i < n; i++) {
        if(*targ.lower_bound(-vec[i]) == -vec[i] + 1)
            targ.erase(targ.lower_bound(-vec[i]));
        targ.insert(-vec[i]);
    }

    // for(int i = 1; i < n; i++) {
    //     if(-vec[i] > *targ.rbegin()) targ.insert(-vec[i]);
    //     else {
    //         targ.erase(targ.lower_bound(-vec[i]));
    //         targ.insert(-vec[i]);
    //     }
    // }

    cout << targ.size() << endl;

    return 0;
}
