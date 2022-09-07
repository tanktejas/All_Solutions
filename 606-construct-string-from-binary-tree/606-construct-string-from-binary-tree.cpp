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
    string ans;
    
    void find(TreeNode* root)
    {
        if(!root)
        {
            return ;
        }
        
        if(root->left==NULL and root->right==NULL) {
            ans+='('+to_string(root->val)+')';
            return ; 
        }
        
         ans=ans+'('+to_string(root->val);
        
        
        if(root->left==NULL and root->right!=NULL)
        {
            ans+="()"; 
        }
        
       
        find(root->left);
        find(root->right);
        
        ans=ans+')';   
        
    }
    
    string tree2str(TreeNode* root) {
        ans="";
        find(root);
        return ans.substr(1,ans.length()-2);   
    }
};