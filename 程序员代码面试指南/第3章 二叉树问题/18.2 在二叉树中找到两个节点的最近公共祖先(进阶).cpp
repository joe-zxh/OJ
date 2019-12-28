#include <iostream>
#include <map>
#include <set>
using namespace std;

int LCA(int head, int*lc, int *rc, int*father, int o1, int o2) {
	
	set<int>f1;
	f1.insert(o1);

	while (father[o1] != -1) {
		o1 = father[o1];
		f1.insert(o1);		
	}

	do {
		if (f1.find(o2)!=f1.end()) {
			return o2;
		}
		else {
			o2 = father[o2];
		}
	} while (o2 != -1);
}

int main()
{
	int n, root, t;
	scanf("%d %d", &n, &root);
	int* lc = new int[n + 1];
	int* rc = new int[n + 1];
	int* father = new int[n + 1];
	
	father[root] = -1;
	for (int i = 0; i < n; i++) {
		scanf("%d", &t);
		scanf("%d %d", &lc[t], &rc[t]);
		father[lc[t]] = t;
		father[rc[t]] = t;
	}
	int o1, o2, opts;
	scanf("%d", &opts);

	for (int i = 0; i < opts; i++) {
		scanf("%d %d", &o1, &o2);
		printf("%d\n", LCA(root, lc, rc, father, o1, o2));
	}	

	delete[]lc, rc, father;
	return 0;
}
