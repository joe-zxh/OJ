#include <iostream>
using namespace std;

int main() {	
	long n;
	cin >> n;
	long ans=0;

	while (n > 0) {
		ans += n / 5;
		n /= 5;
	}
	cout << ans << endl;
	return 0;
}