#include<iostream>
#include <stack>
#include<string>
#include<algorithm>
#include<cmath>
 
using namespace std;
 
int main() {
    stack<int> data, minRecord;
    int minCur = 2147483647;
    int n, num;
    string strInput;
    cin >> n;
 
    while (n--) {
        cin >> strInput;
 
        if (strInput == "push") {
            cin >> num;
 
            if (minRecord.empty()) {
                minCur = num;
            }
            data.push(num);
            minCur = min(minCur, num);
            minRecord.push(minCur);
        }
        else if (strInput=="pop") {
            data.pop();
            minRecord.pop();
 
            if (!minRecord.empty()) {
                minCur = minRecord.top();
            }          
        }
        else if (strInput == "getMin") {
            cout<<minRecord.top()<<endl;
        }
    }
    return 0;
}