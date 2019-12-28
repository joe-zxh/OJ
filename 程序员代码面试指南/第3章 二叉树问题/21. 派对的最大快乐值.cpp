#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Node {
public:
	long happy;
	vector<Node*> child; // 下属
	Node() {}
	Node(long h) :happy(h) {}
};
Node *employees;

class Res {
public:
	long come;
	long notCome;
};

Res maxHappy(Node *root) {
	long rs = root->child.size();
	long come=root->happy; // root来
	long notCome=0; // root不来

	for (long i = 0; i < rs; i++) {
		Res r = maxHappy(root->child[i]);
		come += r.notCome;
		notCome += max(r.come, r.notCome);
	}
	Res ret;
	ret.come = come;
	ret.notCome = notCome;
	return ret;
}

int main()
{
	long n, root, t1, t2;
	cin >> n >> root;

	employees = new Node[n+1];

	for (long i = 1; i <= n; i++) {
		cin >> 	employees[i].happy;
	}

	for (long i = 1; i <= n-1; i++) {
		cin >> t1 >> t2;
		employees[t1].child.push_back(&employees[t2]);
	}
	Res r = maxHappy(&employees[root]);
	cout << max(r.come, r.notCome) << endl;
	
	delete[]employees;
	return 0;
}