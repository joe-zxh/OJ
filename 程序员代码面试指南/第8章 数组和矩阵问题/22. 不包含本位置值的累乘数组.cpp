#include<iostream>
using namespace std;

int main() {
	long N, P;
	cin >> N >> P;
	long* arr = new long[N];
	long* ll = new long[N];// 记录的是不包括自己的累乘

	cin >> arr[0];
	ll[0] = 1;

	for (long i = 1; i < N; i++) {
		cin >> arr[i];
		ll[i] = (arr[i - 1] * ll[i - 1]) % P;
	}

	long mfb = 1, temp; // multiply from back
	for (long i = N-1; i >= 0; i--) {
		temp = arr[i];
		arr[i] = (ll[i] * mfb) % P;
		mfb = (mfb * temp) % P;
	}

	for (long i = 0; i < N; i++) {
		printf("%d ", arr[i]);
	}

	return 0;
}