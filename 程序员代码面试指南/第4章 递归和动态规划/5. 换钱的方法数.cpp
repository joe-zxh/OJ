#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const long modNum = 1000000007;

long methods(long *arr, long ind, long aim, long n) { // 从ind开始，凑aim的钱
	
	if (aim == 0) {
		return 1;
	}

	if (ind > n - 1) {
		return 0;
	}
	
	long res = 0;
	long i = 0;

	while (aim-arr[ind]*i>=0) {
		res += methods(arr, ind + 1, aim - arr[ind] * i, n);
		if (res >= modNum) {
			res %= modNum;
		}
		i++;
	}

	return res;
}

long methods2DDP(long *arr, long aim, long n) { // 从ind开始，凑aim的钱

	long **dp = new long*[n+1];
	for (long i = 0; i <= n + 1; i++) {
		dp[i] = new long[aim+1];
	}

	// vector<vector<long>>dp;

	for (long i = 0; i <= n; i++) { // 设置第一列
		dp[i][0] = 1;
	}

	for (long i = 1; i <= aim; i++) { // 设置最后一行
		dp[n][i] = 0;
	}

	for (long i = n - 1; i >= 0; i--) {
		for (long j = 1; j <= aim; j++) {
			dp[i][j] = 0;
			long ii = 0;
			while (j-arr[i]*ii>=0) {
				dp[i][j] += dp[i+1][j-arr[i]*ii];
				if (dp[i][j] >= modNum) {
					dp[i][j] %= modNum;
				}
				ii++;
			}
		}
	}

	long res = dp[0][aim];

	for (long i = 0; i <= n + 1; i++) {
		delete []dp[i];
	}
	dp=NULL;

	return res;
}

long methods1DDP(long *arr, long aim, long n) { // 从ind开始，凑aim的钱

	long *thisRow = new long[aim + 1];
	long *nextRow = new long[aim + 1];
	
	
	nextRow[0] = 1;// 设置第一列
	thisRow[0] = 1;// 设置第一列
	for (long i = 1; i <= aim; i++) { // 设置最后一行
		nextRow[i] = 0;
	}

	long *tr=thisRow, *nr=nextRow;
	long *temp;

	for (long i = n - 1; i >= 0; i--) {
		for (long j = 1; j <= aim; j++) {
			tr[j] = 0;
			long ii = 0;
			while (j - arr[i] * ii >= 0) {
				tr[j] += nr[j - arr[i] * ii];
				if (tr[j] >= modNum) {
					tr[j] %= modNum;
				}
				ii++;
			}
		}
		temp = tr;
		tr = nr;
		nr = temp;
	}
	
	long res = nr[aim];
	delete[] thisRow, nextRow;
	return res;
}

int main()
{
	long n, aim;
	cin >> n >> aim;
	long *arr = new long[n];

	for (long i = 0; i < n; i++) {
		cin >> arr[i];
	}

	cout << methods1DDP(arr, aim, n)<< endl;
	
	delete[]arr;
	return 0;
}