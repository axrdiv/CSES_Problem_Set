#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
string str;
vector<string> ans;

int main() {
    cin >> str;
    sort(str.begin(), str.end());
    do {
        ans.push_back(str);
    }while(next_permutation(str.begin(), str.end()));

    cout << ans.size() << endl;
    for(int i = 0; i < (int)ans.size(); i++) {
        cout << ans[i] << endl;
    }

    return 0;

}
