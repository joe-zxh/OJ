#include <iostream>
#include <algorithm>
using namespace std;

long maxSub(long *arr, long n) {
	long cur = 0;
	long maxS = 1<<(sizeof(long)*8-1);

	for (long i = 0; i < n; i++) {
		cur += arr[i];
		maxS = max(maxS, cur);

		cur = cur < 0 ? 0 : cur;
	}
	return maxS;
}

int main() {
	long n;
	cin >> n;
	long *arr = new long[n];
	for (long i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cout << maxSub(arr, n) << endl;
	return 0;
}