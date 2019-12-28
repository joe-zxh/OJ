#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool * isValid;

void setIsValid(string str) {
	long sz = str.size();
	for (long i = 0; i < sz; i++) {
		isValid[i*sz + i] = true;
		if (i != sz - 1) {
			isValid[i*sz + i + 1] = str[i] == str[i + 1];
		}		
	}
	for (long i = sz - 3; i >= 0; i--) {
		for (long j = i + 2; j < sz; j++) {
			isValid[i*sz + j] = str[i] == str[j] && isValid[(i + 1)*sz + j - 1];
		}
	}
}

bool getIsValid(long i, long j, long sz) {
	return isValid[i*sz+j];
}

long numofPa(string str, long i) { // 从i位置开始，到end位置的回文子串的个数。
	long sz = str.size();
	long res = sz - i;

	if (i == sz - 1) {
		return 1;
	}

	if (i > sz - 1) {
		return 0;
	}

	for (long j = i; j < sz; j++) {
		if (getIsValid(i, j, sz)) {
			res = min(res, 1+numofPa(str, j+1));
		}
	}
	return res;
}

long numofPaDP(string str) {
	long sz = str.size();
	long *dp = new long[sz+1];
	dp[sz - 1] = 1; dp[sz] = 0;

	for (long i = sz - 2; i >= 0; i--) {
		dp[i] = sz - i;
		for (long j = i; j < sz; j++) {
			if (getIsValid(i, j, sz)) {
				dp[i] = min(dp[i], 1 + dp[j+1]);
			}
		}
	}
	return dp[0];
}

int main()
{
	string str;
	long sz;
	cin >> str;
	sz = str.length();
	isValid = new bool[sz*sz];
	setIsValid(str);
	cout << numofPaDP(str) - 1 << endl;
	delete[]isValid;

	system("pause");
	return 0;
}