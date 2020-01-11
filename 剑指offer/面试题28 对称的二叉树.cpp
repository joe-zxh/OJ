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
    void Mirror(TreeNode *pRoot) {
        if(pRoot==NULL){
            return;
        }

        Mirror(pRoot->left);
        Mirror(pRoot->right);

        TreeNode* t = pRoot->left;
        pRoot->left = pRoot->right;
        pRoot->right = t;	
    }

    char* Serialize(TreeNode* root) {
        if (root == NULL) {
            return NULL;
        }
        string str = "";
        queue<TreeNode*> q;
        q.push(root);

        TreeNode* cur = NULL;

        while (!q.empty()) { // 层序遍历
            cur = q.front();
            q.pop();

            if (cur == NULL) {
                str = str + "#!";
            }
            else {
                str = str+to_string(cur->val) + "!";
                q.push(cur->left);
                q.push(cur->right);
            }
        }

        int sz = str.size();
        char* ch = new char[sz + 1];
        ch[sz] = '\0';
        str.copy(ch, sz);
        return ch;
    }

    bool isSymmetrical(TreeNode* pRoot){
        if(pRoot==NULL){
            return true;
        }
        char *a = Serialize(pRoot);
        Mirror(pRoot);
        char *b = Serialize(pRoot);
        Mirror(pRoot);// 调整回来

        int ind = 0;

        while(true){
            if(a[ind]=='\0'&&b[ind]=='\0'){
                return true;
            }
            if(a[ind]!=b[ind]){
                return false;
            }
            ind++;
        }
    }
};