#include <iostream>
#include <string>
using namespace std;

void minSum(int *matrix, int n, int m) {
	int *dp = new int[m];

	// 填写最后一行
	dp[m - 1] = matrix[n*m-1];
	for (int j = m - 2; j >= 0; j--) {
		dp[j] = dp[j + 1] + matrix[(n-1)*m+j];
	}

	// 从下往上，从右往左
	for (int i = n - 2; i >= 0; i--) {
		for (int j = m - 1; j >= 0; j--) {
			if (j == m - 1) { // 最后一列只能往下走
				dp[j] += matrix[i*m+j];
			}
			else {
				dp[j] = matrix[i*m + j] + (dp[j] < dp[j + 1] ? dp[j] : dp[j + 1]);
			}
		}
	}
	cout << dp[0] << endl;
	delete[]dp;
}

int main() {
	int n, m;
	cin >> n >> m;
	int *matrix = new int[n*m];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> matrix[i*m + j];
		}
	}
	minSum(matrix, n, m);
	delete[]matrix;
	return 0;
}