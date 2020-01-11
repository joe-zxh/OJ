/*
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};
*/
class Solution {
public:
    // 如果有右孩子，那么是右孩子的最左节点
    // 如果没有右孩子，那么 找到第一个左孩子 为 当前子树的 节点。
    TreeLinkNode* GetNext(TreeLinkNode* pNode) {
        if(pNode->right!=NULL) {
            TreeLinkNode* leftmost = pNode->right;
            while(leftmost->left){
                leftmost = leftmost->left;
            }
            return leftmost;
        }else{
            TreeLinkNode* cur = pNode;
            TreeLinkNode* father = cur->next;

            while(father){
                if(father->left==cur){
                    return father;
                }else{
                    cur = father;
                    father = cur->next;
                }
            }
            return NULL; // 当前节点是最后的节点，没有下一个节点
        }
    }
};