#include<iostream>
#include<algorithm>
using namespace std;

int t, a, b;

bool solve(int a, int b) {
    if(a > b) swap(a, b);
    if(a == b) return a % 3 == 0;
    if(a == 0) return false;
    return (a * 2 - b) >= 0 && (a * 2 - b) % 3 == 0;
}

int main() {
    cin >> t;
    for(int i = 0; i < t; i++) {
        cin >> a >> b;
        cout << (solve(a, b) ? "YES" : "NO") << endl;
    }
    return 0;
}
