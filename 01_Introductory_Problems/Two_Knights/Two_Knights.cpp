#include<iostream>
using namespace std;
int n;
const int dx[] = {-2, -1, 1, 2};
const int dy[] = {-1, -2, -2, -1};

long long ans[10000 + 5];

int main() {
    cin >> n;
    ans[1] = 6;
    for(long long i = 2; i < n; i++) {
        ans[i] = ans[i - 1];
        long long inc = 0;
        for(int j = 0; j < i; j++) {
            int block = 0;
            for(int k = 0; k < 4; k++) {
                if(i + dy[k] >= 0 && j + dx[k] >= 0 && j + dx[k] < i) block++;
            }
            inc += i * i - block;
        }
        inc = inc * 2 + (i + 1) * (i + 1) - 3 + 2 * i * i - i - 2;
        ans[i] += inc;
    }
    for(int i = 0; i < n; i++)
        cout << ans[i] << endl;
    return 0;
}
