#include <iostream>
using namespace std;

void printTuple2(int* arr, int n, int from, int k) {
	int L = from+1, R = n - 1;
	while (L < R) {
		if (arr[L] + arr[R] == k) {
			if (L == from || (arr[L - 1] != arr[L])) {
				printf("%d %d %d\n", arr[from], arr[L], arr[R]);
			}
			L++; R--;
		}
		else if (arr[L] + arr[R] > k) {
			R--;
		}
		else {
			L++;
		}
	}
}

void printTriple(int* arr, int n, int k) {
	for (int i = 0; i <= n-3; i++) {
		if (i == 0 || (arr[i - 1] != arr[i])) {
			printTuple2(arr, n, i, k - arr[i]);
		}
	}
}

int main()
{
	int n, k;
	cin >> n >> k;
	int* arr = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	printTriple(arr, n, k);
	delete[]arr;
	return 0;
}