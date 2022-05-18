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
    int ans=0;
    
    void find(TreeNode* root,int temp){
        if(!root){
            return ;
        }
        
        if(root->left==NULL and root->right==NULL){
            temp=temp*10 + root->val;
            ans+=temp; 
            return ;
        }
         
        temp=temp*10 + root->val;
        
        find(root->left,temp);
        find(root->right,temp);
        
        
    }
    
    int sumNumbers(TreeNode* root) {
       ans=0;
        
        find(root,0);
        
        return ans;
    }
};