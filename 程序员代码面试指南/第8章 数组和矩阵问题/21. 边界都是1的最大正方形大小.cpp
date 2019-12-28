#include <iostream>
using namespace std;

bool matrix[200][200];
int R[200][200]; // 当前位置 及其右边有几个1
int D[200][200]; // 当前位置 及其下边有几个1

long maxSquare(int n) {	
	for (int i = 0; i < n; i++) { // 设置R
		R[i][n - 1] = matrix[i][n - 1] == 0 ? 0 : 1;
		for (int j = n - 2; j >= 0; j--) {
			R[i][j] = matrix[i][j] == 0 ? 0 : R[i][j + 1] + 1;
		}
	}

	for (int j = 0; j < n; j++) { // 设置D
		D[n - 1][j] = matrix[n - 1][j] == 0 ? 0 : 1;
		for (int i = n - 2; i >= 0; i--) {
			D[i][j] = matrix[i][j] == 0 ? 0 : D[i + 1][j] + 1;
		}
	}

	int maxSide = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int pSide = n - i < n - j ? n - i : n - j; // 可能达到的最长边长
			for (int s = maxSide+1; s <= pSide; s++) { // 从maxSide+1开始遍历，能减少一点参数上的时间复杂度
				if (R[i][j] >= s && R[i + s - 1][j] >= s && D[i][j] >= s && D[i][j + s - 1] >= s) {
					maxSide = s;
				}
			}	
		}
	}
	return maxSide;
}

int main() {
	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> matrix[i][j];
		}
	}

	cout << maxSquare(n) << endl;
	return 0;
}