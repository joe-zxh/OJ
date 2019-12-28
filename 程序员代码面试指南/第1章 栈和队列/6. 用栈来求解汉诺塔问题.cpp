#include <iostream>
#include <stack>
using namespace std;

long move(int &lastAction, int noAction, int curAction, stack<int>&fromstack, stack<int>&tostack, char* from, char* to) {
	if (lastAction != noAction &&fromstack.top()<tostack.top() ) {
		printf("Move %d from %s to %s\n", fromstack.top(), from, to);
		tostack.push(fromstack.top());
		fromstack.pop();
		lastAction = curAction;
		return 1;
	}
	return 0;
}

void f(int n) {
	int lastAction = -1;// 0: L->M  1:M->L  2:R->M  3: M->R
	
	stack<int>ls, ms, rs;
	ls.push(13); // 设置最下面那个为无限大
	ms.push(13);
	rs.push(13);

	for (int i = n; i >= 1; i--) {
		ls.push(i);
	}
	long steps = 0;
	while (rs.size() != n + 1) {
		steps+=move(lastAction, 0, 1, ls, ms, "left", "mid");
		steps += move(lastAction, 1, 0, ms, ls, "mid", "left");
		steps += move(lastAction, 2, 3, rs, ms, "right", "mid");
		steps += move(lastAction, 3, 2, ms, rs, "mid", "right");
	}
	printf("It will move %d steps.\n", steps);
}

int main() {
	int n;
	cin >> n;
	f(n);
	return 0;
}