#include<iostream>
 
using namespace std;
 
int main() {
    long n, num;
    cin >> n;
 
    long bucket[3] = {0};
 
    for (int i = 0; i < n;i++) {
        cin >> num;
        bucket[num]++;
    }
 
    for (int i = 0; i < 3; i++) {
        while (bucket[i]--) {
            cout << i <<" ";
        }
    }
    return 0;
}