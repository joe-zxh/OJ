class Solution {
public:
    int getHeight(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
    
        if (root->left==NULL&&root->right==NULL) {
            return 1;
        }
        
        int lh = getHeight(root->left);
        int rh = getHeight(root->right);
    
        if (lh==-1||rh==-1|| lh-rh>1 || rh-lh>1) { // 非平衡树
            return -1;
        }
    
        return lh > rh ? lh + 1 : rh + 1;
    }

    bool IsBalanced_Solution(TreeNode* pRoot) {
        return getHeight(pRoot)>=0;
    }
};