#include <iostream>
#include <stack>
#include <list>
#include <algorithm>
using namespace std;

long monoStack(long* arr, long n) {
	stack <long> mst; // 压的是位置
	long t1, t2;
	long maxArea = 0;
	for (long i = 0; i < n; i++) {
		if (mst.empty()) {
			mst.push(i);
		}
		else {
			t1 = mst.top();
			long right = i;
			while (arr[t1] >= arr[i]) { // =的时候不用管，总有一个是对的
				mst.pop();

				if (!mst.empty()) {
					t2 = mst.top();
					maxArea = max(maxArea, (i - t2 - 1) * arr[t1]);
					t1 = t2;
				}
				else {
					maxArea = max(maxArea, (i) * arr[t1]);
					break;
				}
			}
			mst.push(i);
		}
	}

	while (!mst.empty()) {
		t1 = mst.top();
		mst.pop();
				
		if (mst.empty()) {
			maxArea = max(maxArea, (n)*arr[t1]);
		}
		else {
			maxArea = max(maxArea, (n-mst.top()-1)*arr[t1]);
		}
	}

	return maxArea;
}
long getMaxArea(long* matrix, long n, long m) {
	long maxArea = monoStack(matrix, m);

	for (long i = 1; i < n; i++) {
		for (long j = 0; j < m; j++) {
			if (matrix[i * m + j] == 1) {
				matrix[i * m + j] = 1 + matrix[(i - 1) * m + j];
			}
		}
		maxArea = max(maxArea, monoStack(matrix + i * m, m));
	}
	return maxArea;
}

int main() {
	long n, m;
	cin >> n >> m;
	long* matrix = new long[n*m];

	for (long i = 0; i < n; i++) {
		for (long j = 0; j < m; j++) {
			cin >> matrix[i * m + j];
		}
	}
	cout << getMaxArea(matrix, n, m) << endl;
	
	delete[]matrix;
	return 0;
}