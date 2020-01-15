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
    ListNode* deleteDuplication(ListNode* pHead) {
        if(pHead==NULL){
            return NULL;
        }

        ListNode*ppHead = new ListNode(pHead->val-1); // 弄一个假头节点
        ppHead->next = pHead;

        ListNode* pre = ppHead, *cur = pHead;

        int need2Del = pre->val;

        while(cur){
            if(cur->val==need2Del){
                // 删除当前节点
                pre->next = cur->next;
                delete cur;
                cur = cur->next;

            }else if(cur->next && cur->val==cur->next->val){
                // 删除当前节点
                pre->next = cur->next;
                delete cur;
                cur = cur->next;

                need2Del = cur->val;
            }else{
                pre = cur;
                cur = cur->next;
            }
        }
        return ppHead->next;
    }
};