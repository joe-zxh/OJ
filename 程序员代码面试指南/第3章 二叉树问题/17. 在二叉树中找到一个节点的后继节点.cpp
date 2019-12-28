# include <iostream>
using namespace std;
 
long n, root, temp;
 
long getNext(long cur, long *lcs, long *rcs, long *parent) {
     
    if (rcs[cur] != 0) { // 有右孩子，那么找右孩子的最左节点
        long t = rcs[cur];
        while (lcs[t]) {
            t = lcs[t];
        }
        return t;
    }
    else { // 没有右孩子，那么 往上寻找，找到第一个是 某个节点的 左孩子的节点。
        long p = parent[cur];
         
        while (true) {
            if (p == 0) {
                return 0;
            }
            else {
                if (lcs[p] == cur) {
                    return p;
                }
                else {
                    cur = p;
                    p = parent[cur];
                }
            }
        }
    }
}
 
int main()
{
    cin >> n >> root;
 
    long* lcs = new long[n+1];
    long* rcs = new long[n+1];
    long* parent = new long[n + 1];
 
    parent[root] = 0;
 
    for (long i = 1; i <= n; i++) {
        cin >> temp;
        cin >> lcs[temp] >> rcs[temp];
        parent[lcs[temp]] = temp;
        parent[rcs[temp]] = temp;
    }
 
    long q;
    cin >> q;
    printf("%d\n", getNext(q, lcs, rcs, parent));
     
    delete[]lcs, rcs;
    return 0;
}