# include <iostream>
using namespace std;
 
long n, root, temp;
 
void pre(long root, long *lcs, long *rcs) {
    printf("%d ", root);
    if (lcs[root] != 0) {
        pre(lcs[root], lcs, rcs);
    }
    if (rcs[root] != 0) {
        pre(rcs[root], lcs, rcs);
    }
}
 
void mid(long root, long *lcs, long *rcs) {
    if (lcs[root] != 0) {
        mid(lcs[root], lcs, rcs);
    }
    printf("%d ", root);
    if (rcs[root] != 0) {
        mid(rcs[root], lcs, rcs);
    }
}
 
void post(long root, long *lcs, long *rcs) {
    if (lcs[root] != 0) {
        post(lcs[root], lcs, rcs);
    }
    if (rcs[root] != 0) {
        post(rcs[root], lcs, rcs);
    }
    printf("%d ", root);
}
 
int main()
{
    cin >> n >> root;
 
    long* lcs = new long[n+1];
    long* rcs = new long[n+1];
 
    for (long i = 1; i <= n; i++) {
        cin >> temp;
        cin >> lcs[temp] >> rcs[temp];
    }
 
    pre(root, lcs, rcs); printf("\n");
    mid(root, lcs, rcs); printf("\n");
    post(root, lcs, rcs); printf("\n");
     
    delete[]lcs, rcs;
    return 0;
}