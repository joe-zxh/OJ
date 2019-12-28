#include<iostream>
#include<list>

using namespace std;

long f(long n) {
	return n==1 ? 1:n * (n + 1) / 2;
}

void getMaxMinNum(long *arr, long n, long num) {

	long L = 0, R = 0, res = 0;
	long curmax = arr[0], curmin = arr[0];

	list<long> maxli; maxli.push_back(0);
	list<long> minli; minli.push_back(0);

	while (R < n) {		
		while (curmax - curmin <= num) { // R右移
			R++;
			if (R == n) {
				break;
			}
			if (maxli.empty()) {
				maxli.push_back(R);
			}
			else {
				while (!maxli.empty()&&arr[maxli.back()]<=arr[R]) {
					maxli.pop_back();
				}
				maxli.push_back(R);
			}
			curmax = arr[maxli.front()];

			if (minli.empty()) {
				minli.push_back(R);
			}
			else {
				while (!minli.empty() && arr[minli.back()] >= arr[R]) {
					minli.pop_back();
				}
				minli.push_back(R);
			}
			curmin = arr[minli.front()];
		}
		
		while (curmax - curmin > num) { // L右移
			// 结算
			res += (R - L);
			if (maxli.front() == L) {
				maxli.pop_front();
				curmax = arr[maxli.front()];
			}
			if (minli.front() == L) {
				minli.pop_front();
				curmin = arr[minli.front()];
			}
			L++;
		}
	}	
	// 结算
	res += f(R - L);
	cout << res;
}

int main() {
	long n, w;
	cin >> n >> w;
	long* arr = new long[n];

	for (long i = 0; i < n; i++) {
		cin >> arr[i];
	}

	getMaxMinNum(arr, n, w);
	return 0;
}