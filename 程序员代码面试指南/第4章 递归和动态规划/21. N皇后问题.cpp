#include<iostream>
using namespace std;

// colLim标记1的是可以放的位置
// colLim,leftLim和rightLim标记1的是不能放的位置
long NQueen(int colLim, int leftLim, int rightLim) {

	if (colLim==0) {
		return 1;
	}

	int mostRightOne, col=colLim;
	long res = 0;

	while (col > 0) {
		mostRightOne = col & (~col + 1);
		col -= mostRightOne;
		if (mostRightOne & ~leftLim && mostRightOne & ~rightLim) {
			res += NQueen(colLim- mostRightOne,
				(leftLim|mostRightOne)<<1, (rightLim|mostRightOne)>>1);
		}
	}
	return res;
}

int main() {
	int n, up;
	cin >> n;
    up = n == 32 ? -1 : (1 << n) - 1;
	cout << NQueen(up,0,0) << endl;
	return 0;
}
