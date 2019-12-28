#include <iostream>
using namespace std;

class Node {
public:
	long val;
	Node* lc, * rc;
};

void Morris(Node* head) {
	Node* cur = head;

	while (cur) {
		if (cur->lc) { // 有左孩子，寻找左孩子的最右 节点

			Node* mostRight = cur->lc;

			while (mostRight->rc != NULL && mostRight->rc != cur) {
				mostRight = mostRight->rc;
			}

			if (mostRight->rc == NULL) { // 第一次来到这个节点
				mostRight->rc = cur;
				cur = cur->lc;
			}
			else { // 第二次来到这个节点
				mostRight->rc = NULL;
				cur = cur->rc;
			}
		}
		else { // 没有左孩子，直接打印
			cur = cur->rc;
		}
	}
	printf("\n");
}

void MorrisPre(Node* head) {
	Node* cur = head;

	while (cur) {
		if (cur->lc) { // 有左孩子，寻找左孩子的最右 节点

			Node* mostRight = cur->lc;

			while (mostRight->rc != NULL && mostRight->rc != cur) {
				mostRight = mostRight->rc;
			}

			if (mostRight->rc == NULL) { // 第一次来到这个节点
				mostRight->rc = cur;
				printf("%d ", cur->val);
				cur = cur->lc;
			}
			else { // 第二次来到这个节点
				mostRight->rc = NULL;
				cur = cur->rc;
			}
		}
		else { // 没有左孩子，直接打印
			printf("%d ", cur->val);
			cur = cur->rc;
		}		
	}
	printf("\n");
}

void MorrisMid(Node* head) {
	Node* cur = head;

	while (cur) {
		if (cur->lc) { // 有左孩子，寻找左孩子的最右 节点

			Node* mostRight = cur->lc;

			while (mostRight->rc != NULL && mostRight->rc != cur) {
				mostRight = mostRight->rc;
			}

			if (mostRight->rc == NULL) { // 第一次来到这个节点
				mostRight->rc = cur;
				cur = cur->lc;
			}
			else { // 第二次来到这个节点
				mostRight->rc = NULL;
				printf("%d ", cur->val);
				cur = cur->rc;
			}
		}
		else { // 没有左孩子，直接打印
			printf("%d ", cur->val);
			cur = cur->rc;
		}
	}
	printf("\n");
}

Node* reverseEdge(Node* head) {
	Node* last = NULL, * cur = head, * next;

	while (cur != NULL) {
		next = cur->rc;
		cur->rc = last;
		last = cur;
		cur = next;
	}
	return last;
}

void printEdge(Node* head) {
	Node* tail = reverseEdge(head);
	Node* cur = tail;

	while (cur) {
		printf("%d ", cur->val);
		cur = cur->rc;
	}
	reverseEdge(tail);
}

void MorrisPost(Node* head) {
	Node* cur = head;

	while (cur) {
		if (cur->lc) { // 有左孩子，寻找左孩子的最右 节点

			Node* mostRight = cur->lc;

			while (mostRight->rc != NULL && mostRight->rc != cur) {
				mostRight = mostRight->rc;
			}

			if (mostRight->rc == NULL) { // 第一次来到这个节点
				mostRight->rc = cur;
				cur = cur->lc;
			}
			else {
				mostRight->rc = NULL;
				printEdge(cur->lc); // 打印左孩子为头的右边界
				cur = cur->rc;
			}
		}
		else { // 没有左孩子
			cur = cur->rc;
		}
	}
	printEdge(head);
	printf("\n");
}

int main() {
	long n, root, a, b, c;
	cin >> n >> root;

	Node* nodes = new Node[n+1];

	for (long i = 1; i <= n; i++) {
		nodes[i].val = i;
		cin >> a >> b >> c;
		nodes[a].lc = b == 0 ? NULL : &nodes[b];
		nodes[a].rc = c == 0 ? NULL : &nodes[c];
	}

	MorrisPre(&nodes[root]);
	MorrisMid(&nodes[root]);
	MorrisPost(&nodes[root]);

	delete[]nodes;
	return 0;
}