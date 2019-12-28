#include<iostream>
#include<list>

using namespace std;

void getWMax(long *arr, long n, long w) {

	long* res = new long[n - w + 1];

	long L = 0;
	long R = 0;
	list<long> li; // 存放的是index。从尾添加数。头到尾：大到小
	
	for (long R = 0; R < n; R++) {
		if (li.empty()) {
			li.push_back(R);
		}
		else {
			while (!li.empty() && arr[li.back()] < arr[R]) {
				li.pop_back();
			}
			li.push_back(R);
		}

		while (li.front()<R-w+1) {
			li.pop_front();
		}
		
		if (R >= w-1) {
			res[R - w + 1] = li.front();
		}		
	}

	for (long i = 0; i < n - w + 1; i++) {
		printf("%d ", arr[res[i]]);
	}

	delete[]res;
}

int main() {
	long n, w;
	cin >> n >> w;
	long* arr = new long[n];

	for (long i = 0; i < n; i++) {
		cin >> arr[i];
	}

	getWMax(arr, n, w);
	return 0;
}