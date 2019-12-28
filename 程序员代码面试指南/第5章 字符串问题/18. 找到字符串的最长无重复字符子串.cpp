#include <iostream>
#include <map>
using namespace std;

void getNoRepeat(int *arr, int n) {	
	map<int, int> m;// key: arr[i]  value: i
	int *dp = new int[n];
	dp[0] = 1;
	m[arr[0]] = 0;

	int pos;
	int res = 1;
	for (int i = 1; i < n; i++) {
		pos = i-1-dp[i-1];

		if (m.find(arr[i]) != m.end()) {
			pos = pos > m[arr[i]] ? pos : m[arr[i]];
		}
		dp[i] = i - pos;
		res = res < dp[i] ? dp[i] : res;
		m[arr[i]] = i;		
	}
	delete[] dp;
	cout << res << endl;
}

int main()
{
	int n;
	cin >> n;
	int *arr = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	getNoRepeat(arr, n);
	return 0;
}