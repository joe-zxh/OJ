#include<iostream>
using namespace std;

int arr[1000][1000];
int n, m;
void dragon() {
	long* dp = new long[m];
	int t;

	dp[m - 1] = arr[n - 1][m - 1] >= 0 ? 1 : 1 - arr[n - 1][m - 1];
	for (int j = m-2; j >= 0; j--) { // 填写最后一行。
		t = dp[j + 1] - arr[n - 1][j]; // 需要的血数
		dp[j] = t > 0 ? t : 1;
	}

	for (int i = n - 2; i >= 0; i--) {
		t = dp[m - 1] - arr[i][m - 1]; // 需要的血数
		dp[m - 1] = t > 0 ? t : 1;

		for (int j = m - 2; j >= 0; j--) {
			t = dp[j + 1];
			t = t < dp[j] ? t : dp[j];
			t = t - arr[i][j];
			dp[j] = t > 0 ? t : 1;
		}
	}

	cout << dp[0] << endl;
	delete[]dp;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	dragon();		
	return 0;
}
