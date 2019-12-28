#include <iostream>
#include <map>
using namespace std;
 
map<long, long> mp; // key: mid[i] value: i
 
void initMp(long *mid, long n) {
    for (long i = 0; i < n; i++) {
        mp[mid[i]] = i;
    }
}
 
void getPost(long *pre, long *mid, long *pos, long n,
    long preleft, long preright, long midleft, long midright, long posleft, long posright) {
 
    if (preleft == preright) {
        pos[posleft] = pre[preleft];
        return;
    }
 
    pos[posright] = pre[preleft];
    long leftsz = mp[pre[preleft]]-midleft;
 
    if (leftsz != 0) { // 有左孩子
        getPost(pre, mid, pos, n, preleft + 1, preleft + leftsz, midleft, midleft + leftsz - 1, posleft, posleft + leftsz - 1);
    }
 
    if (midleft+leftsz != midright) { // 有右孩子
        getPost(pre, mid, pos, n, preleft + leftsz + 1, preright, midleft + leftsz + 1, midright, posleft + leftsz, posright - 1);
    }
}
 
int main() {
    long n;
    cin >> n;
    long* pre = new long[n];
    long* mid = new long[n];
    long* pos = new long[n];
 
    for (long i = 0; i < n; i++) {
        cin >> pre[i];
    }
    for (long i = 0; i < n; i++) {
        cin >> mid[i];
    }
 
    initMp(mid, n);
    getPost(pre, mid, pos, n, 0, n-1, 0, n-1, 0, n-1);
 
    for (long i = 0; i < n; i++) {
        cout << pos[i] << " ";
    }
    return 0;
}