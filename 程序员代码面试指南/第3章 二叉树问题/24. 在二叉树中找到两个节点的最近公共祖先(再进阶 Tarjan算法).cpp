#include<iostream>
#include<map>
#include<list>

using namespace std;

int* father; // 直接父节点
map<int, list<int>>query; // key: nodeA value: 和nodeA有查询关系的节点的列表。
map<int, list<int>>index; // key: nodeA value: 对应的query的结果 应该要被放入的位置。
int* ancestor; // key: 并查集的root节点  value: 并查集的祖先是谁。

int findRoot(int a) {
	int r = a;
	while (*(father + r) != r) {
		r = *(father + r);
	}

	int t;
	while (*(father + a) != a) {
		t = *(father + a);
		*(father + a) = r;
		a = t;
	}
	return r;
}

void Union(int a, int b) {
	int ra = findRoot(a);
	int rb = findRoot(b);

	if (ra < rb) {
		father[rb] = ra;
	}
	else {
		father[ra] = rb;
	}
}

void setAnswer(int head, int* lc, int* rc, int* ans) {
	if (lc[head] != 0) {
		setAnswer(lc[head], lc, rc, ans);
		Union(lc[head], head);
		ancestor[findRoot(head)] = head; // 设置大并查集的祖先为当前节点。
	}

	if (rc[head] != 0) {
		setAnswer(rc[head], lc, rc, ans);
		Union(rc[head], head);
		ancestor[findRoot(head)] = head; // 设置大并查集的祖先为当前节点。
	}
		
	if (query.find(head) != query.end()) {
		int nodeB, ind, ance;	
		while (!query[head].empty()) {
			nodeB = query[head].front();
			query[head].pop_front();
			ind = index[head].front();
			index[head].pop_front();
			ance = ancestor[findRoot(nodeB)];

			if (ance != -1) {
				ans[ind] = ance;
			}
		}
	}
}

int main() {
	int n, root, t, q, o1, o2;
	cin >> n >> root;

	int* lc = new int[n + 1], * rc = new int[n + 1];
	father = new int[n+1];
	ancestor = new int[n + 1];//大并查集的祖先（已经遍历过的元素的整体的祖先）
		
	for (int i = 0; i < n; i++) {
		cin >> t;
		father[t] = t;// 并查集一开始 自己就是头节点，头节点的father就是自己
		ancestor[t] = -1;// 一开始大家都没有祖先
		cin >> lc[t] >> rc[t];
	}

	cin >> q;
	int* ans = new int[q];
	for (int i = 0; i < q; i++) { // 设置query和index map
		cin >> o1 >> o2;
		query[o1].push_back(o2);
		query[o2].push_back(o1);
		index[o1].push_back(i);
		index[o2].push_back(i);
	}
	setAnswer(root, lc, rc, ans);
	for (int i = 0; i < q; i++) { 
		printf("%d\n", ans[i]);
	}

	delete[]father, lc, rc, ancestor, ans;
	return 0;
}
