#include<iostream>
#include<vector>
 
using namespace std;
 
long getBucket(long num, long n, long max, long min) {
    return (long) ((num-min)*(n)/(max-min));
}
 
int main() {
    long n;
    cin >> n;
 
    long *arr = new long[n];
    long *buckets = new long [n+1];
    bool *hasValue = new bool[n + 1];
    long *mins = new long[n + 1];
    long *maxs = new long[n + 1];
     
    cin >> arr[0];
    long min = arr[0], max = arr[0];
 
    for (long i = 1; i < n; i++) {
        cin >> arr[i];
        if (min > arr[i]) {
            min = arr[i];
        }
        if (max < arr[i]) {
            max = arr[i];
        }
        hasValue[i] = false;
    }
 
    if (max==min) {
        cout << 0 << endl;
    }
    else {
        long maxGap = 0;
        for (long i = 0; i < n; i++) {
            long bid = getBucket(arr[i], n, max, min);
            if (hasValue[bid]) {
                mins[bid] = mins[bid] > arr[i] ? arr[i] : mins[bid];
                maxs[bid] = maxs[bid] < arr[i] ? arr[i] : maxs[bid];
            }
            else {
                hasValue[bid] = true;
                mins[bid] = maxs[bid] = arr[i];
            }
        }
        long lastMax = maxs[0];
        long temp;
        for (long i = 1; i <= n; i++) {
            if (hasValue[i]) {
                temp = mins[i]-lastMax;
                maxGap = maxGap < temp ? temp : maxGap;
                lastMax = maxs[i];
            }      
        }
        cout << maxGap << endl;
    }  
 
    delete[]arr, buckets, hasValue, mins, maxs;
 
    return 0;
}
