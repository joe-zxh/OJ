#include <iostream>
#include<queue>
using namespace std;
 
long n, root, temp;
 
void pre(long root, long *lcs, long *rcs) {
    printf("%d!", root);
    if (lcs[root] != 0) {
        pre(lcs[root], lcs, rcs);
    }
    else {
        printf("#!");
    }
    if (rcs[root] != 0) {
        pre(rcs[root], lcs, rcs);
    }
    else {
        printf("#!");
    }
}
 
void level(long root, long *lcs, long *rcs) {
    queue<long> q;
    q.push(root);
    long r;
 
    while (!q.empty()) {
        r = q.front();
        q.pop();
        if (r == 0) {
            printf("#!");
        }
        else {
            printf("%d!", r);
            q.push(lcs[r]);
            q.push(rcs[r]);
        }
    }
}
 
int main()
{
    cin >> n >> root;
 
    long* lcs = new long[n + 1];
    long* rcs = new long[n + 1];
 
    for (long i = 1; i <= n; i++) {
        cin >> temp;
        cin >> lcs[temp] >> rcs[temp];
    }
 
    pre(root, lcs, rcs); printf("\n");
    level(root, lcs, rcs);
 
    delete[]lcs, rcs;
    return 0;
}
