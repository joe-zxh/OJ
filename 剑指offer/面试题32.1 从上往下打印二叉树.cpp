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
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<int> retv;
        if(root==NULL){
            return retv;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        TreeNode *t;
        while(!q.empty()) {
            t = q.front();
            q.pop();
            retv.push_back(t->val);
            if(t->left!=NULL){
                q.push(t->left);
            }
            if(t->right!=NULL){
                q.push(t->right);
            }
        }
        return retv;
    }
};