#include <iostream>
#include <string>

const long modnum = 1e9+7;

using namespace std;

bool vailid(string str) {
	long sz = str.size();
	for (long i = 0; i < sz; i++) {
		if (str[i] > '9' || str[i] < '1') {
			return false;
		}
	}
	return true;
}

void getTransNum(string str) {
	if (!vailid(str)) {
		cout << 0 << endl;
		return;
	}

	long sz = str.size();
	long cur, next, nextnext;
	// long *dp = new long[sz]; // dp[i] 表示 str[i...sz-1]有多少种组合方式
	cur = nextnext = 1;
	
	if (sz <= 1) {
		cout << 1 << endl;
		return;
	}

	if (str[sz - 2] == '1' || (str[sz - 2] == '2'&&str[sz - 1] <= '6')) {
		cur = next = 2;
	}
	else {
		cur = next = 1;
	}

	for (long i = sz - 3; i >= 0; i--) {
		cur = next;
		if (str[i] == '1' || (str[i] == '2'&&str[i + 1] <= '6')) {
			cur = (cur + nextnext) % modnum;
		}
		nextnext = next;
		next = cur;
	}
	cout << cur << endl;
}

int main() {
	string str;
	cin >> str;
	getTransNum(str);
	return 0;
}