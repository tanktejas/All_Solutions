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
    int depth=0;
    void find(TreeNode* root,int curr,int &maxd){
        if(!root) return ;
        if(root->left==NULL and root->right==NULL){
            if(curr == maxd){
                depth+=root->val;
            }else if(curr > maxd){
                depth=root->val;
                maxd=curr;
            }
        } 
        
        find(root->left,curr+1,maxd);
        find(root->right,curr+1,maxd);
    }
    
    int deepestLeavesSum(TreeNode* root){
       int currde=0;
       int maxd=INT_MIN;
        find(root,currde,maxd);
        return depth;
    }
};