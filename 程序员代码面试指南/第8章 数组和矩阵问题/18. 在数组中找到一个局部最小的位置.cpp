#include <iostream>
using namespace std;

int getLocalMin(int *arr, int n) {
	int left = 0;
	int right = n - 1;
	int mid;

	while (left < right) { // 二分来找
		if (arr[left] < arr[left+1]) {
			return left;
		}
		if (arr[right - 1] > arr[right]) {
			return right;
		}
		mid = left + ((right - left) >> 1);

		if (arr[mid - 1] < arr[mid]) {
			right = mid - 1;
		}
		else if (arr[mid + 1] < arr[mid]) {
			left = mid + 1;
		}
		else {
			return mid;
		}
	}
	return left;
}

int main()
{
	int n, t;
	cin >> n;
	int* arr = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cout << getLocalMin(arr, n) << endl;

	delete[]arr;	
	return 0;
}