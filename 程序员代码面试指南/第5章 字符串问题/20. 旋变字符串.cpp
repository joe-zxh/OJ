#include <iostream>
#include <algorithm>

using namespace std;

bool isValid(string str1, string str2) {
	// todo: 检查字符数量、种类 是否相等
	return str1.size()==str2.size();
}

bool isRotateRecur(string str1, string str2, long SL1, long SL2, long size) {
	if (size == 0) {
		cout << "Fuck" << endl;
		return true;
	}
	
	if (size==1) {
		return str1[SL1] == str2[SL2];
	}

	for (long i = SL1 + 1; i <= SL1 + size - 1; i++) {
		if (isRotateRecur(str1, str2, SL1, SL2, i - SL1) &&
			isRotateRecur(str1, str2, i, SL2 + i - SL1, size - i + SL1)) {
			return true;
		}

		if (isRotateRecur(str1, str2, SL1, SL2 + size - i + SL1, i - SL1) &&
			isRotateRecur(str1, str2, i, SL2, size - i + SL1)) {
			return true;
		}
	}

	return false;
}

bool isRotateDP(string str1, string str2) {
	if (str1.size() != str2.size()) {
		return false;
	}
	long sz = str1.size();

	bool dp[101][101][101] = {}; // 第1维: size(从1开始)

	// 填写size=1的表
	for (long SL1 = 0; SL1 <= sz - 1; SL1++) {
		for (long SL2 = 0; SL2 <= sz - 1; SL2++) {
			dp[1][SL1][SL2] = str1[SL1] == str2[SL2];
		}
	}

	for (long size = 2; size <= sz; size++) {
		for (long SL1 = 0; SL1 <= sz - size; SL1++) {
			for (long SL2 = 0; SL2 <= sz - size; SL2++) {

				for (long i = SL1 + 1; i <= SL1 + size - 1; i++) {
					if (dp[i-SL1][SL1][SL2] && dp[size-i+SL1][i][SL2 + i - SL1]) {
						dp[size][SL1][SL2] = true;
						break;
					}

					if (dp[i - SL1][SL1][SL2 + size - i + SL1] && dp[size - i + SL1][i][SL2]) {
						dp[size][SL1][SL2] = true;
						break;
					}
				}
			}
		}
	}
	return dp[sz][0][0];
}

int main() {
	string str1, str2;
	cin >> str1 >> str2;
	if (isRotateDP(str1, str2)) {
		printf("YES\n");
	}
	else {
		printf("NO\n");
	}	
	return 0;
}