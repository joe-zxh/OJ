#include <iostream>
using namespace std;

int main() {	
	long n, temp;
	cin >> n;
	temp = n;

	long len = sizeof(long)*8;
	long a = 0;
	
	while (len--) {
		if (temp & 1==1) {
			a++;
		}
		temp >>= 1;
	}

	cout << n - a << endl;
	return 0;
}