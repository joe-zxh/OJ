#include<iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	int* arr = new int[n];
	int times = 0;
	int cand;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (times == 0) {
			cand = arr[i];
			times = 1;
		}
		else if (arr[i] == cand) {
			times++;
		}
		else {
			times--;
		}
	}

	times = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] == cand) {
			times++;
		}
	}
	times >= (n / 2 + 1) ? printf("%d\n", cand) : printf("-1\n");	
	return 0;
}