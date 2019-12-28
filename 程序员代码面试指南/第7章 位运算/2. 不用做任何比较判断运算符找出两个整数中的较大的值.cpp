#include<iostream>
using namespace std;

int big(int a, int b) {
	int signa = (a >> 31 & 1);
	int signb = (b >> 31 & 1);

	if (signa - signb) { // 符号不同
		return signa == 1 ? b : a;
	}
	else {
		return a - b > 0 ? a : b;
	}
}

int main() {
	int a, b;
	cin >> a >> b;
	cout << big(a, b) << endl;
	return 0;
}
