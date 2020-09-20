#include<iostream>
using namespace std;
int n;

int main() {
    cin >> n;
    if(n == 1) cout << "1" << endl;
    else if(n < 4) cout << "NO SOLUTION" << endl;
    else {
        for(int i = 2; i <= n; i+=2)
            cout << i << " ";
        for(int i = 1; i <= n; i+=2)
            cout << i << (i + 2 > n ? "\n" : " ");
    }
    return 0;
}
