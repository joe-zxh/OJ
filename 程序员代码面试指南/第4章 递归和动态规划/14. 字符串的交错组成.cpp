#include<iostream>
#include<string>
using namespace std;

void isCombine(string str1, string str2, string aim) {
	string t;
	if (str1.size() < str2.size()) {
		t = str1;
		str1 = str2;
		str2 = t;
	}

	int sz1 = str1.size();
	int sz2 = str2.size();

	bool* dp = new bool[sz2+1];

	dp[0] = true;
	for (int j = 1; j <= sz2; j++) { // 填写第一行
		dp[j] = str2[j - 1] == aim[j - 1] ? dp[j - 1] : false;
	}

	for (int i = 1; i <= sz1; i++) {
		dp[0] = str1[i - 1] == aim[i - 1] ? dp[0] : false;
		for (int j = 1; j <= sz2; j++) {
			dp[j] = str1[i - 1] == aim[i + j - 1] ? dp[j] : false;
			dp[j] = str2[j - 1] == aim[i + j - 1] ? dp[j] | dp[j - 1] : dp[j];
		}
	}
	if (dp[sz2]) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
	delete[]dp;
}

int main() {
	string a, b, aim;
	cin >> a >> b >> aim;
	isCombine(a, b, aim);
	return 0;
}
