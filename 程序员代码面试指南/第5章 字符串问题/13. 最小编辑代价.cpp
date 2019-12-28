#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void getLeastCost(string a, string b, int ic, int dc, int rc) {	
	
	int sza = a.size()+1;
	int szb = b.size()+1;

	int *dp = new int[sza*szb]; // dp[i][j] // a[0...i-1]变成b[0...j-1]

	for (int j = 0; j < szb; j++) {
		dp[j] = j*ic; // 插入
	}
	for (int i = 0; i < sza; i++) {
		dp[i*szb] = i*dc; // 删除
	}

	for (int i = 1; i < sza; i++) {
		for (int j = 1; j < szb; j++) {
			if (a[i-1] == b[j-1]) {
				dp[i*szb+ j] = dp[(i-1)*szb+j-1];
			}
			else {
				dp[i*szb + j] = dp[(i - 1)*szb + j - 1]+rc;
			}
			dp[i*szb + j] = min(dp[i*szb + j], dp[(i - 1)*szb + j] + dc);
			dp[i*szb + j] = min(dp[i*szb + j], dp[i*szb + j - 1] + ic);
		}
	}

	int res = dp[(sza - 1)*szb + szb - 1];
	cout << res << endl;
	delete[]dp;
}

int main()
{
	string a, b;
	int ic, dc, rc;
	cin >> a >> b >> ic >> dc >> rc;
	getLeastCost(a, b, ic, dc, rc);
	return 0;
}