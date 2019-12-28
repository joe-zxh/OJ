#include <iostream>
#include <algorithm>
using namespace std;
 
const long modNum = 1000000007;
 
// 一共N个位置，记为1~N
// 一开始在M位置，走K步，到达P位置的 方法的个数
long PsDP(long N, long M, long K, long P) {
 
    long *thisRow = new long[N], *lastRow = new long[N];
 
    for (int i = 0; i < N; i++) { // 初始化第一行
        lastRow[i] = i==P? 1 : 0;
    }
    long *lr = lastRow, *tr = thisRow;
    long *temp;
 
    for (int i = 1; i <= K; i++) {
        for (int j = 0; j < N; j++) {
            if (j == 0) {
                tr[j] = lr[1];
            }
            else if (j == N - 1) {
                tr[j] = lr[N-2];
            }
            else {
                tr[j] = lr[j + 1] + lr[j-1];
                if (tr[j] >= modNum) {
                    tr[j] = tr[j] % modNum;
                }
            }
        }
        temp = lr;
        lr = tr;
        tr = temp;
    }
     
    long res = lr[M];
    delete[]thisRow, lastRow;
    return res;
}
 
// 一共N个位置，记为1~N
// 一开始在M位置，走K步，到达P位置的 方法的个数
long Ps(long N, long M, long K, long P) {
 
    if (K==0) {
        return M == P ? 1 : 0;
    }
 
    if (M == 0) {
        return Ps(N, 1, K-1, P);
    }
    else if (M == N-1) {
        return Ps(N, N-2, K-1, P);
    }
    else {
        long res = Ps(N, M + 1, K - 1, P) + Ps(N, M - 1, K - 1, P);
        return res >= modNum ? res%modNum : res;
    }
}
 
int main()
{
    long N, M, K, P;
    cin >> N >> M >> K >> P;
    cout << PsDP(N, M-1, K, P-1) << endl;
    return 0;
}
