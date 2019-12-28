#include <iostream>
using namespace std;

long findUpMid(long *arr1, long *arr2, long s1, long s2, long len) {
	if (len == 1) {
		return arr1[s1] < arr2[s2] ? arr1[s1] : arr2[s2];
	}

	long ind1 = s1 + (len - 1) / 2;
	long ind2 = s2 + (len - 1) / 2;

	if (arr1[ind1] == arr2[ind2]) {
		return arr1[ind1];
	}	

	if (len % 2 == 0) { // 偶数
		if (arr1[ind1] > arr2[ind2]) {
			return findUpMid(arr1, arr2, s1, ind2+1, len / 2);
		}
		else {
			return findUpMid(arr1, arr2, ind1 + 1, s2, len / 2);
		}
	}
	else { // 奇数
		if (arr1[ind1] > arr2[ind2]) {
			if (arr2[ind2] >= arr1[ind1 - 1]) { // 手动去掉一个数
				return arr2[ind2];
			}
			else {
				return findUpMid(arr1, arr2, s1, ind2+1, len/2);
			}
		}
		else {
			if (arr1[ind1] >= arr2[ind2 - 1]) {// 手动去掉一个数
				return arr1[ind1];
			}
			else {
				return findUpMid(arr1, arr2, ind1 + 1, s2, len / 2);
			}
		}
	}
}

int main() {
	long n;
	cin >> n;
	long *arr1 = new long[n];
	long *arr2 = new long[n];

	for (long i = 0; i < n; i++) {
		cin >> arr1[i];
	}

	for (long i = 0; i < n; i++) {
		cin >> arr2[i];
	}
	cout << findUpMid(arr1, arr2, 0, 0, n) << endl;

	delete[]arr1, arr2;
	return 0;
}