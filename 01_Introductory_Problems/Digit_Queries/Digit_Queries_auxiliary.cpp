#include<iostream>
#include<string>
using namespace std;

int main() {
    string st;

    int t = 10;
    for(int i = 1; i <= 100000; i++) {
        st = st + to_string(i);
        if((i+1) % t == 0) {
            cout << st.size() << endl;
            t *= 10;
        }
    }


    return 0;
}
