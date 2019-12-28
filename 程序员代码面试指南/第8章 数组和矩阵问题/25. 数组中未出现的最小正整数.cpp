#include <iostream>
using namespace std;

int minPosUn(int*arr, int n) {
	int res;

	int left = -1;
	int right = n;
	int i = 0, t;
	while (left+1 < right) {
		if (arr[left+1] == left + 2) {
			left++;
		}
		else if(arr[left+1]<left+2 || arr[left+1]>right || arr[arr[left+1]-1]==arr[left+1]) { // 放到垃圾堆
			right--;
			t = arr[left + 1];
			arr[left + 1] = arr[right];
			arr[right] = t;
		}
		else { // 否则交换一下
			t = arr[arr[left + 1] - 1];
			arr[arr[left + 1] - 1] = arr[left + 1];
			arr[left + 1] = t;
		}
	}

	return left+2;
}

int main()
{
	int n, t;
	cin >> n;
	int* arr = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	printf("%d\n", minPosUn(arr, n));

	delete[]arr;	
	return 0;
}