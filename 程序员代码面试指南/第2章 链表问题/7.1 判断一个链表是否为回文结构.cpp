# include <bits/stdc++.h>
# include <stack>
using namespace std;
 
struct list_node{
    int val;
    struct list_node * next;
};
 
list_node * input_list(void)
{
    int n, val;
    list_node * phead = new list_node();
    list_node * cur_pnode = phead;
    scanf("%d", &n);
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
 
 
list_node * check(list_node * head)
{
    stack<int>temp;
 
    list_node *p = head;
    while (p) {
        temp.push(p->val);
        p = p->next;
    }
    p = head;
    while (p) {
        if (p->val != temp.top()) {
            printf("false\n");
            return NULL;
        }
         
        temp.pop();
        p = p->next;
    }
 
    printf("true\n");
    return NULL;
}
 
 
int main ()
{
    int L, R;
    list_node * head = input_list();
    check(head);
    return 0;
}