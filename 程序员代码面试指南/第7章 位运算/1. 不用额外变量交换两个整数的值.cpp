#include <iostream>
using namespace std;

int main() {
	int m, n;
	cin >> m >> n;
	m = m ^ n;
	n = m ^ n;
	m = m ^ n;

	printf("%d %d\n", m, n);
	return 0;
}