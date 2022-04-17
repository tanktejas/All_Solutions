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
    TreeNode* temp=NULL;
    TreeNode* ree=NULL;
    TreeNode* rearrange(TreeNode* root,TreeNode* dumm){
        if(!root) return dumm;
        
       dumm=rearrange(root->left,dumm);
        dumm->right=root;
        root->left=NULL;
        dumm=dumm->right;
      return rearrange(root->right,dumm);
        
    }
    TreeNode* increasingBST(TreeNode* root) { 
        TreeNode* dumm=new TreeNode(0); 
        TreeNode* temp=dumm;
        rearrange(root,temp);  
        return dumm->right;
        
    }
};