// # include <bits/stdc++.h>
#include <iostream>
#include<map>
using namespace std;

struct double_list_node {
	int val;
	struct double_list_node * pre, *next;
};

struct BST {
	int val;
	struct BST * lch, *rch;
};

BST * input_BST()
{
	int n, fa, lch, rch;
	scanf("%d", &n);
	BST * root, *new_node;
	root = NULL;
	map<int, BST *> mp;
	for (int i = 1; i <= n; ++i) {
		scanf("%d %d %d", &fa, &lch, &rch);
		if (mp.find(fa) == mp.end()) {
			new_node = (BST *)malloc(sizeof(BST));
			mp[fa] = new_node;
			new_node->val = fa;
			if (i == 1) root = new_node;
		}
		if (lch && mp.find(lch) == mp.end()) {
			new_node = (BST *)malloc(sizeof(BST));
			mp[lch] = new_node;
			new_node->val = lch; new_node->lch = new_node->rch = NULL;
		}
		if (rch && mp.find(rch) == mp.end()) {
			new_node = (BST *)malloc(sizeof(BST));
			mp[rch] = new_node;
			new_node->val = rch; new_node->lch = new_node->rch = NULL;
		}
		mp[fa]->lch = (lch ? mp[lch] : NULL);
		mp[fa]->rch = (rch ? mp[rch] : NULL);
	}
	return root;
}

void process(BST * root, double_list_node *&head, double_list_node *&tail) {
	if (root->lch == NULL&&root->rch == NULL) { // 左右孩子都空
		double_list_node *p = new double_list_node();
		p->val = root->val;
		p->pre = p->next = NULL;
		head = tail = p;
		return;
	}

	if (root->lch != NULL&&root->rch == NULL) { // 左孩子非空，右孩子空
		process(root->lch, head, tail);

		double_list_node *p = new double_list_node();
		p->val = root->val;
		p->pre = tail;
		p->next = NULL;
		tail->next = p;
		tail = p;
		return;
	}

	if (root->lch == NULL&&root->rch != NULL) { // 左孩子空，右孩子非空
		process(root->rch, head, tail);

		double_list_node *p = new double_list_node();
		p->val = root->val;
		p->pre = NULL;
		p->next = head;
		head->pre = p;
		head = p;

		return;
	}

	if (root->lch != NULL&&root->rch != NULL) { // 左右都不空
		double_list_node *p = new double_list_node();
		p->val = root->val;		
		process(root->lch, head, tail);
		tail->next = p;
		p->pre = tail;

		double_list_node *hh=NULL;
		process(root->rch, hh, tail);

		p->next = hh;
		hh->pre = p;
		return;
	}
}

double_list_node * convert(BST * root)
{
	//////在下面完成代码
	double_list_node *head=NULL, *tail=NULL;
	process(root, head, tail);
	return head;
}

void print_double_list(double_list_node * head)
{
	while (head != NULL) {
		printf("%d ", head->val);
		head = head->next;
	}
	puts("");
}

int main()
{
	BST * root = input_BST();
	double_list_node * new_double_head = convert(root);
	print_double_list(new_double_head);
	return 0;
}