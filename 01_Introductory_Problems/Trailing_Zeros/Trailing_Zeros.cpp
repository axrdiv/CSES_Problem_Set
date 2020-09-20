#include<iostream>
using namespace std;
int n, ans;

int main() {
    cin >> n;
    for(int i = 5; i <= n; i += 5) {
        int tmp = i;
        while(tmp % 5 == 0) {
            tmp /= 5;
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
