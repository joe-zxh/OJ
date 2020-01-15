class Solution {
public:
    int* matrixMul(int *A, int *B, int am, int an, int bm, int bn) {
        if (an != bm) {
            cout << "error!" << endl;
            return NULL;
        }
        int *res = new int[am*bn];
        int temp = 0;

        for (int i = 0; i < am; i++) {
            for (int j = 0; j < bn; j++) {
                temp = 0;
                for (int k = 0; k < an; k++) {
                    temp = temp + A[i*an + k] * B[k*bn + j];
                }
                res[i*bn + j] = temp;
            }
        }
        return res;
    }
    
    int Fibonacci(int n) {
        if (n == 0){
            return 0;
        }
        if (n == 1||n==2) {
            return 1;
        }
        n -= 2;

        int *a = new int[4]; a[0] = 1; a[1] = 1; a[2] = 1; a[3] = 0; // a记录 矩阵的2^1次方
        int *b = new int[4]; b[0] = 1; b[1] = 0; b[2] = 0; b[3] = 1; // b记录当前的 幂
        int *x,*y;

        int t;
        while (n > 0) {
            t = n & 1;

            if (t == 1) {
                x = matrixMul(a, b, 2, 2, 2, 2);
                y = b;
                b = x;
                delete[]y;
            }

            x = matrixMul(a, a, 2, 2, 2, 2);
            y = a;
            a = x;
            delete[]y;
            n >>= 1;
        }

        int res = b[0] + b[2];
        delete[]a, b;
        return res;
    }
};