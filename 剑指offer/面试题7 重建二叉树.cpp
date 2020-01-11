/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* f(vector<int> pre, int pstart, int pend, 
        vector<int> vin, int vstart, int vend) {

        TreeNode* head = new TreeNode(pre[pstart]);

        if (pstart==pend) { // 叶子节点
            return head;
        }

        int leftsz = 0, rightsz = 0;
        int maxsz = pend-pstart+1;

        while(leftsz<maxsz) {
            if(vin[vstart+leftsz]!=pre[pstart]){
                leftsz++;
            }else{
                break;
            }
        }

        if(leftsz==maxsz) {
            cout<<"wrong input!"<<endl;
            return NULL;
        }

        rightsz = maxsz-leftsz-1;

        if(leftsz==0){
            head->left = NULL;
        }else{
            head->left = f(pre, pstart+1, pstart+leftsz,
                vin, vstart, vstart+leftsz-1);
        }

        if(rightsz==0){
            head->right = NULL;
        }else{
            head->right = f(pre, pstart+leftsz+1, pstart+leftsz+rightsz,
                vin, vstart+leftsz+1, vstart+leftsz+rightsz);
        }

        return head;
    }
    
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        if(pre.size()!=vin.size()){
            cout<<"wrong input!"<<endl;
            return NULL;
        }
        return f(pre, 0, pre.size()-1, vin, 0, vin.size()-1);
    }
};