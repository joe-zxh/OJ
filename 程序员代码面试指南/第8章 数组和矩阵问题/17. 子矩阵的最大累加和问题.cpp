#include <iostream>
#include <algorithm>
using namespace std;

long maxSubMatrix(long *matrix, long m, long n) {
	long res = 1 << (sizeof(long) * 8 - 1);
	long *temp = new long[n];

	for (long i = 0; i < m; i++) {
		for (long j = i; j < m; j++) {
			long cur = 0;
			long maxS = 1 << (sizeof(long) * 8 - 1);

			for (long k = 0; k < n; k++) {				
				temp[k] = j>i ?  temp[k] + matrix[j*n + k] : matrix[i*n + k];
				cur += temp[k];
				maxS = max(maxS, cur);
				cur = cur < 0 ? 0 : cur;
			}
			res = max(res, maxS);			
		}
	}
	delete[]temp;
	return res;
}

int main() {
	long m, n;
	cin >> m >> n;
	long *arr = new long[m*n];
	for (long i = 0; i < m; i++) {
		for (long j = 0; j < n; j++) {
			cin >> arr[i*n + j];
		}
	}
	cout << maxSubMatrix(arr, m, n) << endl;
	
	system("pause");
	return 0;
}