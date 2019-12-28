#include <iostream>
using namespace std;
 
int minInt = 1 << (sizeof(int) * 8-1);
 
bool isPalindrome(int a) {
    if (a == minInt) { return false; }
    if (a < 0) { a = -a; }
 
    int q = 1;
    while (q * 10 < a) {
        q *= 10;
    }
 
    while (a > 0) {
        if (a / q != a % 10) {
            return false;
        }
        a = (a%q)/10;
        q /= 100;
    }
    return true;
}
 
int main()
{
    int a;
    cin >> a;
 
    if (isPalindrome(a)) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
    return 0;
}