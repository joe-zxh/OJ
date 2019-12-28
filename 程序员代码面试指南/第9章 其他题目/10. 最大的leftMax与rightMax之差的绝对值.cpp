#include <iostream>
using namespace std;

int main() {	
	int a0, n, t, an;
	cin >> n;
	cin >> a0;
	int maxv = a0;
	for (int i = 1; i < n-1; i++) {
		cin >> t;
		maxv = t > maxv ? t : maxv;
	}
	cin >> an;

	int m1 = maxv > a0 ? maxv - a0 : a0 - maxv;
	int m2 = maxv > an ? maxv - an : an - maxv;

	m1 = m2 > m1 ? m2 : m1;
	cout << m1 << endl;
	return 0;
}