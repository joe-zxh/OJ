/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> res;

        if(head==NULL){
            return res;
        }

        if(head->next==NULL){
            res[0] = head->val;
            return res;
        }

        ListNode *curNode=head, *nextNode=head->next, *t;
        curNode->next = NULL;

        while(nextNode){ // 逆序一下
            t = nextNode->next;
            nextNode->next = curNode;
            curNode = nextNode;
            nextNode = t;
        }

        nextNode = curNode->next;
        curNode->next = NULL;

        while(nextNode){ // 恢复原来的顺序
            res.push_back(curNode->val);
            t = nextNode->next;
            nextNode->next = curNode;
            curNode = nextNode;
            nextNode = t;
        }
        res.push_back(curNode->val);
    }
};