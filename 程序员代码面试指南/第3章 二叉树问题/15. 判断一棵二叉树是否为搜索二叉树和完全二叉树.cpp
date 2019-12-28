#include <iostream>
#include <stack>
#include <queue>
using namespace std;
 
long n, root, temp;
long cur = 0;
 
bool isSearchTree(long root, long *lcs, long *rcs) { // 判断方法：中序遍历的值是递增的。
    long head = root;
    stack<long> nodes;
     
    while (!nodes.empty() || head != 0) {
        if (head != 0) {
            nodes.push(head);
            head = lcs[head];
        }
        else {
            if (cur > nodes.top()) {
                return false;
            }
            cur = nodes.top();
            nodes.pop();
            head = rcs[cur];
        }
    }
    cur = 0;
    return true;
}
 
bool isCompleteTree(long root, long *lcs, long *rcs) { // 判断方法：层序遍历。
    long temp;
    queue<long> q;
 
    q.push(root);
 
    bool swit = false; // 后续的节点是否应为 叶子节点
 
    while (!q.empty()) {
        temp = q.front();
        q.pop();
 
        if (swit) { // 后面的节点都是叶子节点
            if (lcs[temp] != 0 || rcs[temp] != 0) {
                return false;
            }
        }
        else {
            if (lcs[temp] == 0 && rcs[temp] != 0) { // 有右孩子，没有左孩子。
                return false;
            }
            else if (lcs[temp] == 0 || rcs[temp] == 0) { // 有左没右，或者 左右都没有
                swit = true;
                if (lcs[temp] != 0) {
                    q.push(lcs[temp]);
                }
            }
            else { // 2个孩子都有
                q.push(lcs[temp]);
                q.push(rcs[temp]);
            }
        }
    }
 
    return true;
}
 
int main()
{
    cin >> n >> root;
 
    long* lcs = new long[n + 1];
    long* rcs = new long[n + 1];
 
    for (long i = 1; i <= n; i++) {
        cin >> temp;
        cin >> lcs[temp] >> rcs[temp];
    }
 
    if (isSearchTree(root, lcs, rcs)) {
        printf("true\n");
    }
    else {
        printf("false\n");
    }
 
    if (isCompleteTree(root, lcs, rcs)) {
        printf("true\n");
    }
    else {
        printf("false\n");
    }
     
    delete[]lcs, rcs;
    return 0;
}