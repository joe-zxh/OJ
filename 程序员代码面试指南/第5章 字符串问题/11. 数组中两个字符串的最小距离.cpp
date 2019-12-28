#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n, last1=-1, last2=-1;
	cin >> n;
	string str1, str2, stemp;
	cin >> str1 >> str2;
	int minv = ~(1 << 31);
	int minDist = minv;
	for (int i = 0; i < n; i++) {
		cin >> stemp;
		if (stemp == str1) {
			last1 = i;
			if (last2 != -1) {
				minDist = minDist > (last1 - last2) ? (last1 - last2) : minDist;
			}
		}
		else if (stemp == str2) {
			last2 = i;
			if (last1 != -1) {
				minDist = minDist > (last2 - last1) ? (last2 - last1) : minDist;
			}
		}
	}
	if (minDist == minv) {
		cout << -1 << endl;
	}
	else {
		cout << minDist << endl;
	}
	return 0;
}