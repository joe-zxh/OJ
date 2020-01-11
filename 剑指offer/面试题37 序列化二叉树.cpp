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
    
    TreeNode* Deserialize(char* str) {
        if (str == NULL) {
            return NULL;
        }

        int val = 0;
        int ind = 0;

        while (str[ind] != '!') { // 第一个节点不会是空 #		
            val = 10 * val + str[ind] - '0';
            ind++;
        }
        ind++;

        TreeNode* head = new TreeNode(val);
        val = 0;

        queue<TreeNode*> q;
        q.push(head);

        TreeNode* cur;

        while (!q.empty()) {
            cur = q.front();
            q.pop();

            if (str[ind] != '#') {
                while (str[ind] != '!') {		
                    val = 10 * val + str[ind] - '0';
                    ind++;
                }
                ind++;
                cur->left = new TreeNode(val);
                val = 0;
                q.push(cur->left);
            }
            else {
                ind += 2;
                cur->left = NULL;
            }

            if (str[ind] != '#') {
                while (str[ind] != '!') {	
                    val = 10 * val + str[ind] - '0';
                    ind++;
                }
                ind++;
                cur->right = new TreeNode(val);
                val = 0;
                q.push(cur->right);
            }
            else {
                ind += 2;
                cur->right = NULL;
            }
        }
        return head;
    }
};