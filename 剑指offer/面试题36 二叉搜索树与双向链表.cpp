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
    void f(TreeNode* head, TreeNode* &lr, TreeNode* &rr) {

        TreeNode* n1 = NULL, * n2 = NULL;

        if (head->left) {
            f(head->left, n1, n2);
            lr = n1;

            n2->right = head;
            head->left = n2;
        }
        else {
            head->left = NULL;
            lr = head;
        }

        if (head->right) {
            f(head->right, n1, n2);

            head->right = n1;
            n1->left = head;
            rr = n2;
        }
        else {
            head->right = NULL;
            rr = head;
        }
    }

    TreeNode* Convert(TreeNode* pRootOfTree) {
        if (pRootOfTree == NULL) {
            return NULL;
        }

        TreeNode* n1 = NULL, * n2 = NULL;
        f(pRootOfTree, n1, n2);
        return n1;
    }
};