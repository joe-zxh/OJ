#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Record {
public:
	int value;
	int ind1, ind2;
	Record() {}
	Record(int v, int i1, int i2) :value(v), ind1(i1), ind2(i2) {}
};

struct cmpMax { // 大根堆
	bool operator() (const Record& a, const Record& b) {
		return a.value < b.value;
	}
};

int main()
{
	int n1, n2, k;
	cin >> n1 >> k;
	n2 = n1;
	vector<int> arr1(n1);
	vector<int> arr2(n2);

	unordered_map<int, unordered_map<int, bool>> tb;

	for (int i = 0; i < n1; i++) {
		cin >> arr1[i];
	}
	for (int i = 0; i < n2; i++) {
		cin >> arr2[i];
	}
	sort(arr1.begin(), arr1.end());
	sort(arr2.begin(), arr2.end());

	tb[n1-1][n2-1] = true;
	priority_queue<Record, vector<Record>, cmpMax> pq;
	pq.push(Record(arr1[n1-1]+arr2[n2-1], n1-1, n2-1));
	
	Record r; int x, y;
	while (k--) {
		r = pq.top();
		pq.pop();
		x = r.ind1;
		y = r.ind2;
		printf("%d ", r.value);
		if (x > 0 && !tb[x - 1][y]) { // ind1-1, ind2
			pq.push(Record(arr1[x - 1] + arr2[y], x - 1, y));
			tb[x-1][y] = true;
		}
		if (y > 0 && !tb[x][y-1]) { // ind1, ind2-1
			pq.push(Record(arr1[x] + arr2[y - 1], x, y - 1));
			tb[x][y - 1] = true;
		}
	}

	return 0;
}