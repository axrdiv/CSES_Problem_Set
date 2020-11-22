#include<iostream>
using namespace std;
const int maxx = 1e6 + 5;
int cnt[maxx];
int n, x;

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> x;
        for(int j = 1; j * j <= x; j++) {
            if(x % j == 0) {
                cnt[j]++;
                if(j != x/j) cnt[x/j]++;
            }
        }
    }

    for(int i = maxx - 1; i >= 0; i--) {
        if(cnt[i] >= 2) {
            cout << i << endl;
            break;
        }
    }

    return 0;
}
