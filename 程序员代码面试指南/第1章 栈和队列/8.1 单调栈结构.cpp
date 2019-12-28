#include <iostream>
#include <stack>
using namespace std;

void monoStack(long *arr, long n) {
	stack <long> mst; // 压的是位置
	pair<long, long> *lr = new pair<long, long> [n];
	long t1, t2;
	for (long i = 0; i < n; i++) {
		if (mst.empty()) {
			mst.push(i);
		}
		else {
			t1 = mst.top();
			long right = i;
			while (arr[t1] > arr[i]) {
				mst.pop();
				lr[t1].second = i;
				
				if (!mst.empty()) {
					t2 = mst.top();
					lr[t1].first = t2;
					t1 = t2;
				}
				else {
					lr[t1].first = -1;
					break;
				}				
			}
			mst.push(i);
		}
	}

	while (!mst.empty()) {
		t1 = mst.top();
		mst.pop();
		lr[t1].second = -1;
		if (mst.empty()) {
			lr[t1].first = -1;
		}
		else {
			lr[t1].first = mst.top();
		}
	}

	for (long i = 0; i < n; i++) {
		printf("%d %d\n", lr[i].first, lr[i].second);
	}
	delete[]lr;
}

int main() {
	long n;
	cin >> n;
	long* arr = new long[n];

	for (long i = 0; i < n; i++) {
		cin >> arr[i];
	}
	monoStack(arr, n);
	
	delete[]arr;
	return 0;
}