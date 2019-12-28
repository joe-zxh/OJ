# include <bits/stdc++.h>
using namespace std;

struct list_node{
    int val;
    struct list_node * next;
};

list_node * input_list(int n)
{
    int val;
    list_node * phead = new list_node();
    list_node * cur_pnode = phead;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &val);
        if (i == 1) {
            cur_pnode->val = val;
            cur_pnode->next = NULL;
        }
        else {
            list_node * new_pnode = new list_node();
            new_pnode->val = val;
            new_pnode->next = NULL;
            cur_pnode->next = new_pnode;
            cur_pnode = new_pnode;
        }
    }
    return phead;
}


list_node* add_list(list_node* head1, list_node* head2)
{
	//////在下面完成代码
	stack<int>l1, l2;
	list_node* cur = head1;
	while (cur) {
		l1.push(cur->val);
		cur = cur->next;
	}

	cur = head2;
	while (cur) {
		l2.push(cur->val);
		cur = cur->next;
	}

	list_node* ret=NULL;
	int jin = 0;//进位
	int v;
	while (!l1.empty() && !l2.empty()) { // 2个stack都有东西
		v = l1.top() + l2.top() + jin;
		l1.pop(); l2.pop();
		jin = v / 10;
		v %= 10;

		list_node *a = new list_node;
		a->val = v;
		a->next = ret;
		ret = a; // 从前面插入链表
	}
	
	while (!l1.empty()) {
		v = l1.top() + jin;
		l1.pop();
		jin = v / 10;
		v %= 10;

		list_node* a = new list_node;
		a->val = v;
		a->next = ret;
		ret = a; // 从前面插入链表
	}

	while (!l2.empty()) {
		v = l2.top() + jin;
		l2.pop();
		jin = v / 10;
		v %= 10;

		list_node* a = new list_node;
		a->val = v;
		a->next = ret;
		ret = a; // 从前面插入链表
	}

	if (jin != 0) {
		list_node* a = new list_node;
		a->val = jin;
		a->next = ret;
		ret = a; // 从前面插入链表
	}

	return ret;
}


void print_list(list_node * head)
{
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
    puts("");
}

int main ()
{
    int n, m;
    scanf("%d%d", &n, &m);
    list_node * head1 = input_list(n), * head2 = input_list(m);
    list_node * new_head = add_list(head1, head2);
    print_list(new_head);
    return 0;
}