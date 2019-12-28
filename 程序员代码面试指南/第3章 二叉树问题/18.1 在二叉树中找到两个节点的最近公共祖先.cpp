#include <iostream>
using namespace std;

int LCA(int head, int*lc, int *rc, int o1, int o2) {
	if (head == 0 || head==o1 || head==o2) {
		// 如果head==o1, o2在head下面，最后返回的也是head
		return head;
	}

	int lres = LCA(lc[head], lc, rc, o1, o2);
	int rres = LCA(rc[head], lc, rc, o1, o2);

	if (lres != 0 && rres != 0) {
		return head;
	}

	return lres == 0 ? rres : lres; // 另外一个可能是0，也可能不是0
}

int main()
{
	int n, root, t;
	cin >> n >> root;
	int* lc = new int[n + 1];
	int* rc = new int[n + 1];
	
	for (int i = 0; i < n; i++) {
		cin >> t;
		cin >> lc[t] >> rc[t];
	}
	int o1, o2;
	cin >> o1 >> o2;
	cout << LCA(root, lc, rc, o1, o2) << endl;

	delete[]lc, rc;
	return 0;
}
