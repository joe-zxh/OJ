#include<iostream>
 
using namespace std;
long n, m;
 
void printZ(long *matrix, long lbx, long lby, long rtx, long rty, long n, long m, bool goUp) {
    long x, y; 
    if (goUp) {
        x = lbx;
        y = lby;
 
        while (x<=rtx && y>=rty) {
            printf("%d ", matrix[y*m+x]);
            x++; y--;
        }
    }
    else {
        x = rtx;
        y = rty;
 
        while (x>=lbx && y<=lby) {
            printf("%d ", matrix[y*m + x]);
            x--; y++;
        }
    }
}
 
int main() {
    long t, lbx, lby, rtx, rty;
    bool goUp = true;
    cin >> n>>m;
 
    t = n*m;
    long *matrix = new long[t];
 
    for (long i = 0; i < t; i++) {
        cin >> matrix[i];
    }
 
    lbx = lby = rtx = rty = 0;
     
    while (true) {
        printZ(matrix, lbx, lby, rtx, rty, n, m, goUp);
 
        if (rtx < m-1) {
            rtx++;
        }
        else if (rtx == m-1){
            rty++;
        }
 
        if (lby<n-1) {
            lby++;
        }
        else if (lby == n - 1) {
            lbx++;
        }
 
        if (lbx == rtx&&lby == rty) {
            printf("%d\n", matrix[lby*m+lbx]);
            break;
        }
 
        goUp = !goUp;
    }  
 
    delete[]matrix;
    return 0;
}
