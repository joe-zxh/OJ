#include <iostream>
using namespace std;

unsigned long const over = 1<<29;

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
				temp = (temp + (A[i*an + k] * B[k*bn + j]) % over) % over;
			}
			res[i*bn + j] = temp;
		}
	}
	return res;
}

long fibo(unsigned long n) {
	if (n == 1) {
		return 1;
	}
	if (n == 2) {
		return 2;
	}
	n -= 2;

	long *a = new long[4]; a[0] = 1; a[1] = 1; a[2] = 1; a[3] = 0; // a记录 矩阵的2^1次方
	long *b = new long[4]; b[0] = 1; b[1] = 0; b[2] = 0; b[3] = 1; // b记录当前的 幂
	long *x, *y;

	unsigned long t;
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

	long res = ((2 * (b[0] % over)) % over + b[2]) % over;
	delete[]a, b;
	return res;
}

int main()
{
	long n;
	cin >> n;
	cout << fibo(n) << endl;
	return 0;
}