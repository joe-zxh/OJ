/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
        if(pHead1==NULL){
            return pHead2;
        }

        if(pHead2==NULL){
            return pHead1;
        }

        ListNode*p1 = pHead1, *p2 = pHead2, *retHead=NULL, *rp;

        while(p1&&p2){
            if(p1->val<p2->val){
                if(retHead==NULL){
                    retHead=p1;
                }else{
                    rp->next = p1;
                }
                rp = p1;
                p1 = p1->next;
            }else{
                if(retHead==NULL){
                    retHead=p2;
                }else{
                    rp->next = p2;
                }
                rp = p2;
                p2 = p2->next;
            }
        }

        if(p1==NULL){
            rp->next = p2;
        }
        if(p2==NULL){
            rp->next = p1;
        }
        return retHead;
    }
};