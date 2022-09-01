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
    int num;
    
    void find(TreeNode* root,int maxi)
    {
        if(!root){
            return ;
        }
        
        if(root->val >= maxi)
        {
            num++;
        }
        
        find(root->left,max(maxi,root->val));
        find(root->right,max(maxi,root->val));
        
    }
    
    int goodNodes(TreeNode* root) {
        num=0;
        int maxi=-1e5;
        
        find(root,maxi);
        return num;
    }
};