#include <iostream>
using namespace std;
 
int main()
{
    long n, m;
    cin >> n >> m;
     
    long newNum = 1; // 最后幸存的人的新编号为1
    for (long i = 2; i <= n; i++) { // 还剩2个人的时候
        long B = (m - 1) % i + 1;// 编号为B的人 报了m这个数
        newNum = (newNum <= i - B) ? B + newNum : newNum - i + B; // 计算旧编号
    }
    cout << newNum << endl;
    return 0;
}
