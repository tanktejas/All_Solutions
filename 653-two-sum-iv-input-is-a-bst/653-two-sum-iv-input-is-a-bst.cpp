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
    unordered_map<int,int>m;
    int tar;
    
    int find(TreeNode* root)
    {
        if(!root)
        {
            return 0;
        }
        
        if(m[tar - root->val]){
            return 1;
        }
        
         m[root->val]=1;
        return find(root->left) || find(root->right);
        
    }
    
    bool findTarget(TreeNode* root, int k) {
        tar=k;
        return find(root);
    }
};