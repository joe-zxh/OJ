#include<iostream>
using namespace std;
 
int main() {   
    int m, n, k;
    cin >> m >> n >> k;
 
    int len = m*n;
    int *matrix = new int [len];
 
    for (int i = 0; i < len;i++) {
        cin >> matrix[i];
    }
 
    int i=0, j=n-1;
    bool isFind = false;
     
    while (i<m && j>=0) {
        if (matrix[i*n + j] == k) {
            isFind = true;
            break;
        }
        else if (matrix[i*n + j] < k) {
            i++;
        }
        else {
            j--;
        }
    }
 
    if (isFind) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
 
    delete[]matrix;
    return 0;
}
