#include<iostream>
#include <unordered_map>
 
using namespace std;
 
int *nodes;
 
int findRoot(int a) {
    int r = a;
    while (*(nodes+r)!=r) {
        r = *(nodes + r);
    }
 
    int t;
    while (*(nodes + a) != a) {
        t = *(nodes + a);
        *(nodes + a) = r;
        a = t;
    }
    return r;
}
 
void isSameSet(int a, int b) {
    if (findRoot(a) == findRoot(b)) {
        printf("Yes\n");
    }
    else {
        printf("No\n");
    }
}
 
void Union(int a, int b) {
    int ra = findRoot(a);
    int rb = findRoot(b);
 
    if (ra < rb) {
        nodes[rb] = ra;
    }
    else {
        nodes[ra] = rb;
    }
}
 
int main() {   
    int N, M, opt, o1, o2;
    cin >> N >> M;
 
    nodes = new int[N+1];
    for (int i = 1; i <= N; i++) {
        nodes[i] = i;
    }
 
    while (M--) {
        scanf("%d%d%d", &opt, &o1, &o2);
        if (opt == 1) {
            isSameSet(o1, o2);
        }
        else {
            Union(o1, o2);
        }
    }
 
    delete[]nodes;
    return 0;
}
