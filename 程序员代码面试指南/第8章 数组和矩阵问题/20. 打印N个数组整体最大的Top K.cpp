#include <iostream>
#include <queue>

using namespace std;

int main()
{
	int n, k, t, t2, f, sz;
	cin >> n >> k;
	int** vs = new int* [n]; // n个指针类型的数据
	int* cur = new int[n]; // 记录每个数组当前遍历到的位置
	priority_queue <pair<int, int>> pq;

	for (int i = 0; i < n; i++) {
		cin >> t;
		vs[i] = new int[t];
		cur[i] = t - 2;
		for (int j = 0; j < t; j++) {
			cin >> vs[i][j];
		}
		pq.push(pair<int, int>(vs[i][t - 1], i));
	}

	while (k--) {
		printf("%d ", pq.top().first);
		f = pq.top().second;
		pq.pop();

		if (cur[f] >= 0) {
			pq.push(pair<int, int>(vs[f][cur[f]--], f));
		}
	}

	for (int i = 0; i < n; i++) {
		delete[]vs[i];
	}
	vs = NULL;
	delete[]cur;
	printf("\n");
	
	return 0;
}