
#include <iostream>
#include <algorithm>

using namespace std;

class Res {
public:
	long leftDepth;
	long rightDepth;
	long maxDist;
	Res() {}
	Res(long ld, long rd, long md) :leftDepth(ld), rightDepth(rd), maxDist(md) {}
};

Res MaxDist(long head, long* left, long* right) {
	Res res;
	Res lc, rc;

	if (left[head] != 0) { // 左不空
		lc = MaxDist(left[head], left, right);
	}
	else { // 左空
		lc.leftDepth = -1;
		lc.rightDepth = -1;
		lc.maxDist = 0;
	}

	if (right[head] != 0) { // 右不空
		rc = MaxDist(right[head], left, right);
	}
	else { // 右空
		rc.leftDepth = -1;
		rc.rightDepth = -1;
		rc.maxDist = 0;
	}

	res.leftDepth = max(lc.leftDepth, lc.rightDepth)+1;
	res.rightDepth = max(rc.leftDepth, rc.rightDepth) + 1;

	long incDist = res.leftDepth + res.rightDepth + 1;//包括当前节点的 最大距离

	res.maxDist = max(incDist, max(lc.maxDist, rc.maxDist));// 最大距离可能不包含当前节点
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

	cout << MaxDist(root, left, right).maxDist << endl;
	
	delete[] left, right;
	return 0;
}