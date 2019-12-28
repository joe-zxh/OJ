#include <iostream>
#include <string>

using namespace std;

long valid(string str) {	
	long count = 0;
	long sz = str.size();

	long *dp = new long[sz];

	dp[0] = 0;
	if (sz == 1) {
		delete[]dp;
		return 0;
	}

	if (str[0] == '('&&str[1] == ')') {
		dp[1]=2;
	}
	else {
		dp[1] = 0;
	}

	long res = dp[1];

	for (long i = 2; i < sz; i++) {
		if (str[i] == ')'&&i - dp[i - 1] - 1>=0&&str[i - dp[i - 1] - 1] == '(') {
			dp[i] = dp[i - 1] + 2;
			if (i - dp[i - 1] - 2 >= 0) {
				dp[i] += dp[i - dp[i - 1] - 2];
			}
		}
		else {
			dp[i] = 0;
		}
		res = dp[i] > res ? dp[i] : res;
	}
	
	delete[]dp;
	return res;
}

int main() {
	string str;
	cin >> str;
	cout << valid(str) << endl;
	return 0;
}