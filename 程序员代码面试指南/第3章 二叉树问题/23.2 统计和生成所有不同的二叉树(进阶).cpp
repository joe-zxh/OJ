// 打印发现答案就是 卡特兰数 fdp(n) = C(2n, n)/(n+1)
// 因为要对结果求模，而组合数需要用到除法，需要用 逆元 转化成乘法来求：
// (a/b)%M = a*(b的逆元)%M
// b关于模数M的逆元=(M - M / b) * inv[M % b] % M;

#include <iostream>
using namespace std;
const long M = 1e9 + 7;

long fdp(long n) {
    if (n < 2) {
        return n;
    }
    
    long* inv = new long[n+2];

    inv[1] = 1;

    for (int i = 2; i < n + 2; i++) { // 线性求逆元: https://blog.csdn.net/xiaoming_p/article/details/79644386
        inv[i] = (M - M / i) * inv[M % i] % M;
    }

    long res = 1;
    long m = n * 2;
    for (int i = 0; i < n; i++) { // 求卡特兰数
        res = (m - i) * inv[i + 1] % M * res % M;
    }

    res = res * inv[n + 1] % M;
    delete []inv;
    return res;
}

int main()
{
    long n;
    cin >> n;
    cout << fdp(n) << endl;
    return 0;
}