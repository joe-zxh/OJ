#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

class Node {
public:
	long value;
	Node* lc, * rc;
	Node() {}
	Node(long v, Node* l, Node* r) :value(v), lc(l), rc(r) {}
};

class Record {
public:
	long leftContri, rightContr;
	Record() {}
	Record(long lc, long rc) :leftContri(lc), rightContr(rc) {}
};

map<Node*, Record> m;

long modifyMap(Node* &head, long v, bool islc) {
	// 返回需要减少的贡献值
	if (head == NULL || m.find(head) == m.end()) {
		return 0;
	}

	if (islc) { // 左子树的节点
		if (head->value < v) { // 当前节点 在以根节点 的BST拓扑中
			if (head->rc == NULL) {
				return 0; // 不需要修改
			}
			else {
				Record record = m.find(head)->second;
				long minus = modifyMap(head->rc, v, islc);
				record.rightContr -= minus;
				m[head] = record;
				return minus;
			}
		}
		else {  // 当前节点 不在以根节点 的BST拓扑中
			Record record = m.find(head)->second;
			m.erase(m.find(head));
			return record.leftContri + record.rightContr + 1;
		}
	}
	else { // 右子树的节点
		if (head->value > v) { // 当前节点 在以根节点 的BST拓扑中
			if (head->lc == NULL) {
				return 0; // 不需要修改
			}
			else {
				Record record = m.find(head)->second;
				long minus = modifyMap(head->lc, v, islc);
				record.leftContri -= minus;
				m[head] = record;
				return minus;
			}
		}
		else {  // 当前节点 不在以根节点 的BST拓扑中
			Record record = m.find(head)->second;
			m.erase(m.find(head));
			return record.leftContri + record.rightContr + 1;
		}
	}
}

void getBSTRecord(Node* &head, long &maxBST) {
	
	Record lr, rr;

	if (head->lc != NULL) { // 左孩子不空
		getBSTRecord(head->lc, maxBST);
		modifyMap(head->lc, head->value, true); // 修改左子树

		if (m.find(head->lc) != m.end()) {
			lr = m.find(head->lc)->second;
		}
		else {
			lr.leftContri = 0; // 单纯为了凑108行的值=0
			lr.rightContr = -1;
		}		
	}
	else { // 左孩子空
		lr.leftContri = 0; // 单纯为了凑108行的值=0
		lr.rightContr = -1;
	}

	if (head->rc != NULL) { // 右孩子不空
		getBSTRecord(head->rc, maxBST);
		modifyMap(head->rc, head->value, false);// 修改右子树

		if (m.find(head->rc) != m.end()) {
			rr = m.find(head->rc)->second;
		}
		else {
			rr.leftContri = 0;
			rr.rightContr = -1;
		}		
	}
	else { // 右孩子 空
		rr.leftContri = 0;
		rr.rightContr = -1;
	}

	Record record = Record(lr.leftContri + lr.rightContr + 1, rr.leftContri + rr.rightContr + 1);
	m[head] = record;

	maxBST = max(record.leftContri+record.rightContr+1, maxBST);
}

int main() {
	long n, root, a, b, c;
	cin >> n >> root;
	Node* nodes = new Node[n+1];

	for (long i = 1; i <= n; i++) {
		nodes[i].value = i;
		cin >> a >> b >> c;
		nodes[a].lc = b == 0 ? NULL : &nodes[b];
		nodes[a].rc = c == 0 ? NULL : &nodes[c];
	}
	long maxBST = 1;
	Node* t = &nodes[root];
	getBSTRecord(t, maxBST);
		
	printf("%d\n", maxBST);
	
	delete[]nodes;
	return 0;
}