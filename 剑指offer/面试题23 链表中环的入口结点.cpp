/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead){
        if (pHead==NULL || pHead->next==NULL) {
            return NULL; // 没有节点 或者 只有1个节点
        }

        if(pHead->next==pHead) {
            return pHead;//只有1个节点的环
        }

        ListNode* fast = pHead->next->next;
        ListNode* slow = pHead->next;

        while(fast!=slow){ // 找到环中的某一个点
            if(fast==NULL||fast==NULL){
                return NULL;
            }
            fast = fast->next->next;
            slow = slow->next;
        }

        int ringsz = 1;
        slow = slow->next;
        while(slow!=fast){ // 获得环的大小
            ringsz++;
            slow = slow->next;
        }

        slow = NULL;
        fast = NULL;
        while(ringsz--){ // fast先走ringsz步
            fast = fast==NULL?pHead:fast->next;
        }

        while(slow!=fast){ // slow和fast相遇的地方 就是 入口节点
            slow = slow==NULL?pHead:slow->next;
            fast=fast->next;
        }
        return slow;
    }
};