#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

long *dp;
void getParFromDP(string str);

void getParDP(string str) {
	long sz = str.size();
	dp = new long[sz*sz];

	for (long i = 0; i < sz; i++) { // 设置对角线 和 对角线左边一条
		dp[i*sz + i] = 0;
		if (i > 0) {
			dp[i*sz + i - 1] = 0;
		}
	}

	for (long i = sz - 1; i >= 0; i--) {
		for (long j = i + 1; j < sz; j++) {
			if (str[i] == str[j]) {
				dp[i*sz + j] = dp[(i + 1)*sz + j - 1];
			}
			else {
				dp[i*sz + j] = 1+min(dp[(i + 1)*sz + j], dp[i*sz + j - 1]);
			}
		}
	}
	
	getParFromDP(str);
	delete[]dp;
}

void getParFromDP(string str) {
	long sz = str.size();
	long rs = dp[sz - 1]; // 附加的大小。
	string out(sz+rs, ' ');
	long i = 0, j = sz - 1;
	long left = 0, right = sz + rs - 1;
	while (i <= j) {
		if (str[i] == str[j]) {
			out[left++] = out[right--] = str[i];
			i++; j--;
		}
		else if (dp[i*sz + j - 1] < dp[(i + 1)*sz + j]) { // 复制j位置的元素，j--
			out[left++] = out[right--] = str[j];
			j--;
		}
		else {
			out[left++] = out[right--] = str[i];
			i++;
		}
	}
	cout << out << endl;
}

int main()
{
	string str;
	cin >> str;
	
	getParDP(str);
	return 0;
}