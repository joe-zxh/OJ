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
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {

        if(k==0||pListHead==NULL){
            return NULL;
        }

        int t = k;

        ListNode *fast = pListHead;
        t--;
        while(t--){
            if(fast==NULL){
                return NULL;
            }else{
                fast = fast->next;
            }
        }

        ListNode *slow = NULL;
        while(fast){
            slow = slow==NULL?pListHead:slow->next;
            fast = fast->next;
        }
        return slow;
    }
};