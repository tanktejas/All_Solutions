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
    TreeNode* tmp;
    int lim;
    
    pair<TreeNode*,int> find(TreeNode* root,int sum)
    {
          if(!root){
              return {NULL,INT_MIN};
          }
         
          if(root->left == NULL and root->right == NULL)
          {
              sum+=(root->val);
              
              if(sum  < lim)
              { 
                  return {NULL,sum};
              }else{
                  return {root,sum};
              }
          }
        
          pair<TreeNode*,int> lef=find(root->left,sum+root->val);
          pair<TreeNode*,int> righ=find(root->right,sum+root->val);
         
          if(lef.first == NULL)
          {
              root->left=NULL;
          }
          if(righ.first == NULL)
          {
              root->right=NULL;
          }
        
          int cmax=max(lef.second,righ.second);
        
         if(cmax < lim)
         {
             return {NULL,cmax};
         }else{
             return {root,cmax};
         }
         
    }
    
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
             lim=limit;
             pair<TreeNode*,int> p= find(root,0);
        
            return p.first;
    }
};