#include <iostream>
#include <algorithm>
using namespace std;
 
int main()
{
    long N, k;
    cin >> N >> k;
     
    long *arr = new long[N];
    long *sum = new long[N]; // 最小累加和
    long *ends = new long[N]; // 最小累加和的结束位置
 
    for (long i = 0; i < N; i++) {
        cin >> arr[i];
    }
 
    sum[N - 1] = arr[N - 1];
    ends[N - 1] = N - 1;
 
    for (long i = N - 2; i >= 0; i--) {
        if (sum[i + 1] <= 0) {
            sum[i] = arr[i] + sum[i+1];
            ends[i] = ends[i + 1];
        }
        else {
            sum[i] = arr[i];
            ends[i] = i;
        }
    }
 
    long len = 0;
    long R = 0;
    long curSum = 0;
    for (long start = 0; start < N; start++) {
        while (R < N&&curSum + sum[R] <= k) {
            curSum += sum[R];
            R = ends[R] + 1;
        }
        curSum -= (start < R ? arr[start] : 0);
        len = max(len, R-start);
        R = max(R, start+1);
    }
    cout << len << endl;
 
    delete[]arr, sum, ends;
    return 0;
}