/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead) {
        if(pHead==NULL){
            return NULL;
        }

        map<RandomListNode*, RandomListNode*> m;
        // key: old node value: new node

        RandomListNode *newHead = new RandomListNode(pHead->label);
        RandomListNode *p1 = pHead, *p2 = newHead;
        m[pHead] = newHead;

        while(p1->next) { // 复制next指针，并设置map
            p2->next = new RandomListNode(p1->next->label);
            p2 = p2->next;
            p1 = p1->next;
            m[p1] = p2;
        }

        p1 = pHead; p2 = newHead;

        while(p1) {
            p2->random = m[p1->random];
            p2 = p2->next;
            p1 = p1->next;
        }
        return newHead;
    }
};