#include<iostream>
#include<queue>
 
using namespace std;
 
struct cmp {
    bool operator() (const long &a, const long &b)  {
        return a > b;
    } 
};
 
int main() {   
    priority_queue<long, vector<long>,  cmp> minHeap;
 
    long n, num;
    cin >> n;
    for (long i = 0; i < n;i++) {
        cin >> num;
        minHeap.push(num);
    }
 
    if (n == 1) {
        cout << num << endl;
    }
    else {
        long price = 0;
        long temp;
        while (minHeap.size()>1) {
            temp = minHeap.top();
            minHeap.pop();
            temp += minHeap.top();
            minHeap.pop();
            price += temp;
            minHeap.push(temp);
        }
        cout << price << endl;
    }
    return 0;
}
