/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool dolevel(TreeNode* root){
        queue<TreeNode*>q;
        bool isnull=0;
        q.push(root);
        q.push(NULL);
        while(q.size()>1){
            if(q.front()==NULL){
                q.pop();
                q.push(NULL);
            }
            TreeNode* curr=q.front();
            q.pop();
            if(curr->left==NULL){
                isnull=1;
            }else{
                if(isnull) return 0;
                else{
                    q.push(curr->left);
                }
            }
            if(curr->right==NULL){
                isnull=1;
            }else{
                if(isnull) return 0;
                else{
                    q.push(curr->right);
                }
            }
        }
        return 1;
    } 
    bool isCompleteTree(TreeNode* root) {
       return dolevel(root);    
    }
};