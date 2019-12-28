#include<iostream>
using namespace std;

int main() {
	int n, t, xor1=0;
	cin >> n;
	while (n--) {
		cin >> t;
		xor1 ^= t;
	}
	cout << xor1 << endl;
	return 0;
}
