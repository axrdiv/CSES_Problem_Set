#include<iostream>
#include<vector>
using namespace std;

int n;
vector<pair<int, int> > vec;

void hanoi(int from, int to, int n) {
    if(n == 1) {
        vec.push_back(make_pair(from, to));
    }
    else {
        hanoi(from, 6 - from - to, n - 1);
        vec.push_back(make_pair(from, to));
        hanoi(6 - from - to, to, n - 1);
    }
}

int main() {
    cin >> n;

    hanoi(1, 3, n);
    cout << vec.size() << endl;
    for(auto p : vec) {
        cout << p.first << " " << p.second << endl;
    }

    return 0;
}
