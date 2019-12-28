#include <iostream>
using namespace std;
 
void rv(int *arr, int left, int right) {
    int temp;
    while (left < right) {
        temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
        left++; right--;
    }
}
 
void reverseLR(int *arr, int ls, int lr, int rs, int rr) {
    rv(arr, ls, lr);
    rv(arr, rs, rr);
    rv(arr, ls, rr);
}
 
void shuffleInside(int *arr, int ind, int divSize) {
    int start = 1;
    int i, s, temp, to;
    int N = divSize / 2;
    do {
        i = start;
        temp = arr[ind + i - 1];
        do {
            to = (2 * i) % (divSize + 1);
            swap(temp, arr[ind + to - 1]);
            i = to;
        } while (i != start);
        start *= 3;
    } while (start < divSize);
}
 
int shuffleFromInd(int *arr, int ind, int n) { // 从位置ind开始洗牌
    if (ind >= n) { // TM没考虑到ind>n的边界问题。。。傻逼了。。。
        return -1;
    }
    if (ind == n - 1) {
        int t = arr[ind];
        arr[ind] = arr[ind + 1];
        arr[ind + 1] = t;
        return -1;
    }
 
    int curSize = n - ind + 1;
    int divSize;
 
    int a = 1;
    while (3 * a - 1 <= curSize) {
        a *= 3;
    }
 
    divSize = a - 1;
 
    int ls = ind + divSize / 2;
    int lr = ind + (curSize / 2) - 1;
    int rs = lr + 1;
    int rr = lr + divSize / 2;
 
    reverseLR(arr, ls, lr, rs, rr);
 
    shuffleInside(arr, ind, divSize);
    return (ind + divSize);
}
 
void shuffle(int *arr, int n) {
    int ind = 1;
    while (ind != -1) {
        ind = shuffleFromInd(arr, ind, n);
    }
}
 
int main()
{
    int n;
    scanf("%d", &n);
    int *arr = new int[n + 1];
 
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
 
    shuffle(arr, n);
    for (int i = 1; i <= n; i++) {
        cout << arr[i] << " ";
    }
    printf("\n");
    delete[]arr;
 
    system("pause");
    return 0;
}