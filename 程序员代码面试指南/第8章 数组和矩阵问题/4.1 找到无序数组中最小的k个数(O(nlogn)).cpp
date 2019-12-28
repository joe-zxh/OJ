#include <iostream>
#include <map>
#include <algorithm>

using namespace std;


pair<long, long> partition(long *arr, long left, long right, long pivot) {
	// 返回=pivot的左边界和右边界

	long lp = left - 1, rp = right + 1;
	long iter = left;
	while (iter < rp) {
		if (arr[iter] < pivot) {
			swap(arr[iter++], arr[++lp]);
		}
		else if (arr[iter] == pivot) {
			iter++;
		}
		else {
			swap(arr[iter], arr[--rp]);
		}
	}

	return pair<long, long>(lp + 1, rp - 1);
}

void findminK(long *arr, long n, long k) {
	
	long left = 0, right = n - 1;
	
	while (left <= right) {
		long pivot = arr[right];
		pair<long, long> res = partition(arr, left, right, pivot);
		if (res.first > k-1) {
			right = res.first - 1;
		}
		else if (res.second < k - 1) {
			left = res.second + 1;
		}
		else {
			for (long i = 0; i < k; i++) {
				printf("%d ", arr[i]);
			}
			printf("\n");
			return;
		}
	}
}

int main() {
	long n, k;
	cin >> n >> k;
	long* arr = new long[n];

	for (long i = 0; i < n; i++) {
		cin >> arr[i];
	}

	findminK(arr, n, k);

	delete[]arr;
	return 0;
}