#include<iostream>
#include <queue>
#include <string>
 
using namespace std;
long n;
 
void printMatrix(long *matrix, long n) {
    for (long i = 0; i < n; i++) {
        for (long j = 0; j < n; j++) {
            printf("%d ", matrix[i*n + j]);
        }
        printf("\n");
    }
}
 
void rotateMatrix(long *matrix, long ltx, long lty, long rbx, long rby) {
    long i, temp;
 
    long size = rbx - ltx;
    for (i = 0; i < size; i++) {
        temp = matrix[lty*n+ltx + i];
        matrix[lty*n+ltx + i] = matrix[(rby-i)*n+ltx];
        matrix[(rby - i)*n + ltx] = matrix[rby*n+rbx-i];
        matrix[rby*n + rbx-i] = matrix[(lty + i)*n + rbx];
        matrix[(lty + i)*n + rbx] = temp;
    }
}
 
int main() {
    long t, ltx, lty, rbx, rby;
    cin >> n;
 
    t = n*n;
    long *matrix = new long[t];
 
    for (long i = 0; i < t; i++) {
        cin >> matrix[i];
    }
 
    ltx = lty = 0;
    rbx = n - 1;
    rby = n - 1;
     
    while (ltx < rbx&&lty < rby) {
        rotateMatrix(matrix, ltx++, lty++, rbx--, rby--);
    }  
 
    printMatrix(matrix, n);
 
    delete[]matrix;
    return 0;
}
