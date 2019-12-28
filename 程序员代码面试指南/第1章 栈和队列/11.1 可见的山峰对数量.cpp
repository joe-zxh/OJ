#include <iostream>
using namespace std;

long f(long n) {
	if (n <= 2) {
		return n-1;
	}
	else {
		return 2 * n - 3;
	}
}

int main() {
	long T, a, b, c;
	cin >> T;
	while (T--) {
		cin >> a >> b >> c;
		cout<<f(a)<<endl;
	}
	return 0;
}