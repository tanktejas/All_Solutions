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
class no{
    public:
     
     long long mx;
     long long mn;
    
     no()
     {
         
     }
    
     no(long long a,long long b){
         mx=a;
         mn=b;
     }
};
class Solution {
public:
    bool bo=1;
    no* is(TreeNode* root)
    { 
         if(!root){
             return new no(-1e17,1e17);
         }
        
         if(root->left==NULL and root->right==NULL)
         {
             return new no(root->val,root->val);
         }
         
         no* lef=is(root->left);
         no* rig=is(root->right);
        
         long long leftmax=lef->mx;
         long long rightmin=rig->mn;
        
         if(root->val <= leftmax or root->val >= rightmin) bo=0;
        
        long long mmmx=root->val;
        if(lef->mx>mmmx) mmmx=lef->mx;
        if(rig->mx>mmmx) mmmx=rig->mx;
        
        long long mmmn=root->val;
        if(lef->mn<mmmn) mmmn=lef->mn;
        if(rig->mn<mmmn) mmmn=rig->mn;
        
        return new no({mmmx,mmmn});
         
    }
    
    bool isValidBST(TreeNode* root) {
          is(root);
        
         return bo;
        
    }
};