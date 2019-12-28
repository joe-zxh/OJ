#include <iostream>
#include <string>
using namespace std;

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

int main()
{
	string str, exp;
	cin >> str >> exp;

	if (isMatch(str, exp, 0, 0)) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
	return 0;
}