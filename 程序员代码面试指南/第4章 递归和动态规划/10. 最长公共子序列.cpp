#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int **dp; // dp[i][j]表示str1[0...i]和str2[0...j]的最长公共子序列的长度

void longestCommonSubseq(string str1, string str2) {
	int sz1 = str1.size();
	int sz2 = str2.size();

	// 填写第一行
	dp[0][0] = str1[0] == str2[0] ? 1 : 0;
	for (int j = 1; j < sz2; j++) {
		dp[0][j] = str1[0] == str2[j] ? 1 : dp[0][j - 1];
	}

	// 填写第一列
	for (int i = 1; i < sz1; i++) {
		dp[i][0] = str1[i] == str2[0] ? 1 : dp[i-1][0];
	}

	// 从上往下，从左往右 填写dp表
	for (int i = 1; i < sz1; i++) {
		for (int j = 1; j < sz2; j++) {
			if (str1[i] == str2[j]) {
				dp[i][j] = 1 + dp[i-1][j-1];
			}
			else {
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}

	// 回溯dp表
	string res = "";
	int i = sz1 - 1, j = sz2 - 1;
	while (i >= 0 && j >= 0) {
		if (str1[i] == str2[j]) {
			res = str1[i] + res;
			i--; j--;
		}
		else {
			if (i > 0 && dp[i - 1][j] == dp[i][j]) {
				i--;
			}
			else {
				j--;
			}
		}
	}
	cout << res << endl;
}

int main() {
	string str1, str2;
	cin >> str1 >> str2;
	
	int sz1 = str1.size();
	int sz2 = str2.size();

	dp = new int*[sz1];
	for (int i = 0; i < sz1; i++) {
		dp[i] = new int[sz2];
	}
	
	longestCommonSubseq(str1, str2);
	
	for (int i = 0; i < sz1; i++) {
		delete []dp[i];
	}
	delete []dp;
	return 0;
}