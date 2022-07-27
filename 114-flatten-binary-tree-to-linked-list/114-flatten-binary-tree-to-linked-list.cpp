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
    void conv(TreeNode* root)
    {
        if(root==NULL or (!root->left and !root->right)) return ;
        
        conv(root-> left);
        conv(root->right);
        
        if(root->left!=NULL){
            TreeNode* lf=root->left;
        TreeNode* rg=root->right;
        
        root->left=NULL;
        root->right=lf;
        TreeNode* lastfromleft=NULL;
        
        while(lf and lf->right)
        {
            lf=lf->right;
        }
        
        lastfromleft=lf;    
        lastfromleft->right=rg;
         
            
        }
        
        
    }
    
    void flatten(TreeNode* root) {
        
        conv(root);   
    }
};