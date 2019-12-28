#include <iostream>

using namespace std;

class Node {
public:
	int num;
	Node *prev, *next;
	Node(int n) {
		this->num = n;
		this->prev = NULL;
		this->next = NULL;
	}
};

int main()
{
	long n, m;
	cin >> n >> m;
	
	Node *head, *p, *t;
	head = p = new Node(1);

	for (long i = 2; i <= n; i++) {
		Node *t = new Node(i);
		p->next = t;
		t->prev = p;
		p = p->next;
	}
	p->next = head;
	head->prev = p;
	
	p = head;
	long count = 1;
	
	while (p->next != p) {
		if (count == m) {
			p->prev->next = p->next;
			p->next->prev = p->prev;
			Node *temp = p;
			p = p->next;
			delete temp;
			count = 1;
		}
		else {
			count++;
			p = p->next;
		}
	}
	cout << p->num << endl;
	return 0;
}