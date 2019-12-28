#include<iostream>
using namespace std;
 
int *temp;
long sum = 0;
 
void merge(int *arr, int left, int mid, int right) {
    int lp = left, rp = mid + 1;
    int p = 0;
    while (lp <= mid && rp <= right) {
        sum += arr[lp] <= arr[rp] ? arr[lp] * (right - rp + 1) : 0;
        temp[p++] = arr[lp] <= arr[rp] ? arr[lp++] : arr[rp++];
    }
    while (lp <= mid) {
        temp[p++] = arr[lp++];
    }
    while (rp <= right) {
        temp[p++] = arr[rp++];
    }
    for (int i = left, j = 0; i <= right; i++, j++) {
        arr[i] = temp[j];
    }
}
 
void mSort(int *arr, int left, int right) {
    if (left == right) {
        return;
    }
    int mid = left + (right - left) / 2;
 
    mSort(arr, left, mid);
    mSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}
 
int main() {
    int n;
    cin >> n;
    temp = new int[n];
    int *arr = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    mSort(arr, 0, n - 1);
 
    cout << sum << endl;
 
    delete[]temp;
    delete[]arr;
    return 0;
}
