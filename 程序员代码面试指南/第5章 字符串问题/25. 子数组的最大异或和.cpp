#include <iostream>
#include <algorithm>
using namespace std;
 
class Node {
public:
    Node *childs[2];
    Node() {
        childs[0] = NULL;
        childs[1] = NULL;
    }
};
 
void addNode(Node *head, int eorSum) {
    int bit;
    Node *cur = head;
    for (int i = 31; i >= 0; i--) {
        bit = ((eorSum >> i) & 1); // 从最高位开始 拿位
        if (cur->childs[bit] == NULL) {
            cur->childs[bit] = new Node();
        }
        cur = cur->childs[bit];
    }
}
 
int findMaxEOR(Node *head, int eorSum) {
    int bit, path;
    int res = 0;
    Node *cur = head;
    for (int i = 31; i >= 0; i--) {
        bit = ((eorSum >> i) & 1); // 从最高位开始 拿位
        path = (i == 31 ? bit : (bit ^ 1)); // path是期望的路线, 区分一下符号位
        path = cur->childs[path] != NULL ? path : (path ^ 1); // 实际路线
        res |= ((path^bit) << i);
        cur = cur->childs[path];
    }
    return res;
}
 
int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
 
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
 
    int maxEOR = arr[0];
    int eorSum = arr[0];
 
    Node *head = new Node();
    addNode(head, eorSum);
 
    for (int i = 1; i < n; i++) {
        eorSum ^= arr[i];
        maxEOR = max(maxEOR, findMaxEOR(head, eorSum));
        addNode(head, eorSum);
    }
 
    cout << maxEOR << endl;
    delete[]arr;
    return 0;
}
