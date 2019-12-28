#include <iostream>
using namespace std;

int gcd(int m, int n) {
	return n == 0 ? m : gcd(n, m%n);
}

int main() {
	int a, b;
	cin >> a >> b;
	cout << gcd(a, b) << endl;
	return 0;
}