#include <iostream>
using namespace std;

int getHeight(int head, int* lc, int* rc, int curHeight) {
	if (head == 0) {
		return curHeight;
	}
	int hl = getHeight(lc[head], lc, rc, curHeight + 1);
	int hr = getHeight(rc[head], lc, rc, curHeight + 1);

	return hl > hr ? hl : hr;
}

void setEdges(int head, int* lc, int* rc, int *edges, int curHeight) {
	
	if (head == 0) {
		return;
	}

	edges[2 * curHeight] = edges[2 * curHeight] == -1 ? head : edges[2 * curHeight];
	setEdges(lc[head], lc, rc, edges, curHeight + 1);

	edges[2 * curHeight + 1] = head;
	setEdges(rc[head], lc, rc, edges, curHeight + 1);
}

void printLeafNotEdge(int head, int* lc, int* rc, int* edges, int curHeight) {
	if (head == 0) {
		return;
	}
	if (lc[head] == 0 && rc[head] == 0
		&& edges[2*curHeight]!=head && edges[2*curHeight+1]!=head) {
		printf("%d ", head);
	}
	printLeafNotEdge(lc[head], lc, rc, edges, curHeight + 1);
	printLeafNotEdge(rc[head], lc, rc, edges, curHeight + 1);
}

void print1(int head, int *lc, int *rc) {
	
	int h = getHeight(head, lc, rc, 0);
	int* edges = new int[h*2];
	for (int i = 0; i < h * 2; i++) edges[i] = -1;

	setEdges(head, lc, rc, edges, 0);

	// 打印左边界
	for (int i = 0; i < h; i++) {
		printf("%d ",edges[2*i]);
	}

	// 打印除了边界外的叶节点
	printLeafNotEdge(head, lc, rc, edges, 0);

	// 打印右边界
	for (int i = h - 1; i >= 0; i--) {
		if (edges[2 * i] != edges[2 * i + 1]) {
			printf("%d ", edges[2 * i + 1]);
		}
	}
	printf("\n");
	delete[]edges;
}

void printLeftEdge(int head, int* lc, int* rc, bool print) {
	if (head == 0) {
		return;
	}

	if (print || (lc[head] == 0 && rc[head] == 0)) {
		printf("%d ", head);
	}
	printLeftEdge(lc[head], lc, rc, print);
	printLeftEdge(rc[head], lc, rc, print && lc[head] == 0 ? true : false);
}

void printRightEdge(int head, int* lc, int* rc, bool print) {
	if (head == 0) {
		return;
	}
		
	printRightEdge(lc[head], lc, rc, print && rc[head] == 0 ? true : false);
	printRightEdge(rc[head], lc, rc, print);
	if (print || (lc[head] == 0 && rc[head] == 0)) {
		printf("%d ", head);
	}
}

void print2(int head, int* lc, int* rc) {
	// 我没看懂第二种标准是什么意思，直接复制书上代码了
	if (head == 0) {
		return;
	}
	printf("%d ", head);
	if (lc[head] != 0 && rc[head] != 0) {
		printLeftEdge(lc[head], lc, rc, true);
		printRightEdge(rc[head], lc, rc, true);
	}
	else {
		print2(lc[head] != 0 ? lc[head] : rc[head], lc, rc);
	}
	printf("\n");
}


int main()
{
	int n, root, t;
	cin >> n >> root;
	int* lc = new int[n + 1];
	int* rc = new int[n + 1];
	
	for (int i = 0; i < n; i++) {
		cin >> t;
		cin >> lc[t] >> rc[t];
	}
	print1(root, lc, rc);
	print2(root, lc, rc);
	delete[]lc, rc;
	return 0;
}
