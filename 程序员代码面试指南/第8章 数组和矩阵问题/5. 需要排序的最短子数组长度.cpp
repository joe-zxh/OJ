#include <iostream>
using namespace std;

int needSortLen(int* arr, int n) {
	int curmax = arr[0], curmin = arr[n-1];
	int left, right=-1;

	for (int i = 1; i < n; i++) {
		if (arr[i] < curmax) {
			right = i;
		}
		else {
			curmax = arr[i];
		}
	}

	if (right == -1) {
		return 0;
	}

	for (int i = n - 2; i >= 0; i--) {
		if (arr[i] > curmin) {
			left = i;
		}
		else {
			curmin = arr[i];
		}
	}

	return right - left + 1;
}

int main()
{
	int n;
	cin >> n;
	int* arr = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cout << needSortLen(arr, n) << endl;
	delete[]arr;
	return 0;
}