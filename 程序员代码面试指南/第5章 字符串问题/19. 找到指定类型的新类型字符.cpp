#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str;
	int n, k, ind;
	int up; // str[k] 左边大写的个数
	cin >> n >> k >> str;
	up = 0;
	ind = k - 1;
	while (ind >= 0) {
		if (str[ind] <= 'Z' && str[ind] >= 'A') {
			up++;
			ind--;
		}
		else {
			break;
		}
	}
	if (str[k] <= 'z' && str[k] >= 'a') {
		if (up % 2) {
			printf("%c%c\n", str[k - 1], str[k]);
		}
		else {
			printf("%c\n", str[k]);
		}
	}
	else { // 大写
		if (up % 2) {
			printf("%c%c\n", str[k - 1], str[k]);
		}
		else {
			printf("%c%c\n", str[k], str[k + 1]);
		}
	}
	
	return 0;
}
