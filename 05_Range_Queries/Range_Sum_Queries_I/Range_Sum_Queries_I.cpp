#include<iostream>
using namespace std;
const int maxn = 2 * 1e5 + 5;
int x[maxn];
long long acc[maxn];
int n, q;

int main() {
    cin >> n >> q;
    for(int i = 1; i <= n; i++) {
        cin >> x[i];
        acc[i] = acc[i-1] + x[i];
    }


    for(int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        cout << acc[b] - acc[a] << endl;
    }

    return 0;
}
