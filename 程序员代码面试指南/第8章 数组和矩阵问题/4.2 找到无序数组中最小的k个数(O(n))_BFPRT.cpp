#include <iostream>
#include <map>
#include <algorithm>

using namespace std;
long findminK_BFPRT(long* arr, long n, long k);

pair<long, long> partition(long* arr, long left, long right, long pivot) {
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

void InsertionSort(long* arr, long left, long right) {
	if (left > right) {
		printf("error! left:%d, right:%d\n", left, right);
		return;
	}
	
	if (left == right) {
		return;
	}

	// insertion sort
	for (long i = left + 1; i <= right; i++) {
		for (long j = i; j > left&& arr[j] < arr[j - 1]; j--) {
			swap(arr[j], arr[j - 1]);
		}
	}
}

long getMiddle(long *arr, long left, long right) {
	InsertionSort(arr, left, right);
	return arr[((right-left)>>1)+left];
}

long getPivot_BFPRT(long *arr, long left, long right) {
	long arrayNums = (right - left + 1) / 5; // 5个元素的数组的个数
	arrayNums += (right - left + 1) % 5 == 0 ? 0 : 1;

	long* midArray = new long[arrayNums]; // 这里没有delete，可能会爆内存

	for (long i = 0; i < arrayNums; i++) {
		midArray[i] = getMiddle(arr, left + 5 * i, min(left + 5 * (i + 1) - 1, right));
	}
	return findminK_BFPRT(midArray, arrayNums, arrayNums/2+1);
}

long findminK_BFPRT(long* arr, long n, long k) {
	// 返回第k小的数
	 
	if (n <= 5) {
		InsertionSort(arr, 0, n - 1);
		return arr[k-1];
	}

	long left = 0, right = n - 1;

	while (left <= right) {
		long pivot = getPivot_BFPRT(arr, left, right);
		pair<long, long> res = partition(arr, left, right, pivot);
		if (res.first > k - 1) {
			right = res.first - 1;
		}
		else if (res.second < k - 1) {
			left = res.second + 1;
		}
		else {
			return pivot;
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

	findminK_BFPRT(arr, n, k);

	for (long i = 0; i < k; i++) {
		cout << arr[i] << " ";
	}
	printf("\n");
	delete[]arr;
	return 0;
}