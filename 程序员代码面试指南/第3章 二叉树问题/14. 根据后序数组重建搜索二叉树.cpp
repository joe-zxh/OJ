#include<iostream>
using namespace std;

bool isBST(int *arr, int left, int right) {
	if (left == right) {
		return true;
	}

	int x = arr[right];
	int fgtxInd = right;//第一个比x大的元素的位置
	int lltxInd = left-1;//最后一个比x小的元素的位置
	// lltxInd+1==fgtxInd 就是对的

	for(int i = left; i<=right;i++){
		if (arr[i] > x) {
			fgtxInd = i;
			break;
		}
	}

	for (int i = right; i >= left; i--) {
		if (arr[i] < x) {
			lltxInd = i;
			break;
		}
	}

	if (lltxInd + 1 != fgtxInd) {
		return false;
	}
	else {
		bool res = true;
		if (fgtxInd != right) {
			res &= isBST(arr, fgtxInd, right-1);
		}
		if (lltxInd != left - 1) {
			res &= isBST(arr, left, lltxInd);
		}
		return res;		
	}
}

int main() {
	int n;
	cin >> n;
	int* arr = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	if (isBST(arr, 0, n - 1)) {
		cout << "true" << endl;
	}
	else {
		cout << "false" << endl;
	}
	return 0;
}