#include <iostream>
#include <map>
 
using namespace std;
 
long maxXorPart(long *arr, long n) {
    map<long, long> m; // key: xor sum, value: postion
 
    m[0]=-1;
 
    long* dp = new long[n]; // dp[i]表示到i位置时的最大 异或划分
    dp[0] = arr[0] == 0 ? 1 : 0;
    long xorCur = arr[0];
    m[xorCur] = 0;
    long p;
    for (long i = 1; i < n; i++) {
        xorCur ^= arr[i];
 
        if (m.find(xorCur) != m.end()) {
            p = m.find(xorCur)->second;
            dp[i] = p == -1 ? 1 : dp[p]+1; // -1说明 现在是 第一个异或和为0的位置
 
            dp[i] = dp[i] > dp[i - 1] ? dp[i] : dp[i - 1];
        }
        else {
            dp[i] = dp[i - 1];
        }
        m[xorCur] = i;
    }
    long res = dp[n - 1];
    delete []dp;
    return res;
}
 
int main() {
    long n;
    cin >> n;
    long* arr = new long[n];
 
    for (long i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << maxXorPart(arr, n) << endl;
     
    delete[]arr;
    return 0;
}
