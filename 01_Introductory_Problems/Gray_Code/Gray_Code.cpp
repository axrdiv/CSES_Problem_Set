#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int n;
void gray(vector<string> &s, int d) {
    if(d == 1) {
        s.push_back("0");
        s.push_back("1");
    }
    else {
        gray(s, d-1);
        int ns = s.size();
        for(int i = ns-1; i >= 0; i--) s.push_back(s[i]);
        for(int i = 0; i < s.size(); i++) {
            s[i].append((i&(1<<(d-1)) ? "1" : "0"));
        }
    }


}

int main() {
    cin >> n;
    vector<string> s;
    gray(s, n);

    for(int i = 0; i < s.size(); i++) {
        reverse(s[i].begin(), s[i].end());
        cout << s[i] << endl;
    }

    return 0;
}
