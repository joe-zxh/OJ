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
			if (i == n) {
				new_pnode->next = phead;
			}
		}
	}
	return phead;
}


list_node* insert_num(list_node* head, int num)
{
	//////在下面完成代码
	list_node* t=NULL, *t2;
	t = new list_node;
	t->val = num;

	if (head == head->next) {//只有一个节点
		t->next = head;
		head->next = t;

		if (num < head->val) {
			return t;			
		}
		else {
			return head;
		}
	}
	
	list_node *cur = head, *next = cur->next;
	bool insert = false;
	while (next != head) {
		if (cur->val <= num && num <= next->val) {
			cur->next = t;
			t->next = next;
			insert = true;
			break;
		}
		else {
			t2 = next;
			next = cur->next;
			cur = t2;
		}
	}

	if (!insert) {
		cur->next = t;
		t->next = next;
	}

	return head;
}


void print_list(list_node* head)
{
	list_node* h = head;
	while (1) {
		printf("%d ", head->val);
		if (head->next == h) break;
		head = head->next;
	}
	puts("");
}


int main()
{
	list_node* head = input_list();
	int n;
	scanf("%d", &n);
	list_node* new_head = insert_num(head, n);
	print_list(new_head);
	return 0;
}