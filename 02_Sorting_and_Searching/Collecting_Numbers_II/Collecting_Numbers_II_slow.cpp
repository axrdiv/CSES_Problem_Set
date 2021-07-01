#include<iostream>
#include<vector>
#include<set>
using namespace std;
int n, m, tmp;
vector<int> vec;

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> tmp;
        vec.push_back(tmp);
    }

    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        swap(vec[a-1], vec[b-1]);
        set<int> targ; targ.insert(-vec[0]);
        for(int i = 1; i < n; i++) {
            if(*targ.lower_bound(-vec[i]) == -vec[i] + 1)
                targ.erase(targ.lower_bound(-vec[i]));
            targ.insert(-vec[i]);
        }
        cout << targ.size() << endl;
    }

    return 0;
}
