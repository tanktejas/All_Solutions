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
    void find(TreeNode* root,int curr,int &pre,int &val){
        if(!root) return ;
        if(root->left==NULL and root->right==NULL){
           if(pre==-1){
              pre=curr;
              val=root->val;
           }else if(curr>pre){
               pre=curr;
               val=root->val;
           }
        
        }
        find(root->left,curr+1,pre,val);
        find(root->right,curr+1,pre,val);
        
    }
    int findBottomLeftValue(TreeNode* root) {
         int val=0;
        int curr=0;
        int pre=-1;
        find(root,curr,pre,val);
        return val;
    }
};