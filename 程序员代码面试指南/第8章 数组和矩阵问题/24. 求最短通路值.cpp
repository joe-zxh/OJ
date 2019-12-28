#include<iostream>
#include<map>
#include<queue>
using namespace std;

char Matrix[1000][1000];
map<pair<int, int>, int>m;
int nrow, mcol;
queue<int>row; // 深搜
queue<int>col;

void go2(int r, int c, int pre) {
	if (r < 0 || r >= nrow || c<0 || c>=mcol ||
		Matrix[r][c] == '0' || m.find(pair<int, int>(r, c)) != m.end()) {
		return;
	}
	row.push(r); col.push(c);
	m[pair<int, int>(r, c)] = pre + 1;
}

int shortestPath() {
	if (Matrix[0][0] == '0' || Matrix[nrow-1][mcol -1]=='0') {
		return -1;
	}
	row.push(0);
	col.push(0);
	m[pair<int, int>(0, 0)] = 1;
	int r, c, pre;
	while (!row.empty()) {
		r = row.front(); row.pop();
		c = col.front(); col.pop();
		if (r == nrow - 1 && c == mcol - 1) {
			return m[pair<int, int>(r, c)];
		}
		pre = m[pair<int, int>(r, c)];
		go2(r - 1, c, pre);
		go2(r, c - 1, pre);
		go2(r, c + 1, pre);
		go2(r + 1, c, pre);
	}
	return -1;
}

int main() {
	cin >> nrow >> mcol;
	for (int i = 0; i < nrow; i++) {
		for (int j = 0; j < mcol; j++) {
			cin >> Matrix[i][j];
		}
	}
	cout << shortestPath() << endl;
	return 0;
}