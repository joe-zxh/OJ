#include <iostream>
using namespace std;

bool binSearch(int* arr, int left, int right, int aim) {
	int mid;
	while (left <= right) {
		mid = left + ((right - left) > 1);
		if (arr[mid] == aim) {
			return true;
		}
		else if (arr[mid] > aim) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	return false;
}

bool isInRotatedArray(int* arr, int n, int aim) {
	int left = 0;
	int right = n - 1;
	int mid;
	while (left < right) {
		if (left + 1 == right) {
			return arr[left] == aim || arr[right] == aim ? true : false;
		}

		mid = left + ((right - left) > 1);

		if (arr[left] < arr[right]) { //  // left...right之间无断点，且递增，直接二分即可。
			return binSearch(arr, left, right, aim);
		}
		
		if (arr[left] > arr[mid]) { // left...mid之间有断点，mid+1...right之间无断点，且递增
			
			if (arr[mid + 1] <= aim && aim <= arr[right]) { // 二分搜索
				return binSearch(arr, mid + 1, right, aim);
			}
			else { // 继续当前过程
				right = mid;
			}

		}
		else if (arr[mid] > arr[right]) { // mid...right之间有断点，left...mid-1之间无断点，且递增

			if (mid - 1 >= left && arr[left] <= aim && aim <= arr[mid - 1]) { // 二分搜索
				return binSearch(arr, left, mid - 1, aim);
			}
			else { // 继续当前过程
				left = mid;
			}			
		}
		else { // left>=right && left<=mid && mid<=right，即left=mid=right
			while (left <= mid&&arr[left]==arr[mid]) { // 找到第一个不相等的值之后，继续当前过程
				left++;
			}
		}
	}
	return false;
}

int main()
{
	int n, aim;
	scanf("%d %d", &n, &aim);
	int* arr = new int[n];

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	
	if (isInRotatedArray(arr, n, aim)) {
		printf("Yes\n");
	}
	else {
		printf("No\n");
	}
	delete[]arr;	
	return 0;
}