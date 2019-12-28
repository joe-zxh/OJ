#include <iostream>
#include <algorithm>

using namespace std;

long balloonDP(long* arr, long n) { // 记得要在arr左右2端补充1, n是数组扩充后的大小
	long dp[502][502] = {};

	for (long i = 1; i <= n-2; i++) {
		dp[i][i] = arr[i] * arr[i - 1] * arr[i + 1];
	}

	long temp = 0;

	for (long L = n - 2; L >= 1; L--) { // 从下往上，从左往右
		for (long R = L + 1; R <= n - 2; R++) {
			for (long i = L; i <= R; i++) {
				temp = 0;
				if (i != L) {
					temp += dp[L][i-1];
				}
				if (i != R) {
					temp += dp[i+1][R];
				}
				temp += arr[i] * arr[L - 1] * arr[R + 1];
				dp[L][R] = max(dp[L][R], temp);
			}
		}
	}
	return dp[1][n - 2];
}

int main() {
	long n;
	cin >> n;
	long* arr = new long[n+2];

	arr[0] = 1; arr[n + 1] = 1;

	for (long i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	
	cout << balloonDP(arr, n + 2) << endl;

	delete[]arr;
	return 0;
}