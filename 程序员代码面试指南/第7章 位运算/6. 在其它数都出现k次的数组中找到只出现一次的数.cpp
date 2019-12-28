#include<iostream>
using namespace std;

int main() {
	int help[32] = { 0 };
	int n, k, temp;
	cin >> n >> k;
	int j = 0;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		j = 0;
		while (temp>0) {
			help[j] = (help[j] + (temp % k)) % k;
			temp /= k;
			j++;
		}
	}
	int p = 1, res = 0;
	for (int i = 0; i < 32; i++) {
		res += help[i] * p;
		p *= k;
	}
	cout << res << endl;

	return 0;
}