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
    void f(TreeNode* root, int expectNumber,
        vector<vector<int> >& retv, vector<int>& path, int& cursum) {

        if (root == NULL) {
            return;
        }

        path.push_back(root->val);
        cursum += root->val;

        if (cursum==expectNumber && root->left==NULL && root->right==NULL) {
            vector<int> *v = new vector<int> (path.begin(), path.end());
            retv.push_back(*v);
        }

        f(root->left, expectNumber, retv, path, cursum);
        f(root->right, expectNumber, retv, path, cursum);

        path.pop_back();
        cursum -= root->val;
    }

    vector<vector<int> > FindPath(TreeNode* root, int expectNumber) {
        vector<vector<int> > retv;

        if (root == NULL) {
            return retv;
        }

        vector<int> path;
        int cursum = 0;

        f(root, expectNumber, retv, path, cursum);
        return retv;
    }
};
