#include<iostream>
#include<queue>
 
using namespace std;
 
struct cmpMin {
    bool operator() (const long &a, const long &b) {
        return a > b;
    }
};
 
int main() {   
    priority_queue<long, vector<long>, cmpMin> minHeap;
    priority_queue<long> maxHeap;
     
    long q;
    long opt,temp;
 
    cin >> q;
 
    while (q--) {
        cin >> opt;
        if (opt ==1 ) {
            cin >> temp;
            if (minHeap.empty()) {
                minHeap.push(temp);
            }
            else if (!maxHeap.empty() && maxHeap.top()>temp) {
                maxHeap.push(temp);
                if (minHeap.size() < maxHeap.size()) {
                    minHeap.push(maxHeap.top());
                    maxHeap.pop();
                }
            }
            else {
                minHeap.push(temp);
                if (minHeap.size() - 1 > maxHeap.size()) {
                    maxHeap.push(minHeap.top());
                    minHeap.pop();
                }
            }          
        }
        else {
            if (minHeap.empty() && maxHeap.empty()) {
                cout << -1 << endl;
            }
            else if (minHeap.size() == maxHeap.size()) {
                printf("%0.1f\n", double (minHeap.top() + maxHeap.top()) / double(2));
            }
            else    {
                printf("%0.1f\n", (double)minHeap.top());
            }
        }
    }
    return 0;
}