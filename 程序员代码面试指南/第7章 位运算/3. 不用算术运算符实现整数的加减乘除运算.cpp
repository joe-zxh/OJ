#include <iostream>
using namespace std;

const int minv = 1 << 31;
const int maxv = ~(1 << 31);
const int help = maxv>>1;

int Add(int a, int b) {
	int res = a ^ b;
	int jin = (a & b) << 1;
	a = res;
	b = jin;
	while (b != 0) {
		res = a^b;
		jin = b = ((a & b) << 1);
		a = res;
	}
	return res;
}

int Minus(int a, int b) {
	return Add(a, -b);
}

int Multiply(int a, int b) {
	int res = 0;

	if (a == minv) { // 边界条件
		if (b == 1) return a;
		if (b == 0) return 0;
	}

	if (b == minv) { // 边界条件
		if (a == 1) return b;
		if (a == 0) return 0;
	}

	bool neg = false;
	if (a < 0 && b>0 || a > 0 && b < 0) { // 处理负数的情况
		neg = true;
	}
	a = a < 0 ? -a : a;
	b = b < 0 ? -b : b;

	while (b != 0) {
		if ((b & 1) == 1) {
			res = Add(res, a);
		}
		a <<= 1;
		b >>= 1;
	}
	return neg?-res:res;
}

int Div(int a, int b) { // a>=0 b>=0
	int res = 0;
	int i = 1;
	while ((b << 1) <= a && b <=help) {
		b <<= 1;
		i++;
	}

	while (i--) {
		if (a >= b) {
			a -= b;
			res = ((res << 1) + 1);
		}
		else {
			res <<= 1;
		}
		b >>= 1;
	}
	return res;
}

int DivAPI(int a, int b) {
	if (a == minv && b == minv) {
		return 1;
	}
	
	if (b == minv) {
		return 0;
	}

	bool neg = false;
	if (a == minv) { // 单独处理
		neg = b > 0 ? true : false;
		b = b < 0 ? -b : b;
		int res = Div(~minv, b);
		res += Div(-(minv + Multiply(res, b)), b);
		return neg ? -res : res;
	}
	
	if (a < 0 && b>0 || a > 0 && b < 0) { // 处理负数的情况
		neg = true;
	}
	a = a < 0 ? -a : a;
	b = b < 0 ? -b : b;
		
	return neg ? -Div(a, b) : Div(a, b);
}

int main()
{
	int a, b;
	char ch;
    cin >> a >> ch >> b;
	if (ch == '+') {
			cout << Add(a, b) << endl;
		}
		else if (ch == '-') {
			cout << Minus(a, b) << endl;
		}
		else if (ch == '*') {
			cout << Multiply(a, b) << endl;
		}
		else {
			cout << DivAPI(a, b) << endl;
		}
	
	return 0;
}
