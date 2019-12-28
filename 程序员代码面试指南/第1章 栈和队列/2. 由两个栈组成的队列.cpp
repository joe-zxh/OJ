#include<iostream>
#include <stack>
#include<string>
 
using namespace std;
 
int main() {
    stack<int> pushStack, popStack;
 
    string s;
    int n, num;
    cin >> n;
 
    while (n--) {
        cin >> s;
        if (s == "add") {
            cin >> num;
            pushStack.push(num);
        }
        else if (s=="poll"){
            if (popStack.empty()) {
                while (!pushStack.empty()) {
                    popStack.push(pushStack.top());
                    pushStack.pop();
                }
                popStack.pop();
            }
            else {
                popStack.pop();
            }
        }
        else {
            if (popStack.empty()) {
                while (!pushStack.empty()) {
                    popStack.push(pushStack.top());
                    pushStack.pop();
                }
            }
            cout << popStack.top() << endl;
        }
    }
    return 0;
}