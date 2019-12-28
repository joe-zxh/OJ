# include <iostream>
using namespace std;
 
long n, root, temp;
 
long getHeight(long root, long *lcs, long *rcs) {
    if (root == 0) {
        return 0;
    }
 
    if (lcs[root]==0&&rcs[root]==0) {
        return 1;
    }
     
    long lh = getHeight(lcs[root], lcs, rcs);
    long rh = getHeight(rcs[root], lcs, rcs);
 
    if (lh==-1||rh==-1||abs(lh-rh)>1) { // 非平衡树
        return -1;
    }
 
    return lh > rh ? lh + 1 : rh + 1;
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
 
    long h = getHeight(root, lcs, rcs);
    if (h>0) {
        printf("true\n");
    }
    else {
        printf("false\n");
    }
 
    delete[]lcs, rcs;
    return 0;
}