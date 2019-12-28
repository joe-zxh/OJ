#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
 
 
long winDP(long *arr, long n) {
    long **first = new long*[n];
    long **second = new long*[n];
    for (long i = 0; i <n; i++) {
        first[i] = new long[n];
        first[i][i] = arr[i];
        second[i] = new long[n];
        second[i][i] = 0;
    }
 
    for (long i = n - 2; i >= 0; i--) {
        for (long j = i + 1; j < n; j++) {
            first[i][j] = max(arr[i] + second[i+1][j], arr[j] + second[i][j-1]);
            second[i][j] = min(first[i + 1][j], first[i][j - 1]);
        }
    }
 
    long res = max(first[0][n - 1], second[0][n - 1]);
 
    for (long i = 0; i < n; i++) {
        delete[]first[i];
        delete[]second[i];
    }
    first = second = NULL;
    return res;
}
 
 
long first(long *arr, long left, long right);
long second(long *arr, long left, long right);
 
long win(long *arr, long n) {
    return max(first(arr, 0, n-1), second(arr, 0, n-1));
}
 
long first(long *arr, long left, long right) { // 先手
 
    if (left == right) {
        return arr[left];
    }
 
    // 先手取了一个数之后，变成后手了
    return max(arr[left]+second(arr, left+1, right), arr[right]+second(arr, left, right-1));
}
 
long second(long *arr, long left, long right) { // 后手
 
    if (left == right) {
        return 0;
    }
 
    // 被动地只能选 较小的那个
    return min(first(arr, left+1, right), first(arr, left, right-1));
}
 
int main()
{
    long n, *arr;
    cin >> n;
    arr = new long[n];
 
    for (long i = 0; i < n; i++) {
        cin >> arr[i];
    }
 
    cout << winDP(arr, n) << endl;
     
    delete[] arr;
    return 0;
}
