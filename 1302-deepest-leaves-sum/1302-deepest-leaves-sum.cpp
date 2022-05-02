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
    void dolevel(TreeNode* root,int &sum,int curr,int &maxh){
         if(!root) return ;
        
         if(curr==maxh){
             sum+=root->val;
         }
         else if(curr > maxh){
             sum=0;
             sum=root->val;
             maxh=curr;
         }
        
        dolevel(root->left,sum,curr+1,maxh);
        dolevel(root->right,sum,curr+1,maxh);
        
    }
    int deepestLeavesSum(TreeNode* root) {
        int currmaxhight=0;
        int sum=root->val;
        int currh=0;
         dolevel(root,sum,currh,currmaxhight);
        
        return sum;
    }
};