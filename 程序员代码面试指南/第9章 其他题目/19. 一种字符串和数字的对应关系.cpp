#include <iostream>
#include <map>
#include <string>
using namespace std;

map<char, int> m;//key: 字母  value: base
map<int, char> m2;//key: base  value: 字母
void int2Str(int num, int n) {
	string str="";
	int base = 1;

	while (num - base >= 0) {
		num -= base;
		base *= n;
	}
	base /= n;

	while (base > 0) {
		str = str + m2[1+num/base];
		num %= base;
		base /= n;
	}

	cout << str << endl;
}

void str2Int(string str, int n) {
	int sz = str.size();
	int base = 1;
	int res = 0;

	for (int i = sz - 1; i >= 0; i--) {
		res += m[str[i]] * base;
		base *= n;
	}
	cout << res << endl;
}

int main() {
	int opt, n;
	char t;
	cin >> opt >> n;
	for (int i = 1; i <= n; i++) {
		cin >> t;
		m[t] = i;
		m2[i] = t;
	}

	if (opt == 1) {
		int num;
		cin >> num;
		int2Str(num, n);
	}else if (opt == 2) {
		string str;
		cin >> str;
		str2Int(str, n);
	}
	return 0;
}