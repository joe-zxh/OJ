#include <iostream>
using namespace std;

void minJump(int *arr, int n) {

	int jump = 0, cur = 0, next=0;
	for (int i = 0; i < n; i++) {
		if (cur < i) {
			cur = next;
			jump++;
		}
		next = next > arr[i] + i ? next : arr[i] + i;
	}
	cout << jump << endl;
}

int main() {
	int n;
	cin >> n;
	int *arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	minJump(arr, n);

	delete[]arr;
	return 0;
}