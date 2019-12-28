#include <iostream>
#include <list>

using namespace std;

void levelPrint(int head, int* lc, int*rc) {
	list<pair<int, int>> nodes; // pair: (value, level)
	nodes.push_back(pair<int, int>(head, 1));
	int val, level, curLevel = 0;
	while (!nodes.empty()) {
		val = nodes.front().first;
		level = nodes.front().second;
		nodes.pop_front();
		if (val != 0) {
			if (curLevel != level) {
				curLevel = level;
				curLevel==1? printf("Level %d : ", curLevel):
					printf("\nLevel %d : ", curLevel);
			}

			printf("%d ", val);
			nodes.push_back(pair<int, int>(lc[val], level+1));
			nodes.push_back(pair<int, int>(rc[val], level+1));
		}
	}
	printf("\n");
}

void ZigZagPrint(int head, int* lc, int* rc) {
	list<pair<int, int>> nodes; // pair: (value, level)
	// nodes.push_back(pair<int, int>(head, 1));
	int val=head, level=1, curLevel = 1;
	printf("Level 1 from left to right: %d", val);
	nodes.push_back(pair<int, int>(lc[head], 2));
	nodes.push_back(pair<int, int>(rc[head], 2));

	while (!nodes.empty()) {
		if (curLevel % 2 == 1) { // 左到右，pop_front, push_back
			val = nodes.front().first;
			level = nodes.front().second;

			if (curLevel != level && val!=0) {
				curLevel = level;
				printf("\nLevel %d from right to left: ", curLevel);
			}
			else {
				nodes.pop_front();
				if (val != 0) {
					printf("%d ", val);
					nodes.push_back(pair<int, int>(lc[val], curLevel+1));
					nodes.push_back(pair<int, int>(rc[val], curLevel+1));
				}
			}
		}
		else { // 右到左，pop_back, push_front
			val = nodes.back().first;
			level = nodes.back().second;

			if (curLevel != level && val != 0) {
				curLevel = level;
				printf("\nLevel %d from left to right: ", curLevel);
			}
			else {
				nodes.pop_back();
				if (val != 0) {
					printf("%d ", val);
					nodes.push_front(pair<int, int>(rc[val], curLevel + 1));
					nodes.push_front(pair<int, int>(lc[val], curLevel + 1));
				}
			}
		}
	}

}

int main()
{
	int n, head, t;
	cin >> n >> head;
	int* lc = new int[n + 1];
	int* rc = new int[n + 1];

	for (int i = 0; i < n; i++) {
		cin >> t;
		cin >> lc[t] >> rc[t];
	}
	levelPrint(head, lc, rc);
	ZigZagPrint(head, lc, rc);
	
	delete[]lc, rc;
	return 0;
}
