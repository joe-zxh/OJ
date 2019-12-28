#include<iostream>
using namespace std;

int main() {
	int n, count = 0;
	cin >> n;

	int len = sizeof(int) * 8;

	for (int i = 0; i < len; i++) {
		if ((n & 1) == 1) {
			count++;
		}
		n >>= 1;
	}
	cout << count << endl;
	return 0;
}