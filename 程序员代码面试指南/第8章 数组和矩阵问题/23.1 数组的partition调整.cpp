#include <iostream>
using namespace std;

void partition(int*arr, int n) {
	int u = 0; // 有效区的右边界
	int i = 1; // 
	int t;

	while (i < n) {
		if (arr[i++] != arr[u]) {
			// swap(u+1, i-1)
			t = arr[u + 1];
			arr[u + 1] = arr[i - 1];
			arr[i - 1] = t;
			u++;
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
	partition(arr, n);

	delete[]arr;	
	return 0;
}