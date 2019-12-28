#include <iostream>
#include <algorithm>
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

long getK(long *arr1, long *arr2, long sz1, long sz2, long k) { // 传入参数时，保证sz1<=sz2
	if (k <= sz1) {
		return findUpMid(arr1, arr2, 0, 0, k);
	}

	if (sz1 < k&& k <= sz2) { // 去掉那些不可能的数，再去掉长数组剩余中的第一个数。
		if (arr2[k - sz1 - 1] >= arr1[sz1 - 1]) {
			return arr2[k - sz1 - 1];
		}
		else {
			return findUpMid(arr1, arr2, 0, k - sz1, sz1);
		}
	}

	if (sz2 < k&&k <= sz1 + sz2) { // 去掉那些不可能的数，再去掉2个数。
		if (arr1[k - sz2 - 1] >= arr2[sz2 - 1]) {
			return arr1[k - sz2 - 1];
		}
		if (arr2[k - sz1 - 1] >= arr1[sz1 - 1]) {
			return arr1[k - sz1 - 1];
		}
		return findUpMid(arr1, arr2, k-sz2, k-sz1, sz1+sz2-k);
	}
}

int main() {
	long n, m, k;
	cin >> n >> m >> k;
	long *arr1 = new long[n];
	long *arr2 = new long[m];

	for (long i = 0; i < n; i++) {
		cin >> arr1[i];
	}

	for (long i = 0; i < m; i++) {
		cin >> arr2[i];
	}
	if (n <= m) {
		cout << getK(arr1, arr2, n, m, k) << endl;
	}
	else {
		cout << getK(arr2, arr1, m, n, k) << endl;
	}

	delete[]arr1, arr2;
	return 0;
}