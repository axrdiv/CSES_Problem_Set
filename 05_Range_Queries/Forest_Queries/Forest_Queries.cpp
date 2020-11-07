#include<iostream>
#include<string>
using namespace std;
const int maxn = 1000 + 5;
int S[maxn][maxn];
bool F[maxn][maxn];
int n, q;


int main() {
    cin >> n >> q;
    string s;
    getline(cin, s);
    for(int i = 0; i < n; i++) {
        getline(cin, s);
        for(int j = 0; j < n; j++) {
            if(s[j] == '*')
                F[i][j] = 1;
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            S[i][j] = S[i-1][j] + S[i][j-1] + F[i-1][j-1] - S[i-1][j-1];
        }
    }

    for(int i = 0; i < q; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        cout << S[c][d] - S[c][b-1] - S[a-1][d] + S[a-1][b-1] << endl;
    }

    return 0;
}
