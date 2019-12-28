#include<iostream>
#include<map>

using namespace std;

int main() {

	map<pair<int, int>, bool> m;
	map<pair<int, int>, bool>::iterator iter;

	int ldx = ~(1 << 31), ldy = ~(1 << 31); // left down x; left down y
	int rux = (1 << 31), ruy = (1 << 31); // right up x; right up y

	int n, x1, y1, x2, y2;
	int area = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x1 >> y1 >> x2 >> y2;

		if (x1 <= ldx && y1 <= ldy) {
			ldx = x1; ldy = y1;
		}

		if (x2 >= rux && y2 >= ruy) {
			rux = x2; ruy = y2;
		}
		
		// 左下角
		iter = m.find(pair<int, int>(x1, y1));
		if (iter != m.end()) {
			m.erase(iter);
		}
		else {
			m[pair<int, int>(x1, y1)] = true;
		}

		// 左上角
		iter = m.find(pair<int, int>(x1, y2));
		if (iter != m.end()) {
			m.erase(iter);
		}
		else {
			m[pair<int, int>(x1, y2)] = true;
		}
		
		// 右上角
		iter = m.find(pair<int, int>(x2, y2));
		if (iter != m.end()) {
			m.erase(iter);
		}
		else {
			m[pair<int, int>(x2, y2)] = true;
		}

		// 右下角
		iter = m.find(pair<int, int>(x2, y1));
		if (iter != m.end()) {
			m.erase(iter);
		}
		else {
			m[pair<int, int>(x2, y1)] = true;
		}

		area += (x2 - x1) * (y2 - y1);
	}

	if (m.size() == 4 && area == (rux - ldx) * (ruy - ldy)) {
		printf("Yes\n");
	}
	else {
		printf("No\n");
	}
	return 0;
}
