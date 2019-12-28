#include <iostream>
using namespace std;

void printTuple(int* arr, int n, int k) {
	int L = 0, R = n - 1;
	while (L < R) {
		if (arr[L] + arr[R] == k) {
			if (L == 0 || (arr[L - 1] != arr[L])) {
				printf("%d %d\n", arr[L], arr[R]);
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

int main()
{
	int n, k;
	cin >> n >> k;
	int* arr = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	printTuple(arr, n, k);
	delete[]arr;
	return 0;
}