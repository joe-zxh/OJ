#include <iostream>
#include <string>
using namespace std;

const long M = 1e9+7;

long True[500][500], False[500][500];

long getNumDP(string str, bool aim) {
	long sz = str.size();
	
	// 填写对角线
	for (long i = 0; i < sz; i += 2) {
		for (long j = i + 2; j < sz; j += 2) {
			True[i][j] = 0;
			False[i][j] = 0;
		}

		True[i][i] = str[i] - '0' == 1 ? 1 : 0;
		False[i][i] = str[i] - '0' == 0 ? 1 : 0;
	}

	// 从下往上，从左往右
	for (long left = sz - 3; left >= 0; left -= 2) {
		for (long right = left + 2; right < sz; right += 2) {
			for (long i = left + 1; i < right; i += 2) {

				if (str[i] == '^') {
					// true false  +  false true
					True[left][right] += (True[left][i - 1] * False[i + 1][right]) % M;
					True[left][right] += (False[left][i - 1] * True[i + 1][right]) % M;

					// true true + false false
					False[left][right] += (True[left][i - 1] * True[i + 1][right]) % M;
					False[left][right] += (False[left][i - 1] * False[i + 1][right]) % M;

					True[left][right] %= M;
					False[left][right] %= M;
				}
				else if (str[i] == '|') {
					// true true  +  false true + true false
					True[left][right] += (True[left][i - 1] * True[i + 1][right]) % M;
					True[left][right] += (False[left][i - 1] * True[i + 1][right]) % M;
					True[left][right] += (True[left][i - 1] * False[i + 1][right]) % M;

					// false false
					False[left][right] += (False[left][i - 1] * False[i + 1][right]) % M;

					True[left][right] %= M;
					False[left][right] %= M;
				}
				else if (str[i] == '&') {
					// true true
					True[left][right] += (True[left][i - 1] * True[i + 1][right]) % M;

					// true false + false true + false false
					False[left][right] += (True[left][i - 1] * False[i + 1][right]) % M;
					False[left][right] += (False[left][i - 1] * True[i + 1][right]) % M;
					False[left][right] += (False[left][i - 1] * False[i + 1][right]) % M;

					True[left][right] %= M;
					False[left][right] %= M;
				}
			}
		}
	}
	
	long res = aim ? True[0][sz - 1] : False[0][sz - 1];
	return res;
}

int main()
{
	string str;
	string aim;
	cin >> str >> aim;
	if (aim == "true") {
		cout << getNumDP(str, true) << endl;
	}
	else {
		cout << getNumDP(str, false) << endl;
	}
	return 0;
}