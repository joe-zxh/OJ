#include<iostream>
using namespace std;

int artistsNum(long* arr, int n, long limit) {
	// 每个画家画画不超过limit时间，至少需要多少个画家？
	int res = 1;
	long cur = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] > limit) {
			return ~(1 << 31);
		}
		if (cur + arr[i] <= limit) {
			cur += arr[i];
		}
		else {
			cur = arr[i];
			res++;
		}
	}
	return res;
}

int main() {
	int N, K;
	cin >> N >> K;
	long minLimit = 0, maxLimit = 0, midLimit, maxv = 0;
	long* arr = new long[N];
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		maxLimit += arr[i];
		maxv = maxv < arr[i] ? arr[i] : maxv;
	}
	if (K >= N) {
		cout << maxv << endl;
		delete[]arr;
		return 0;
	}

	while (minLimit < maxLimit) {
		midLimit = minLimit + ((maxLimit - minLimit) >> 1);
		if (artistsNum(arr, N, midLimit) > K) {
			minLimit = midLimit + 1;
		}
		else {
			maxLimit = midLimit;
		}
	}
	cout << maxLimit << endl;
	delete[]arr;
	return 0;
}