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
    int mxdep=0;
    TreeNode* ans=NULL;
    int howmany=0;
    
    void finddist(TreeNode* root,int cd)
    {  
        if(cd>mxdep){
            mxdep=cd; 
            howmany=1;
        }else if(cd==mxdep){
            howmany++;
        }
        
        if(!root) return ;
        
        finddist(root->left,cd+1);
        finddist(root->right,cd+1);
        
    }
    
  
    
    int collect(TreeNode* root,int cd)
    {
        if(!root)
        {
            if(cd==mxdep){
                return 1;
            }
            return 0;
        }
        
        int left=collect(root->left,cd+1);
        int right=collect(root->right,cd+1);
        
        if((left + right)==(howmany)){
            if(ans==NULL)
                ans=root; 
        } 
        
        return left+right;
        
    }
    
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        finddist(root,0);   
        collect(root,0);
        
        return ans;
        
    }
};