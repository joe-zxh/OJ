#include <iostream>
using namespace std;

const long MAXVAL = -1 ^ (1 << 31);

void minMoneyNum(long *arr, long n, long aim) {

	long *next = new long[aim+1];
	long *cur = new long[aim+1];

	long *t;

	// 设置最后一行（第n行）。
	next[0] = 0;
	for (long j = 1; j <= aim; j++) {
		next[j] = MAXVAL;
	}

	for (long i = n - 1; i >= 0; i--) {
		for (long j = 0; j <= aim; j++) {
			if (j == 0) {
				cur[j] = 0;
			}
			else {
				cur[j] = MAXVAL;
				for (long k = 0; arr[i] * k <= j; k++) {
					if (next[j - arr[i] * k] != MAXVAL) {
						cur[j] = cur[j] > next[j - arr[i] * k] + k ? next[j - arr[i] * k] + k : cur[j];
					}
				}
			}
		}
		t = cur;
		cur = next;
		next = t;
	}
	if (next[aim] == MAXVAL) {
		cout << -1 << endl;
	}
	else {
		cout << next[aim] << endl;
	}
	delete[]cur, next;
}

int main() {
	long n, aim;
	cin >> n >> aim;

	long *arr = new long[n];
	for (long i = 0; i < n; i++) {
		cin >> arr[i];
	}
	minMoneyNum(arr, n, aim);
	return 0;
}