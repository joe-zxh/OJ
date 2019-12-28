#include <iostream>
#include <string>
using namespace std;

int minInt = 1<<31;
int maxInt = (-1 ^ minInt);

bool isValid(string str) {
	if (str[0]=='0' && str.length()>1) { // 如果开头为0，那么后续必无字符
		return false;
	}

	if (str[0] == '-' && str[1]=='0') { //-号后面不能跟0
		return false;
	}

	if (!(str[0]=='-'|| (str[0]<='9'&&str[0]>='0'))) { // 第1个位置只能是-号 或者 数字
		return false;
	}

	for (int i = 1; i < str.length(); i++) { // 后面的都是数字才行
		if (str[i]<'0' || str[i]>'9') {
			return false;
		}
	}
	return true;
}

int str2Int(string str) {
	if (!isValid(str)) {
		return 0;
	}

	int res = 0;
	int s = 0;
	if (str[0] == '-') {
		s = 1;
	}

	int a = minInt / 10;
	int b;
	for (int i = s; i < str.length(); i++) {
		b = minInt - ('0' - str[i]);
		if (res>=a && res*10>=b) {
			res = res*10+'0'-str[i];
		}
		else {
			return 0;
		}
	}
	if (res == minInt&&str[0] != '-') {
		return 0;
	}
	return str[0] == '-' ? res : -res;
}

int main()
{
	string str;
	cin >> str;
	cout << str2Int(str) << endl;
	return 0;
}