#include<iostream>
#include<vector>
#include<algorithm>
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

    sort(vec.begin(), vec.end());

    long long s = 0;
    bool find = false;
    for(int i = 0; i < vec.size(); i++) {
        if(vec[i] > s + 1) {
            find = true;
            cout << s + 1 << endl;
            break;
        }
        else s += vec[i];
    }
    if(!find) cout << s+1 << endl;

    return 0;
}
