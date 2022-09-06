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
    TreeNode* find(TreeNode* root)
    {
        if(!root) return NULL;
        
        TreeNode* lef=find(root->left);
        TreeNode* righ=find(root->right);

        root->left=lef;
        root->right=righ;
        
        if(root->val==1)
        {
            return root;
        }else{
            if(lef or righ) return root;
            else return NULL;
        }
        
    }
    
    
    TreeNode* pruneTree(TreeNode* root) {
        return find(root);    
    }
};