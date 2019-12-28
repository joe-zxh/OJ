# include <iostream>
# include <vector>
using namespace std;
 
struct list_node {
    int val;
    struct list_node * next;
};
 
int pivot, n;
 
list_node * input_list(void)
{
    int val;
    list_node * phead = new list_node();
    list_node * cur_pnode = phead;
    scanf("%d%d", &n, &pivot);
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
 
list_node * list_partition(list_node * head, int pivot)
{
    //////在下面完成代码
    int *container=new int[n];
    list_node *p = head;
 
    long iter = 0;
    while (p) {
        container[iter++] = p->val;
        p = p->next;
    }
 
    long sz = iter;
    long less=-1, more= sz;
    iter = 0;
    int temp;
 
    while (iter<more) {
        if (container[iter] < pivot) {
            less++;
            temp = container[less];
            container[less] = container[iter];
            container[iter] = temp;
            iter++;
        }
        else if (container[iter]>pivot) {
            more--;
            temp = container[more];
            container[more] = container[iter];
            container[iter] = temp;
        }
        else {
            iter++;
        }      
    }
 
    for (long i = 0; i < sz;i++) {
        printf("%d ", container[i]);
    }
 
    delete[]container;
    return NULL;
}
 
int main()
{
    list_node * head = input_list();
    list_partition(head, pivot);
    return 0;
}
