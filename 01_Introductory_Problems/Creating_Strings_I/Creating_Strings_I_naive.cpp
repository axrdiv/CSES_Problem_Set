#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
string str;
vector<string> ans;
char strp[10];
bool vis[10];

void permutation(int dep, const int n) {
    if(dep == n) {
        ans.push_back(string(strp));
        return;
    }

    for(int i = 0; i < n; i++) {
        if(vis[i]) continue;
        vis[i] = 1;
        strp[dep] = str[i];
        permutation(dep + 1, n);
        vis[i] = 0;
        while(i + 1 < n && str[i + 1] == str[i]) i++;
    }
}


int main() {
    cin >> str;
    sort(str.begin(), str.end());

    permutation(0, str.size());

    cout << ans.size() << endl;
    for(int i = 0; i < (int)ans.size(); i++) {
        cout << ans[i] << endl;
    }

    return 0;

}
