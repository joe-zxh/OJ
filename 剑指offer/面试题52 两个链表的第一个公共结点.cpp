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
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        int count1 = 0, count2 = 0, t, go;
        ListNode *n1=pHead1, *n2=pHead2;

        while(n1){
            count1++;
            n1=n1->next;
        }

        while(n2){
            count2++;
            n2=n2->next;
        }

        if(count1<count2){
            go = count2-count1;
            n1 = pHead2;
            n2 = pHead1;
        }else{
            go = count1-count2;
            n1 = pHead1;
            n2 = pHead2;
        }

        while(go--){
            n1 = n1->next;
        }

        while(n1){
            if(n1->val == n2->val){
                return n1;
            }
            n1 = n1->next;
            n2 = n2->next;
        }
        return NULL;        
    }
};