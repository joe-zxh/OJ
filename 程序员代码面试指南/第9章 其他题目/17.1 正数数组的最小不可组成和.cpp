#include <iostream>
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	int * arr = new int[n];
	int sum = 0, mv = ~(1<<31);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		sum += arr[i];
		mv = arr[i] < mv ? arr[i] : mv;
	}
	bool *dp = new bool[sum + 2];
	bool* dpn = new bool[sum + 2];
	bool* t;
	dp[0] = true; dp[sum + 1] = false;
	dpn[0] = true; dpn[sum + 1] = false;
	for (int j = 1; j < sum + 1; j++) { // 初始化
		dp[j] = false;
		dpn[j] = false;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= sum; j++) {
			if (dp[j] || (!dp[j] && j - arr[i] >= 0 && dp[j - arr[i]])) {
				dpn[j] = true;
			}
		}
		t = dp;
		dp = dpn;
		dpn = t;
	}

	for (int j = mv+1; j <= sum + 1; j++) { // 初始化
		if (!dp[j]) {
			cout << j << endl;
			break;
		}
	}	
	delete[]dp, dpn;
	return 0;
}