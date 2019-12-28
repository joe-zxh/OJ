# include <iostream>
using namespace std;

struct list_node {
	int val;
	struct list_node* next;
};


list_node* input_list(void)
{
	int n, val;
	list_node* phead = new list_node();
	list_node* cur_pnode = phead;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &val);
		if (i == 1) {
			cur_pnode->val = val;
			cur_pnode->next = NULL;
		}
		else {
			list_node* new_pnode = new list_node();
			new_pnode->val = val;
			new_pnode->next = NULL;
			cur_pnode->next = new_pnode;
			cur_pnode = new_pnode;
		}
	}
	return phead;
}


list_node* relocate(list_node* head)
{
	//////在下面完成代码
	if (head->next == NULL || head->next->next == NULL) {
		return head;
	}

	list_node* p1=head, * p2=head->next;

	while (true) {
		if (p2->next == NULL) { // p2走2步
			break;
		}
		else {
			p2 = p2->next;
			if (p2->next == NULL) {
				break;
			}
			else {
				p2 = p2->next;
			}
		}
		p1 = p1->next;
	}
	p2 = p1->next;
	p1 = head;

	list_node* t=NULL, *t2=p2;
	list_node* h = new list_node(), *c;
	h->val = p1->val;
	p1 = p1->next;

	c = new list_node();
	c->val = p2->val;
	p2 = p2->next;
	h->next = c;

	while (p1 != t2) {
		t = new list_node();
		t->val = p1->val;
		p1 = p1->next;
		c->next = t;
		c = c->next;

		t = new list_node();
		t->val = p2->val;
		p2 = p2->next;
		c->next = t;
		c = c->next;
	}

	if (p2!=NULL) { // 右边可能会多出一个节点
		t = new list_node();
		t->val = p2->val;
		p2 = p2->next;
		c->next = t;
		c = c->next;
	}
	return h;
}


void print_list(list_node* head)
{
	while (head != NULL) {
		printf("%d ", head->val);
		head = head->next;
	}
	puts("");
}


int main()
{
	list_node* head = input_list();
	list_node* new_head = relocate(head);
	print_list(new_head);
	return 0;
}