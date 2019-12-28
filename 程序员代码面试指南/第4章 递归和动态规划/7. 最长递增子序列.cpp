#include <iostream>
#include <algorithm>
using namespace std;
 
void print(int *arr, int *dp, int n) {
    int ind = 0;
    for (int i = 1; i < n; i++) {
        if (dp[i] > dp[ind] || (dp[i] == dp[ind] && arr[i]<arr[ind])) {// 找到最长子序列的末尾
            ind = i;
        }
    }
 
    int sz = dp[ind];
    int len = sz;
    int *res = new int[sz];
    res[--sz] = arr[ind];
 
    for (int i = ind-1; i >= 0;i--) {
        if (dp[i] == dp[ind]-1) { // 最右那个 是最小的
            res[--sz] = arr[i];
            ind = i;
        }
    }
 
    for (int i = 0; i < len; i++) {
        printf("%d ", res[i]);
    }
    delete[]res;
}
 
void longest(int *arr, int n) {
    int R = 0;
    int *end = new int[n];
    int *dp = new int[n];
 
    end[0] = arr[0];
    dp[0] = 1;
 
    int left, right, mid, ind;
 
    for (int i = 1; i < n; i++) {
        left = 0; right = R;
        ind = -1;
        while (left <= right) {
            mid = (left + right) / 2;
            if (arr[i]>end[mid]) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        R = R>left ? R : left;
        end[left] = arr[i];
        dp[i] = left + 1;
    }
    print(arr, dp, n);
}
 
int main()
{
    int n;
    cin >> n;
 
    int *arr = new int[n];
 
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
 
    longest(arr, n);
    system("pause");
    return 0;
}
