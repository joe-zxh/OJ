/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    int TreeDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
    
        if (root->left==NULL&&root->right==NULL) {
            return 1;
        }
        
        int lh = TreeDepth(root->left);
        int rh = TreeDepth(root->right);
        
        return lh > rh ? lh + 1 : rh + 1;
    }
};