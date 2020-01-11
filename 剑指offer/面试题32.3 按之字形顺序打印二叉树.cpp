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
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int> > v;
        if(pRoot==NULL){
            return v;
        }
        list<TreeNode*> q;
        q.push_back(pRoot);
        bool popFront = false;

        TreeNode *t;

        int curNum = 0;
        int nextNum = 1;

        vector<int> *vi=NULL;

        while(!q.empty()) {
            if(curNum==0){
                curNum = nextNum-1;
                nextNum = 0;
                if(vi!=NULL){
                    v.push_back(*vi);
                }
                vi = new vector<int>;
                popFront = (!popFront);
            }else{
                curNum--;
            }

            if(popFront){
                t = q.front();
                q.pop_front();
            }else{
                t = q.back();
                q.pop_back();
            }

            vi->push_back(t->val);

            if(popFront){
                if(t->left!=NULL){
                    nextNum++;
                    q.push_back(t->left);			
                }
                if(t->right!=NULL){
                    nextNum++;
                    q.push_back(t->right);
                }
            }else{			
                if(t->right!=NULL){
                    nextNum++;
                    q.push_front(t->right);
                }
                if(t->left!=NULL){
                    nextNum++;
                    q.push_front(t->left);			
                }
            }

        }
        v.push_back(*vi);
        return v;
    }    
};