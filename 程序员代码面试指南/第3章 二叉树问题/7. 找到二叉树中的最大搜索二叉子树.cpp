
#include <iostream>
#include <algorithm>

using namespace std;

class Res {
public:
	long maxVal;
	long minVal;
	long size;
	bool isBST;
	Res() {}
	Res(long ma, long mi, long s, bool IB) :maxVal(ma), minVal(mi), size(s), isBST(IB) {}
};

Res MaxBSTSize(long head, long* left, long* right) {
	Res res(head, head, 1, false);

	Res lc, rc;

	if (left[head] != 0) { // 左不空
		lc = MaxBSTSize(left[head], left, right);
	}
	else { // 左空
		lc.maxVal = lc.minVal = head;
		lc.size = 0;
		lc.isBST = true;
	}

	if (right[head] != 0) { // 右不空
		rc = MaxBSTSize(right[head], left, right);
	}
	else { // 右空
		rc.maxVal = rc.minVal = head;
		rc.size = 0;
		rc.isBST = true;
	}

	res.maxVal = max(res.maxVal, max(lc.maxVal, rc.maxVal));
	res.minVal = min(res.minVal, min(lc.minVal, rc.minVal));

	if (lc.isBST == true && rc.isBST == true && lc.maxVal <= head && head <= rc.minVal) {
		res.isBST = true;
		res.size = lc.size + rc.size + 1;
	}
	else { // maxBST不包括当前节点
		res.isBST = false;
		res.size = max(lc.size, rc.size);
	}
	return res;
}

int main() {
	long n, root;
	cin >> n >> root;
	long* left = new long[n + 1];
	long* right = new long[n + 1];
	long temp;

	for (long i = 0; i < n; i++) {
		cin >> temp;
		cin >> left[temp] >> right[temp];
	}

	cout << MaxBSTSize(root, left, right).size << endl;
	
	delete[] left, right;
	return 0;
}