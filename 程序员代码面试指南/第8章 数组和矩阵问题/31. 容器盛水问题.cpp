#include <iostream>
using namespace std;

void waterVol(long *arr, long n) {
	if (n < 3) {
		cout << 0 << endl;
		return;
	}
	
	long leftMax = arr[0];
	long rightMax = arr[n-1];

	long lp = 1, rp = n - 2;
	long sum = 0;
	while (lp<=rp) {
		if (arr[lp] >= leftMax) {
			leftMax = arr[lp++];
		}
		else if (arr[rp] >= rightMax) {
			rightMax = arr[rp--];
		}
		else if (leftMax <= rightMax) { // 小的那边做结算
			sum += (leftMax - arr[lp++]);
		}
		else {
			sum += (rightMax-arr[rp--]);
		}
	}
	cout << sum << endl;
}

int main() {
	long n;
	cin >> n;
	long *arr = new long[n];
	for (long i = 0; i < n; i++) {
		cin >> arr[i];
	}
	waterVol(arr, n);

	delete[]arr;
	return 0;
}