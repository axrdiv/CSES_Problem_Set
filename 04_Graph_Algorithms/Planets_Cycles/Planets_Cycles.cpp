#include<iostream>
#include<stack>
using namespace std;
const int maxn = 2e5+5;

int n;
int G[maxn], vis[maxn], st[maxn], top;

void find(int x) {
    top = 0;
    st[top++] = x;
    int a = G[x];
    int b = G[G[x]];
    while(!vis[a] && a != b) {
        st[top++] = a;
        a = G[a];
        b = G[G[b]];
    }
    st[top] = a;

    if(vis[a]) {
        while(top) {
            vis[st[top-1]] = vis[st[top]] + 1;
            --top;
        }
        return;
    }



    top = 0;
    a = x;
    while(a != b) {
        st[top++] = a;
        a = G[a];
        b = G[b];
    }
    st[top] = a;

    b = G[a];
    int length = 1;
    while(a != b) {
        b = G[b];
        length++;
    }

    // for compute mini-length
    b = G[a];
    vis[a] = length;
    while(a != b) {
        vis[b] = length;
        b = G[b];
    }

    while(top) {
        vis[st[top-1]] = vis[st[top]] + 1;
        --top;
    }
}

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> G[i];

    for(int u = 1; u <= n; u++) {
        if(!vis[u]) find(u);
    }


    for(int u = 1; u <= n; u++) {
        cout << vis[u] << (u == n ? "\n" : " ");
    }


    return 0;
}
