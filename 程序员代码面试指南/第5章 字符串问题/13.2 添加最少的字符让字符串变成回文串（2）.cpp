#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void getPar(string str, string strips) {
	string left, leftReverse, right, rightReverse;
	string bigleft = "", bigright = "";

	long sz = str.length();
	long lp = 0, rp = sz - 1;

	long totalIters = (strips.size() + 1) / 2;

	for (long i = 0; i < totalIters; i++) {
		left = leftReverse = right = rightReverse = "";

		while (str[lp] != strips[i]) {
			left = left + str[lp];
			leftReverse = str[lp] + leftReverse;
			lp++;
		}

		while (str[rp] != strips[i]) {
			right = str[rp]+ right;
			rightReverse = rightReverse + str[rp];
			rp--;
		}

		bigleft = bigleft+left + rightReverse+ strips[i];

		if (lp == rp) {
			bigright = right + leftReverse + bigright;
		}
		else {
			bigright = strips[i] + right + leftReverse + bigright;
		}

		lp++; rp--;
	}
	string res = bigleft + bigright;
	cout << res << endl;
}

int main()
{
	string str, strips;
	cin >> str>>strips;

	getPar(str, strips);
	return 0;
}