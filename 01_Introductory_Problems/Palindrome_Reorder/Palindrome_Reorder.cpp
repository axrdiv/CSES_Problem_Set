#include<cstdio>
using namespace std;
char c;
int cnt[256], len, idx;

bool check() {
    bool flag = 0;
    for(int i = 0; i < 256; i++) {
        if(!(cnt[i] & 1)) continue;
        if(!(len & 1)) return false;
        if(flag) return false;
        flag = 1;
        idx = i;
    }
    return true;
}

int main() {
    while(scanf("%c", &c) != -1 && c != '\n') {
        cnt[(int)c]++;
        len++;
    }

    if(!check()) {
        printf("NO SOLUTION\n");
        return 0;
    }

    for(int i = 0; i < 256; i++) {
        for(int j = 0; j < cnt[i] / 2; j++) {
            printf("%c", i);
        }
    }

    if(len & 1) printf("%c", idx);

    for(int i = 255; i >= 0; i--) {
        for(int j = 0; j < cnt[i] / 2; j++) {
            printf("%c", i);
        }
    }
    printf("\n");

    return 0;
}
