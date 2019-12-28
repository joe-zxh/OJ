#include <iostream>
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


list_node* merge_list(list_node* head1, list_node* head2)
{
	//////在下面完成代码
	list_node* c1 = head1, * c2 = head2;
	list_node* head = NULL, * c = NULL, * t = NULL;
		
	while (c1 && c2) {
		if (c1->val < c2->val) {
			t = new list_node;
			t->val = c1->val;
			t->next = NULL;
			c1 = c1->next;
			
			if (head == NULL) {
				head = c = t;
			}
			else {
				c->next = t;
				c = t;
			}
		}
		else {
			t = new list_node;
			t->val = c2->val;
			t->next = NULL;
			c2 = c2->next;

			if (head == NULL) {
				head = c = t;
			}
			else {
				c->next = t;
				c = t;
			}
		}
	}

	while (c1) {
		t = new list_node;
		t->val = c1->val;
		t->next = NULL;
		c1 = c1->next;

		if (head == NULL) {
			head = c = t;
		}
		else {
			c->next = t;
			c = t;
		}
	}

	while (c2) {
		t = new list_node;
		t->val = c2->val;
		t->next = NULL;
		c2 = c2->next;

		if (head == NULL) {
			head = c = t;
		}
		else {
			c->next = t;
			c = t;
		}
	}

	return head;
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
	list_node* head1 = input_list();
	list_node* head2 = input_list();
	list_node* new_head = merge_list(head1, head2);
	print_list(new_head);
	return 0;
}