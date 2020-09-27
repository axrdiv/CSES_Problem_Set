#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;

int N;
ll before, tmp, maxsum;

int main() {
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> tmp;
        before = max(0LL,  before);
        maxsum = i == 0 ? tmp : max(maxsum, before + tmp);
        before = before + tmp;
    }
    cout << maxsum << endl;

    return 0;
}
