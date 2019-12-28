#include <iostream>
#include <string>

#define MINVAL 1 << (sizeof(long)*8-1)

using namespace std;

long getLeftChildRightMost(long head, long* left, long* right) {
	long p = left[head];

	while (right[p] != 0&&right[p]!=head) {
		p = right[p];
	}
	long res = right[p];
	if (res == 0) { // 第一次来到head节点
		right[p] = head;
	}
	else { // 第二次回到head节点
		right[p] = 0;
	}
	return res;
}

void MorrisMid(long root, long* left, long* right) {

	long e1, e2, t;

	long head = root;
	long pre = MINVAL; // 最小值
	e1 = e2 = MINVAL;

	while (head) {
		if (left[head]!=0&&getLeftChildRightMost(head, left, right) == 0) {
			head = left[head];
		}
		else { // 第二次来到这个节点，或者这个节点没有左孩子。			
			if (pre <= head) {
				pre = head;
			}
			else {
				if (e1 == MINVAL) {
					e1 = pre;
					pre = head;
					t = head;
				}
				else {
					e2 = head;
					break;
				}
			}
			head = right[head];
		}
	}
	if (e2 == MINVAL) {
		e2 = t;
	}
	if (e1 > e2) {
		t = e1;
		e1 = e2;
		e2 = t;
	}
	printf("%d %d\n", e1, e2);
}

int main() {
	long n, root, temp;
	cin >> n >> root;
	long *left = new long[n + 1];
	long *right = new long[n + 1];

	for (long i = 1; i <= n; i++) {
		cin >> temp;
		cin >> left[temp] >> right[temp];
	}
	MorrisMid(root, left, right);
	return 0;
}