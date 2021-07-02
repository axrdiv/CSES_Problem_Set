#include<iostream>
using namespace std;
struct child {
    int id = 0;
    child *next = NULL;
};
int n;

int main() {
    cin >> n;
    child head;
    child *p = &head;

    for(int i = 1; i <= n; i++) {
        child *ch = new child;
        ch->id = i;
        p->next = ch;
        p = ch;
    }

    p->next = head.next;
    p = head.next;
    while(n-- && p) {
        cout << p->next->id << (n ? " " : "\n");
        child *tmp = p->next;
        p->next = p->next->next;
        delete tmp;
        p = p->next;
    }

    return 0;
}
