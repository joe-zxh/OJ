#include <iostream>
#include <map>
using namespace std;

map<int, int>m;

// m: key: sum value: level
void longest(int head, int *lc, int* rc, int*val,
	int pathsum, int level, int &maxlen, int aim) {
	
	if (head == 0) {
		return;
	}

	pathsum += val[head];
	if (m.find(pathsum) == m.end()) {
		m[pathsum] = level;	   		 
	}

	if (m.find(pathsum - aim) != m.end()) {
		int t = level - m[pathsum - aim];
		maxlen = maxlen < t ? t : maxlen;
	}

	longest(lc[head], lc, rc, val, pathsum, level + 1, maxlen, aim);
	longest(rc[head], lc, rc, val, pathsum, level + 1, maxlen, aim);

	if (m[pathsum] == level) {
		m.erase(m.find(pathsum));
	}
}

int main()
{
	m[0] = 0;
	int n, root, t, aim;
	cin >> n >> root;
	int* lc = new int[n+1];
	int* rc = new int[n+1];
	int* val = new int[n+1];

	for (int i = 0; i < n; i++) {
		cin >> t;
		cin >> lc[t] >> rc[t] >> val[t];
	}
	cin >> aim;

	int maxlen = 0;
	longest(root, lc, rc, val, 0, 1, maxlen, aim);
	cout << maxlen << endl;

	return 0;
}
