#include <iostream>
using namespace std;

unsigned long const over = 1e9 + 7;

long* matrixMul(long *A, long *B, long am, long an, long bm, long bn) {
	if (an != bm) {
		cout << "error!" << endl;
		return NULL;
	}
	long *res = new long[am*bn];
	long temp = 0;

	for (long i = 0; i < am; i++) {
		for (long j = 0; j < bn; j++) {
			temp = 0;
			for (long k = 0; k < an; k++) {
				temp = (temp + (A[i*an + k] * B[k*bn + j])%over)%over;
			}
			res[i*bn + j] = temp;
		}
	}
	return res;
}

long fibo(unsigned long n) {
	if (n <= 1) {
		return n;
	}
	n -= 3;
	long *a = new long[9];
	a[0] = 1; a[1] = 1; a[2] = 0; // a记录 矩阵的2^1次方
	a[3] = 0; a[4] = 0; a[5] = 1;
	a[6] = 1; a[7] = 0; a[8] = 0;

	long *b = new long[9];
	b[0] = 1; b[1] = 0; b[2] = 0;// b记录当前的 幂
	b[3] = 0; b[4] = 1; b[5] = 0;
	b[6] = 0; b[7] = 0; b[8] = 1;
	
	long *x,*y;

	unsigned long t;
	while (n > 0) {
		t = n & 1;

		if (t == 1) {
			x = matrixMul(a, b, 3,3,3,3);
			y = b;
			b = x;
			delete[]y;
		}
		
		x = matrixMul(a, a, 3, 3, 3, 3);
		y = a;
		a = x;
		delete[]y;
		n >>= 1;
	}

	long res = 3*b[0]+2*b[3]+b[6];
	delete[]a, b;
	return res%over;
}

int main()
{
	long n;
	cin >> n;
	cout << fibo(n) << endl;
	return 0;
}