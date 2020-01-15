/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    TreeNode* KthNodeCore(TreeNode* pRoot, int &k) {
        if(pRoot==NULL){
            return NULL;
        }

        TreeNode* p = KthNodeCore(pRoot->left, k);

        if(p==NULL){
            if((--k)==0){
                return pRoot;
            }
        }else{
            return p;
        }

        p = KthNodeCore(pRoot->right, k);
        return p;        
    }

    TreeNode* KthNode(TreeNode* pRoot, int k) {
        return KthNodeCore(pRoot, k);
    }
};