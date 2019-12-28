#include<iostream>
#include<math.h>
#define ll long long
using namespace std;

ll getTime(int N, int K) {
	if (K > log2(N)) {
		return log2(N) + 1;
	}
	if (K == 1) {
		return N;
	}

	ll *dp = new ll[K];
	for (int i = 0; i < K; i++) { // 设置第一列
		dp[i] = 1;
	}
	ll ti = 2;
	while (true) {
		for (int i = K-1; i >0 ; i--) {
			dp[i] += (dp[i - 1]+1);
			if (i == K - 1 && dp[i] >= N) {
				delete[]dp;
				return ti;
			}
		}
		dp[0] = ti++;
	}	
}

int main() {
	int N, K;
	cin >> N >> K;
	cout << getTime(N, K) << endl;
	return 0;
}