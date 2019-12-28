#include<iostream>

using namespace std;

int dp1[3001][3001];//dp1[i][j]: i到j之间建一个邮局 的最小距离
int dp2[3001][3001];//dp2[i][j]: i+1个邮局，搞定0..j的居民点
int cut[3001][3001];//cut[i][j]: i+1个邮局，搞定0..j的居民点时，第i个邮局搞定的是cut[i][j]...j的居民点

int main() {
	int n, num;
	scanf("%d %d", &n, &num);
	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	for (int i = 0; i < n; i++) {
		dp1[i][0] = 0;
		for (int j = i + 1; j < n; j++) {
			dp1[i][j] = dp1[i][j - 1] + arr[j] - arr[i + (j - i) / 2];
		}
	}

	for (int j = 0; j < n; j++) { // 填写第一行，1个邮局，搞定0..j的居民点
		dp2[0][j] = dp1[0][j];
		cut[0][j] = 0;
	}
	int start, end, t;
	for (int i = 1; i < num; i++) {
		for (int j = n - 1; j > i; j--) {
			start = cut[i - 1][j]; // 四边形不等式 优化枚举过程
			end = j == n - 1 ? n - 1 : cut[i][j + 1];
			dp2[i][j] = ~(1<<31);
			for (int k = start; k <= end; k++) {
				t = dp2[i - 1][k] + dp1[k+1][j];
				if (t <= dp2[i][j]) {
					dp2[i][j] = t;
					cut[i][j] = k;
				}
			}
		}
	}
	cout << dp2[num-1][n - 1] << endl;

	delete[]arr;
	return 0;
}