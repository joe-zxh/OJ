#include <iostream>
using namespace std;

int minRotatedArray(int* arr, int n) {
	int left = 0;
	int right = n - 1;
	int mid;
	while (left < right) {
		if (left + 1 == right) {
			return arr[left] < arr[right] ? arr[left] : arr[right];
		}

		if (arr[left] < arr[right]) { // left...right之间无断点，且递增
			return arr[left];
		}
		mid = left + ((right - left) > 1);

		if (arr[left] > arr[mid]) { // left...mid之间有断点
			right = mid;
		}
		else if (arr[mid] > arr[right]) { // mid...right之间有断点
			left = mid;
		}
		else { // left>=right && left<=mid && mid<=right，即left=mid=right
			for (int i = left; i < mid; i++) {
				if (arr[i] > arr[left]) { // 1 2 1 1 1  断点在右侧
					left = i;
					right = mid;
					break;
				}
				else if (arr[i] < arr[left]) { // 2 1 2 2 2  第一个递减的位置就是断点
					return arr[i];
				}
			}
			left = mid; // 2 2 2 1 2  断点在右侧
		}
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	int* arr = new int[n];

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	
	printf("%d\n", minRotatedArray(arr, n));	
	delete[]arr;	
	return 0;
}