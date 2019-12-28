#include<iostream>
#include <queue>
#include <string>
 
using namespace std;
long n, m;
void printRing(long *matrix, long ltx, long lty, long rbx, long rby) {
    long i;
 
    if (lty==rby) {
        for (i = ltx; i <= rbx; i++) {
            printf("%d ", matrix[lty*m + i]);
        }
        return;
    }
 
    if (ltx==rbx) {
        for (i = lty; i <= rby;i++) {
            printf("%d ", matrix[i*m + ltx]);
        }
        return;
    }
 
    for (i = ltx; i < rbx; i++) {
        printf("%d ", matrix[lty*m+i]);
    }
 
    for (i = lty; i < rby; i++) {
        printf("%d ", matrix[i*m + rbx]);
    }
 
    for (i = rbx; i > ltx; i--) {
        printf("%d ", matrix[rby*m + i]);
    }
 
    for (i = rby; i > lty; i--) {
        printf("%d ", matrix[i*m + ltx]);
    }
}
 
int main() {
    long t, ltx, lty, rbx, rby;
    cin >> n>>m;
 
    t = n*m;
    long *matrix = new long[t];
 
    for (long i = 0; i < t; i++) {
        cin >> matrix[i];
    }
 
    ltx =lty = 0;
    rbx = m - 1;
    rby = n - 1;
 
    while (ltx<=rbx&&lty<=rby) {
        printRing(matrix, ltx++, lty++, rbx--, rby--);
    }
 
    delete[]matrix;
    return 0;
}
