#include<iostream>
#include<vector>
#include<algorithm>
#include<tuple>
#include<set>

using namespace std;
int n;
vector<tuple<int, int, int> > vec, vecb;
vector<int> vt;
set<int> end_points;

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        vec.push_back(make_tuple(a, -b, i));
        vecb.push_back(make_tuple(-a, b, i));
        vt.push_back(a);
        vt.push_back(b);
    }

    vector<bool> ans1(n, false), ans2(n, false);

    sort(vec.begin(), vec.end());
    sort(vecb.begin(), vecb.end());

    sort(vt.begin(), vt.end());
    auto p = unique(vt.begin(), vt.end());
    vt.erase(p, vt.end());


    end_points.clear();
    for(int i = 0, k = 0; i < vt.size()-1; i++) {
        int now = vt[i];

        if(end_points.find(now) != end_points.end()) {
            end_points.erase(now);
        }

        int a, b, c;
        while(k != n && (tie(a,b,c) = vec[k], a == now)) {
            if(end_points.lower_bound(-b) != end_points.end())
                ans2[c] = true;
            end_points.insert(-b);
            k++;
        }
    }

    end_points.clear();
    for(int i = vt.size()-2, k = 0; i >= 0; i--) {
        int now = vt[i];

        int a, b, c;
        while(k!= n && (tie(a, b, c) = vecb[k], a == -now)) {
            if(end_points.lower_bound(-b) != end_points.end())
                ans1[c] = true;
            end_points.insert(-b);
            k++;
        }
    }

    for(int i = 0; i < n; i++)
        cout << ans1[i] << (i == n-1 ? "\n" : " ");

    for(int i = 0; i < n; i++)
        cout << ans2[i] << (i == n-1 ? "\n" : " ");


    return 0;
}
