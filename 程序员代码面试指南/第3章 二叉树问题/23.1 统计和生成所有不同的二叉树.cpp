#include <iostream>
using namespace std;
const long modNum = 1e9 + 7;

long f(int n) {
	if (n < 2) {
		return n;
	}	
	long sum = (f(n - 1) * 2) % modNum; // 以1号元素作为头节点、以n号元素作为头节点。

	for (long i = 2; i <= n - 1; i++) {
		sum = (sum + (f(i - 1) * f(n - i)) % modNum) % modNum;
	}
	return sum;
}

long fdp(int n) {
	if (n < 2) {
		return n;
	}
	
	long* dp = new long[n+1];
	dp[0] = 0;
	dp[1] = 1;
	
	for (int i = 2; i <= n; i++) {
		dp[i] = (dp[i - 1] * 2) % modNum;
		for (int j = 2; j <= i-1; j++) {
			dp[i] = (dp[i]+(dp[j - 1] * dp[i - j])%modNum)%modNum;
		}
	}

	long res = dp[n];
	delete[]dp;
	return res;
}

int main()
{
	int n;
	cin >> n;
	cout << fdp(n) << endl;
	return 0;
}
