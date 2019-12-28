#include<iostream>
using namespace std;

const long M = 1e9 + 7;

long power2(int n) { // 快速求2的次方。
	long res = 1;
	long cmi = 2;

	while (n>0) {
		res = n & 1 ? (res * cmi)%M : res;
		n >>= 1;
		cmi = (cmi*cmi)%M;
	}
	return res;
}

// 要改成非递归的才行
long Hanoi2(int* arr, int n, int from, int other, int to) {
	int i = n - 1;
	int res = 0, tmp;
	while (i >= 0) {
		if (arr[i] != from && arr[i] != to) {
			return -1;//不是最优的轨迹过程
		}

		if (arr[i] == from) {
			tmp = to;
			to = other;
			other = tmp;
			i--;
		}
		else {
			tmp = from;
			from = other;
			other = tmp;
			res = (res + power2(i)) % M;
			i--;
		}
	}
	return res;
}

long Hanoi(int* arr, int n, int i, int from, int other, int to) {
	if (i < 0) {
		return 0;
	}

	if (arr[i] != from && arr[i] != to) {
		return -1;//不是最优的轨迹过程
	}

	if (arr[i] == from) {
		return Hanoi(arr, n, i - 1, from, to, other);
	}
	else {
		long rest = Hanoi(arr, n, i - 1, other, from, to);
		if (rest == -1) {
			return -1;
		}
		long t = 1;
		for (int j = 0; j < i; j++) {
			t = (t << 1) % M;
		}
		return (rest + t) % M;
	}
}

int main() {
	int n,t;
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cout << Hanoi2(arr, n, 1, 2, 3);
	return 0;
}
