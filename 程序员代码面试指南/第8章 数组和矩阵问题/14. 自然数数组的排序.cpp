#include <iostream>
using namespace std;

void NatureSort(int *arr, int n) {
	int t = 0;
	int i = 0;
	while (i < n) {
		if (arr[i] != i + 1) { // 循环怼下标即可。
			t = arr[arr[i] - 1];
			arr[arr[i] - 1] = arr[i];
			arr[i] = t;
		}
		else {
			i++;
		}
	}
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
}

int main()
{
	int n, t;
	cin >> n;
	int* arr = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	NatureSort(arr, n);

	delete[]arr;	
	return 0;
}