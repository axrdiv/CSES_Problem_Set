#include<iostream>
using namespace std;
const int maxn = 2 * 1e5 + 5;
int root[maxn];
int sub[maxn];
int n;

int main() {
    cin >> n;
    for(int i = 0; i < n-1; i++)
        cin >> root[i];

    for(int i = n-2; i >= 0; i--) {
        sub[root[i]] += sub[i+2] + 1;
    }

    for(int i = 1; i <= n; i++)
        cout << sub[i] << (i == n ? '\n' : ' ');

    return 0;
}
