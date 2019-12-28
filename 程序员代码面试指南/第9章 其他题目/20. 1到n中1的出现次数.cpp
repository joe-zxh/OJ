#include <iostream>
using namespace std;
 
long f(long n) {
    if (n < 1) {
        return 0;
    }
    if (n < 10) {
        return 1;
    }
    long mod = 10;
    long ans = 0;
 
    long k = 2; // 位数
    while (n / mod >= 10) {
        mod *= 10;
        k++;
    }
    ans += n / mod == 1 ? n%mod + 1 : mod; // 区分最高位是否为1
    ans += (k - 1)*(n / mod)*(mod / 10);
    return ans + f(n%mod);
}
 
int main() {
    long n;
    cin >> n;
    cout << f(n) << endl;
    return 0;
}
