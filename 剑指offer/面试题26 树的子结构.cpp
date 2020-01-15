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
bool HasSubtreeCore(TreeNode* pRoot1, TreeNode* pRoot2) {

    if(pRoot2==NULL){
        return true;
    }else if(pRoot1==NULL){ // pRoot2!=NULL
        return false;
    }

    bool ret = false;

    if(pRoot1->val==pRoot2->val){
        ret = ret || (HasSubtreeCore(pRoot1->left, pRoot2->left) && 
            HasSubtreeCore(pRoot1->right, pRoot2->right));
    }

    if(ret == true){
        return true;
    }else{
        return HasSubtreeCore(pRoot1->left, pRoot2) || HasSubtreeCore(pRoot1->right, pRoot2);
    }
}

bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2) {
    if(pRoot2==NULL){
        return false;
    }    
    return HasSubtreeCore(pRoot1, pRoot2);
}
};