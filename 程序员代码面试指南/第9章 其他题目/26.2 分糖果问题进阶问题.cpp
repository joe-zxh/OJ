#include<iostream>

using namespace std;

int main() {

	int n;
	cin >> n;
	int* arr = new int[n];
	int* left = new int[n];
	int* right = new int[n];

	left[0] = 1; right[n - 1] = 1;
	cin >> arr[0];
	for (int i = 1; i < n; i++) {
		cin >> arr[i];
		if (arr[i - 1] < arr[i]) {
			left[i] = left[i - 1] + 1;
		}
		else if (arr[i - 1] == arr[i]) {
			left[i] = left[i - 1];
		}
		else {
			left[i] = 1;
		}
	}

	for (int i = n - 2; i >= 0; i--) {
		if (arr[i+1] < arr[i]) {
			right[i] = right[i + 1] + 1;
		}
		else if (arr[i + 1] == arr[i]) {
			right[i] = right[i + 1];
		}
		else {
			right[i] = 1;
		}
	}
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += (left[i] < right[i] ? right[i] : left[i]);
	}

	printf("%d\n", sum);
	delete[]arr, left, right;
	return 0;
}
