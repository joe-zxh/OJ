#include <iostream>
using namespace std;
 
int main()
{
    long maxLen = 0, L = 0, R = 0;
    long N, k, temp;
    cin >> N >> k;
    long *arr = new long[N];
     
 
    for (long i = 0; i < N; i++) {
        cin >> arr[i];
    }
 
    long curSum = arr[0];
    while (R < N) {
        if (curSum == k) {
            temp = R - L + 1;
            maxLen = temp > maxLen ? temp : maxLen;
            curSum -= arr[L++];
        }
        else if (curSum < k) {
            R++;
            curSum += arr[R];
        }
        else {
            curSum -= arr[L++];
        }
    }
 
    cout << maxLen << endl;
    delete[]arr;
    return 0;
}