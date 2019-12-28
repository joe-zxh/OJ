#include <iostream>
#include <string>
using namespace std;

bool dp[305][305] = {false}; // 不知道这里会不会越界

bool isMatch(string str, string exp, int si, int ei) {
	if (exp.length()==ei) {
		return str.length() == si;
	}

	if (ei == exp.length() - 1 || exp[ei + 1] != '*') {
		// ei的下一个位置不是'*'的情况：如果ei位置和si位置的字符匹配 或者 ei位置的字符为'.'，那么匹配下一个字符
		return si != str.length() && (str[si]==exp[ei]||exp[ei]=='.')
			&& isMatch(str, exp, si+1, ei+1);
	}

	// exp的下一个位置是'*'
	while (si != str.length() && (str[si] == exp[ei] || exp[ei] == '.')) {
		if (isMatch(str, exp, si, ei+2)) { // 从0个开始
			return true;
		}
		si++;
	}
	return isMatch(str, exp, si, ei + 2);
}

void InitDP(string str, string exp) {
	int sLen = str.length();
	int eLen = exp.length();

	// 设置最后一列
	dp[sLen][eLen] = true;

	// 设置倒数第二列
	dp[sLen - 1][eLen - 1] = (str[sLen - 1] == exp[eLen - 1] || exp[eLen - 1] == '.') ? true : false;

	// 设置倒数第一行
	for (int i = eLen - 2; i >= 0; i-=2) {
		if (exp[i] != '*' && exp[i + 1] == '*') {
			dp[sLen][i] = true;
		}
		else {
			break;
		}
	}
}

bool isMatchDP(string str, string exp) {
	int sLen = str.length();
	int eLen = exp.length();

	if (eLen <= 0) {
		return false;
	}
	InitDP(str, exp);
	
	for (int i = sLen - 1; i >= 0; i--) {
		for (int j = eLen - 2; j >= 0; j--) {

			if (j == exp.length() - 1 || exp[j + 1] != '*') {
				// ei的下一个位置不是'*'的情况：如果ei位置和si位置的字符匹配 或者 ei位置的字符为'.'，那么匹配下一个字符
				dp[i][j]= i != str.length() && (str[i] == exp[j] || exp[j] == '.')
					&& dp[i + 1][j + 1];
			} else {
                // exp的下一个位置是'*'
                int ii = i;
                while (ii != str.length() && (str[ii] == exp[j] || exp[j] == '.')) {
                    if (dp[ii][j+2]) { // 从0个开始
                        dp[i][j] = true;
                        break;
                    }
                    ii++;
                }
                if (dp[i][j]!=true) {
                    dp[i][j] = dp[ii][j + 2];
                }
            }						
		}
	}

	return dp[0][0];
}


int main()
{
	string str, exp;
	cin >> str >> exp;

	if (isMatchDP(str, exp)) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
	return 0;
}