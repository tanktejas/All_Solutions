/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    
    TreeNode* find(TreeNode* root,TreeNode* p,TreeNode* q){
        if(!root) return 0;
        
        if(root == q or root == p){
            return root; 
        }
       
       TreeNode* l=find(root->left,p,q);
       TreeNode* r=find(root->right,p,q);
       
        if(l and r){
            return root;
        }
        
      if(l or r){
          return l ? l : r;
      }
      
        return NULL;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return  find(root,p,q); 
    }
};